#include <iostream>
#include "Base.h"

using namespace std;

// конструктор без параметра класса Students
Students::Students()
{
    this->fname_lname_tname = "NONE"; // ФИО
    this->group = "NONE"; // группа
    this->name_of_major = "NONE"; // специальность
    this->course_of_study = 0; // курс
    this->average_score = 0; // средний балл

    cout << "Вызван конструктор без параметра класса - Students" << endl;
}

// конструктор с параметром класса Students
Students::Students(string fname_lname_tname, string group, string name_of_major, int course_of_study, float average_score)
{
    this->fname_lname_tname = fname_lname_tname; // ФИО
    this->group = group; // группа
    this->name_of_major = name_of_major; // специальность

    try
    {
        this->course_of_study = course_of_study; // курс
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен курс" << endl;
    }

    try
    {
        this->average_score = 0; // средний балл
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен балл" << endl;
    }

    cout << "Вызван конструктор с параметром класса - Students" << endl;
}

// конструктор копирования класса Students
Students::Students(const Students &S)
{
    this->fname_lname_tname = S.fname_lname_tname; // ФИО
    this->group = S.group; // группа
    this->name_of_major = S.name_of_major; // специальность
    this->course_of_study = S.course_of_study; // курс
    this->average_score = S.average_score; // средний балл

    cout << "Вызван конструктор копирования класса - Students" << endl;
}

Students::~Students()
{
    cout << "Вызван деструктор класса Students" << endl;
}

void Students::Set()
{
    cout << "Введите данные о студенте:" << endl;

    cout << "Ф.И.О:";
    cin >> this->fname_lname_tname;

    cout << "Группа:";
    cin >> this->group;

    cout << "Специальность:";
    cin >> this->name_of_major;

    try
    {
        cout << "Курс:";
        cin >> this->course_of_study;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен курс" << endl;
    }

    try
    {
        cout << "Средний балл:";
        cin >> this->average_score;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен балл" << endl;
    }
}

void Students::Get()
{
    cout << "Информация о студенте:" << endl;
    cout << "Ф.И.О: " << this->fname_lname_tname << endl;
    cout << "Группа: " << this->group << endl;
    cout << "Специальность: " << this->name_of_major << endl;
    cout << "Курс: " << this->course_of_study << endl;
    cout << "Средний балл: " << this->average_score << endl;
}

void Students::Change()
{
    cout << "Выберете параметр для изменения:" << endl;
    int choice;

    try
    {
        cin >> choice;
        if (choice > 5 or choice < 1) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
    }
    catch (const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    cout << "Введите новое значение" << endl;
    if (choice == 1)
    {
        cout << "Ф.И.О:";
        cin >> this->fname_lname_tname;
    }
    else if (choice == 2)
    {
        cout << "Группа:";
        cin >> this->group;
    }
    else if (choice == 3)
    {
        cout << "Специальность:";
        cin >> this->name_of_major;
    }
    else if (choice == 4)
    {
        try
        {
            cout << "Курс:";
            cin >> this->course_of_study;
        }
        catch(const std::exception& e)
        {
            cout << "Некорректно введен курс" << endl;
        }
    }
    else
    {
        try
        {
            cout << "Средний балл:";
            cin >> this->average_score;
        }
        catch(const std::exception& e)
        {
            cout << "Некорректно введен балл" << endl;
        }
    }
}
