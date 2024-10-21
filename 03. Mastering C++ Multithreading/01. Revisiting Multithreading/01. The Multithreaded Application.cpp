#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>

/* The thread and mutex includes are the core of our multithreaded application;
they provide the basic means for creating threads, and allow for thread-safe
interactions between them

we create two mutexes: one for the global vector and one for cout, since the
latter is not thread-safe */
// --- Globals
std::mutex values_mtx;
std::mutex cout_mtx;
std::vector<int> values;

/* Note to self: can barely understand this...

This preceding method takes a minimum and maximum value as explained earlier, which
limits the range of the random numbers this method can return. At its core, it uses a
mt19937-based generator, which employs a 32-bit Mersenne Twister algorithm with a
state size of 19937 bits. This is a common and appropriate choice for most applications.

Of note here is the use of the thread_local keyword. What this means is that even though
it is defined as a static variable, its scope will be limited to the thread using it. Every thread
will thus create its own generator instance, which is important when using the random
number API in the STL.

Revisiting Multithreading
A hash of the internal thread identifier is used as a seed for the generator. This ensures
that each thread gets a fairly unique seed for its generator instance, allowing for better
random number sequences.

Finally, we create a new uniform_int_distribution instance using the provided
minimum and maximum limits, and use it together with the generator instance to
generate the random number which we return */
int randGen(const int& min, const int& max)
{
    static thread_local std::mt19937 generator(
        std::hash<std::thread::id>() (std::this_thread::get_id()));
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

void threadFnc(int tid)
{
    /* we can see that the integer parameter being passed to the thread method is a
    thread identifier. To indicate that the thread is starting, a message
    containing the thread identifier is output. Since we're using a non-thread-safe
    method for this, we use the cout_mtx mutex instance to do this safely, ensuring
    that just one thread can write to cout at any time */
    cout_mtx.lock();
    std::cout << "Starting thread " << tid << "\n";
    cout_mtx.unlock();

    /* When we obtain the initial value set in the vector, we copy it to a local
    variable so that we can immediately release the mutex for the vector to enable
    other threads to use the vector */
    values_mtx.lock();
    int val = values[0];
    values_mtx.unlock();

    int rval = randGen(0, 10);
    val += rval;

    cout_mtx.lock();
    std::cout << "Thread " << tid << " adding " << rval << ". New value: " << val
        << ".\n";
    cout_mtx.unlock();

    values_mtx.lock();
    values.push_back(val);
    values_mtx.unlock();
}

int main()
{
    values.push_back(42);
    std::thread tr1(threadFnc, 1);
    std::thread tr2(threadFnc, 2);
    std::thread tr3(threadFnc, 3);
    std::thread tr4(threadFnc, 4);

    /* we wait for each thread to finish before we continue by calling join() on
    each thread instance */
    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();

    std::cout << "input: " << values[0] << "\nResult 1: " << values[1]
        << "\nResult 2: " << values[2] << "\nResult 3: " << values[3]
        << "\nResult 4: " << values[4];

    return 1;
}
