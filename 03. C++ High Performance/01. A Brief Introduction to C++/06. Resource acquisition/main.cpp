#include <mutex>

/* Note that the destructors of all the local variables are still executed, meaning
that any resources (in this case, memory) allocated by leafs and branches will be
released. The destruction of C++ objects is predictable, meaning that we have full
control over when, and in what order, resources that we have acquired are being
released. This is further illustrated in the following example, where the mutex
variable m is always unlocked when exiting the function as the lock guard releases
it when we exit the scope, regardless of how and where we exit */

auto func(std::mutex &m, int val, bool b)
{
    auto guard = std::lock_guard<std::mutex> {
        m
    }; // The mutex is locked

    if (b) {
        // The guard automatically releases the mutex at early exit
        return;
    }

    if (val == 313) {
        // The guard automatically releases if an exception is thrown
        throw std::exception{};
    }
    // The guard automatically releases the mutex at function exit
}