// Название: CurrencyMachine
// Функционал: Реализует машину снятия денег (банкомат) путем применения Greedy (жадного) алгоритма.
// Используемый подход: OOP

#include <stdio.h>
#include <math.h>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

// Используемые парадигмы программирования:
// -- Полиморфизм -- ?.
// -- Абстракция -- .
// -- Инкапсуляция -- .
// -- Наследование -- .

// TODO:
// 1. Фабрика с добавлением и поиском нужного адреса в классе BankMachine.

class Address
{
public:
    virtual void deactivate() = 0;
};

class VisibleAddress : Address
{
public:
    char identificator;
    char email;

    void deactivate() override
    {
        printf("<-- Адресс был удален -->");
    }
};

class BankDeposit
{
public:
    VisibleAddress address;
    double amount = 0;

    void hold(double d_amount)
    {
        amount = d_amount;
        const auto timestamp = std::chrono::system_clock::now();
        printf("Депозит %d$ in %d:", amount, timestamp);
    }

    void withdraw(double w_amount)
    {
        amount -= w_amount;
        const auto timestamp = std::chrono::system_clock::now();
        printf("Вывод %d$ in %d:", amount, timestamp);
    }
};

class BankMachine
{
private:
    int initial_capitalization = 1000000;

public:
    BankDeposit single_account_deposit = BankDeposit();

    void init()
    {
        printf("<-- Bank (currency) Machine -->");
        printf("\n \n");

        single_account_deposit.hold(100);
    }

    void withdraw(double amount)
    {
        const auto timestamp = std::chrono::system_clock::now();
        single_account_deposit.withdraw(amount);
    }
};

class CurrencyMachine : BankMachine
{
public:
    void init()
    {
        this->init();
    }

    void *change_currency(int amount)
    {
        std::cout << "Введите номера обменных купюр:\n";
        size_t nominals;
        std::cin >> nominals;

        if (amount == 0)
        {
            return NULL;
        }
        else
        {
            std::vector<int> denominations(nominals);

            for (size_t i = 0; i < nominals; ++i)
            {
                std::cout << "Обменная купюра #" << (i + 1) << ":\n";
                std::cin >> denominations[i];
            }

            std::sort(denominations.begin(), denominations.end(),
                      [](int lhs, int rhs)
                      { return lhs > rhs; });

            if (denominations.back() != 1)
                denominations.push_back(1);

            for (int coin : denominations)
            {
                int numCoins = amount / coin;
                amount %= coin;
                std::cout << "Результат обмена: \n";

                if (numCoins > 0)
                    std::cout << numCoins << " x " << coin << '\n';
            }
        }
    }
};

int main(int c, char *v[])
{
    int amount_to_withdraw = 150;

    CurrencyMachine machine;

    machine.init();

    machine.change_currency(amount_to_withdraw);
}
