#include "currency.cpp"

template<typename Currency>
class Account
{
    public:
        Account(Currency amount) : balance(amount) { }

        template<typename OtherCurrency>
        void addToBalance(OtherCurrency& other) {
            balance.d_value += to<Currency>(other).d_value;
        }

        int getBalance() const {
            return balance.d_value;
        }

    private:
        Currency balance;
};