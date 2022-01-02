// Название: CurrencyMachine
// Функционал: Реализует машину снятия денег (банкомат) путем применения Greedy (жадного) алгоритма.
// Используемый подход: Instructions

#include <stdio.h>
#include <math.h>
#include <iostream>

// Используемые парадигмы программирования:
// -- Просто инструкция -- .

// TODO:
// 1. Фабрика с добавлением и поиском нужного адреса среди сохраненных адрессов.
// 2. Сортировка обменных купюр.

const char deposit_holder = '0011002200330044';
const int deposited_amount = 1000;

void withdraw_moneys(int amount)
{
    int new_amount = deposited_amount - amount;
    printf("Средства %d выведены с адреса %d", deposited_amount, deposit_holder);
}

void put_moneys(int amount)
{
    int new_amount = deposited_amount + amount;
    printf("Сумма депозита %d занесена на адрес %d", deposited_amount, deposit_holder);
}

int *receive_denoms(int nominals)
{
    int x;
    int *denominations = new int(nominals);

    for (x = 0; x < nominals; x++)
    {
        std::cout << "Обменная купюра #" << (x + 1) << ":\n";
        std::cin >> denominations[x];
    }

    return denominations;
}

void *change_currency()
{
    std::cout << "Введите сумму для обмена:\n";
    size_t amount_to_change;
    std::cin >> amount_to_change;

    std::cout << "Введите номера обменных купюр:\n";
    size_t nominals;
    std::cin >> nominals;

    if (amount_to_change == 0)
    {
        return NULL;
    }
    else
    {
        int x;
        int *denominations = receive_denoms(nominals);

        for (x = 0; x < nominals; x++)
        {
            int numCoins = amount_to_change / denominations[x];
            amount_to_change %= denominations[x];
            if (numCoins > 0)
                std::cout << "Результат обмена: \n";
            std::cout << numCoins << " x " << denominations[x] << '\n';
        }
    }
}

int main(int c, char *v[])
{
    withdraw_moneys(100);

    printf("\n");

    change_currency();

    return 0;
}
