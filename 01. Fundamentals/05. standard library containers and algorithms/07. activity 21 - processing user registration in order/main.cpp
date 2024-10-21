#include <iostream>
#include <stack>
// #include <queue>
#include "registration.h"

// my solution
/* void processRegistration(RegistrationForm form)
{
    std::cout << "Processing form of user: "
    << form.userName << std::endl;
}

void storeRegistrationForm(std::stack<RegistrationForm>& stack,
    RegistrationForm form)
{
    processRegistration(form);
    stack.push(form);
}

void endOfDayRegistrationProcessing(std::stack<RegistrationForm>& stack)
{
    std::queue<RegistrationForm> queue;
    RegistrationForm form;
    auto size = stack.size();

    std::cout << "\nEnd of day registration:\n";

    for(auto i = 0; i < size; i++) {
        form = stack.top();
        queue.push(form);
        stack.pop();
    }

    for(auto i = 0; i < size; i++) {
        std::cout << queue.front().userName << "\n";
        queue.pop();
    }
    std::cout << std::endl;
}

int main()
{
    static std::stack<RegistrationForm> stack;

    RegistrationForm form1 = { "Anthony" };
    RegistrationForm form2 = { "Johanna" };
    RegistrationForm form3 = { "Marcus" };

    storeRegistrationForm(stack, form1);
    storeRegistrationForm(stack, form2);
    storeRegistrationForm(stack, form3);

    endOfDayRegistrationProcessing(stack);

    return 0;
} */


//book's solution
void processRegistration(RegistrationForm form)
{
    std::cout << "Processing form of user: "
    << form.userName << std::endl;
}

void storeRegistrationForm(std::stack<RegistrationForm>& stack,
    RegistrationForm form)
{
    stack.push(form);
    std::cout << "Pushed form for user " << form.userName << std::endl;
}

void endOfDayRegistrationProcessing(std::stack<RegistrationForm>& stack)
{
    while(not stack.empty()) {
        processRegistration(stack.top());
        stack.pop();
    }
}

int main()
{
    std::stack<RegistrationForm> registrationForms;

    storeRegistrationForm(registrationForms, RegistrationForm { "Alice" });
    storeRegistrationForm(registrationForms, RegistrationForm { "Bob" });
    storeRegistrationForm(registrationForms, RegistrationForm { "Charlie" });

    endOfDayRegistrationProcessing(registrationForms);

    return 0;
}