/* Write a program that supports and stores multiple currencies. Follow these steps:


1. We want to create an Account class that stores the account balance in different currencies.


2. A Currency is a class that represents a certain value in a specific currency.
It has a public field called value and a template function called to()
that takes the argument as a Currency type and returns an instance of that currency
with the value set to the appropriate conversion of the current value of the class:

    struct Currency
    {
        static const int conversionRate = CurrencyConversion;
        int d_value;
        Currency(int value): d_value(value) {}
    };

    template<typename OtherCurrency, typename SourceCurrency>
    OtherCurrency to(const SourceCurrency& source) {
        float baseValue = source.d_value / float(source.conversionRate);
        int otherCurrencyValue = int(baseValue *
        OtherCurrency::conversionRate);
        return OtherCurrency(otherCurrencyValue);
    }

    using USD = Currency<100>;
    using EUR = Currency<87>;
    using GBP = Currency<78>;

    template<typename Currency>
    class UserAccount
    {
        public:
            Currency balance;
    };


3. Our aim is to write an Account class that stores the current balance in any currency provided by the template parameter.


4. The user account must provide a method called addToBalance that accepts any kind of currency,
and after converting it to the correct currency that's used for the account,
it should sum the value to the balance:

       template<typename OtherCurrency>
         void addToBalance(OtherCurrency& other) {
           balance.value += to<Currency>(other).value;
         }


5. The user now understands how to write class templates, how to instantiate them, and how to call their templates.*/
#include <iostream>
#include "account.cpp"

using USD = Currency<100>;
using EUR = Currency<87>;
using GBP = Currency<78>;

int main()
{
    Account<USD> usd_account(1000);
    std::cout << "USD account value: " << usd_account.getBalance() << " usd" << std::endl;
    EUR eur(100);
    usd_account.addToBalance(eur);
    std::cout << "Added 100 eur to the account" << std::endl;
    std::cout << "USD account value: " << usd_account.getBalance() << " usd" << std::endl;

    Account<GBP> gbp_account(1000);
    std::cout << "GBP account value: " << gbp_account.getBalance() << " gbp" << std::endl;
    gbp_account.addToBalance(eur);
    std::cout << "Added 100 eur to the account" << std::endl;
    std::cout << "GBP account value: " << gbp_account.getBalance() << " gbp" << std::endl;

    return 0;
}