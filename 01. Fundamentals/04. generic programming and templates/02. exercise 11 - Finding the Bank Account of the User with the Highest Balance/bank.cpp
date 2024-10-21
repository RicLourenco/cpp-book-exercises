#include <iostream>
#include <string>

struct EUBankAccount {
    std::string IBAN;
    int amount;
};

struct UKBankAccount {
    std::string sortNumber;
    std::string accountNumber;
    int amount;
};

template<typename BankAccount>
int getMaxAmount(const BankAccount& acc1, const BankAccount& acc2) {
    // all banks have an account field so we can access it safely
    if (acc1.amount > acc2.amount) {
        return acc1.amount;
    }
    return acc2.amount;
}

int main()
{
    EUBankAccount euAccount1 { "IBAN1", 1000 };
    EUBankAccount euAccount2 { "IBAN2", 2000 };
    std::cout << "The greater amount between EU accounts is " << getMaxAmount(euAccount1, euAccount2) << "\n";

    UKBankAccount ukAccount1 { "SORT1", "ACCOUNT_NUM1", 2500 };
    UKBankAccount ukAccount2 { "SORT2", "ACCOUNT_NUM2", 1500 };
    std::cout << "The greater amount between UK accounts is " << getMaxAmount(ukAccount1, ukAccount2) << std::endl;


    return 0;
}