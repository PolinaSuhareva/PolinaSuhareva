    // cout << "Вы хотите загрузить данные из файла?" << endl;
    // cout << "Введите - Да/Нет" << endl;

    // string choice_for_load; // переменная для выбора загрузить данные из файла или нет

    // cin >> choice_for_load; // ввод выбора

    // try
    // {
    //     // если пользовтель не ввел ДА/НЕТ, бросаем ошибку
    //     if (choice_for_load != "Да" or choice_for_load != "Нет") throw;
    // }
    // catch(const std::exception& e)
    // {
    //     cout << "Неверно дан ответ";
    // }

    // // если выбор ДА, загружаем из файла
    // if (choice_for_load == "Да")
    // {
    //     cout << "Происходит загрузка из файла" << endl;
    // }

    // // если выбор НЕТ, просим пользователя ввести данные
    // else this->Set();

#include <iostream>
#include "Keeper.h"
#include "Base.h"

using namespace std;

int main()
{
    Keeper keeper;

    keeper.Set();
    keeper.Set();
    keeper.Set();

    keeper.Get();
}
