#include <iostream>
#include "Base.h"

using namespace std;

// Класс Students
// конструктор без параметра класса Students
Students::Students()
{
    this->fname_lname_tname = "NONE"; // ФИО
    this->group = "NONE"; // группа
    this->name_of_major = "NONE"; // специальность
    this->course_of_study = "NONE"; // курс
    this->average_score = "NONE"; // средний балл
    this->indeficator = 1;

    cout << "Вызван конструктор без параметра класса - Students" << endl;
}

// конструктор с параметром класса Students
Students::Students(string fname_lname_tname, string group, string name_of_major, string course_of_study, string average_score)
{
    this->fname_lname_tname = fname_lname_tname; // ФИО
    this->group = group; // группа
    this->name_of_major = name_of_major; // специальность
    this->course_of_study = course_of_study; // курс
    this->average_score = average_score; // средний балл
    this->indeficator = 1;

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
    this->indeficator = S.indeficator;

    cout << "Вызван конструктор копирования класса - Students" << endl;
}

// деструктор
Students::~Students()
{
    cout << "Вызван деструктор класса Students" << endl;
}

// основыне методы
// метод установки значения
void Students::Set()
{
    cout << "\n\nВведите данные о студенте:" << endl;

    cout << "Ф.И.О: ";
    cin >> this->fname_lname_tname;

    cout << "Группа: ";
    cin >> this->group;

    cout << "Специальность: ";
    cin >> this->name_of_major;

    try
    {
        cout << "Курс: ";
        cin >> this->course_of_study;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен курс" << endl;
        exit(1);
    }

    try
    {
        cout << "Средний балл: ";
        cin >> this->average_score;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен балл" << endl;
        exit(1);
    }
}

// меод получения значений
void Students::Get()
{
    cout << "\n\nИнформация о студенте:" << endl;
    cout << "Ф.И.О.: " << this->fname_lname_tname << endl;
    cout << "Группа: " << this->group << endl;
    cout << "Специальность: " << this->name_of_major << endl;
    cout << "Курс: " << this->course_of_study << endl;
    cout << "Средний балл: " << this->average_score << endl;
}

// метод изменения значений
void Students::Change()
{
    cout << "\n\nВыберете параметр для изменения:" << endl;
    cout << "1 - Ф.И.О. \n"
         << "2 - Группа \n"
         << "3 - Специальность \n"
         << "4 - Курс \n"
         << "5 - Средний балл \n" << endl;
    string choice;

    try
    {
        cin >> choice;
        if (choice != "1" or choice != "2" or choice != "3" or choice != "4" or choice != "5") throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
        exit(1);
    }
    catch (const char*mssg)
    {
        cout << "Неверный выбор" << endl;
        exit(1);
    }

    cout << "Введите новое значение" << endl;
    if (choice == "1")
    {
        cout << "Ф.И.О: ";
        cin >> this->fname_lname_tname;
    }
    else if (choice == "2")
    {
        cout << "Группа: ";
        cin >> this->group;
    }
    else if (choice == "3")
    {
        cout << "Специальность: ";
        cin >> this->name_of_major;
    }
    else if (choice == "4")
    {
        try
        {
            cout << "Курс: ";
            cin >> this->course_of_study;
        }
        catch(const std::exception& e)
        {
            cout << "Некорректно введен курс" << endl;
            exit(1);
        }
    }
    else
    {
        try
        {
            cout << "Средний балл: ";
            cin >> this->average_score;
        }
        catch(const std::exception& e)
        {
            cout << "Некорректно введен балл" << endl;
            exit(1);
        }
    }
}

// метод выгрузки данных из файла
void Students::Load(int count, string line)
{
    if (count == 0) this->fname_lname_tname = line;
    else if (count == 1) this->group = line;
    else if (count == 2) this->name_of_major = line;
    else if (count == 3) this->course_of_study = line;
    else if (count == 4) this->average_score = line;
}

// Метод загрузки в файл
string Students::Save(int count)
{
    if (count == 0) return this->fname_lname_tname;
    else if (count == 1) return this->group;
    else if (count == 2) return this->name_of_major;
    else if (count == 3) return this->course_of_study;
    else if (count == 4) return this->average_score;
}

// Класс Teacher
// конструктор без параметра класса Teacher
Teachers::Teachers()
{
    this->fname_lname_tname = "NONE"; // ФИО
    this->groups = "NONE"; // группы
    this->disciplines = "NONE"; // дисциплины
    this->indeficator = 2;

    cout << "Вызван конструктор без параметра класса - Teachers" << endl;
}

// конструктор с параметром класса Students
Teachers::Teachers(string fname_lname_tname, string groups, string disciplines)
{
    this->fname_lname_tname = fname_lname_tname; // ФИО
    this->groups = groups; // группы
    this->disciplines = disciplines; // дисциплины
    this->indeficator = 2;

    cout << "Вызван конструктор с параметром класса - Teachers" << endl;
}

// конструктор копирования класса Students
Teachers::Teachers(const Teachers &T)
{
    this->fname_lname_tname = T.fname_lname_tname; // ФИО
    this->groups = T.groups; // группы
    this->disciplines = T.disciplines; // дисциплины
    this->indeficator = T.indeficator;

    cout << "Вызван конструктор копирования класса - Teachers" << endl;
}

// деструктор
Teachers::~Teachers()
{
    cout << "Вызван деструктор класса Teachers" << endl;
}

// основыне методы
// метод установки значения
void Teachers::Set()
{
    cout << "\n\nВведите данные об учителе:" << endl;

    cout << "Ф.И.О: ";
    cin >> this->fname_lname_tname;

    cout << "Группа: ";
    cin >> this->groups;

    cout << "Дисциплины: ";
    cin >> this->disciplines;
}

// меод получения значений
void Teachers::Get()
{
    cout << "\n\nИнформация об учителе:" << endl;
    cout << "Ф.И.О.: " << this->fname_lname_tname << endl;
    cout << "Группа: " << this->groups << endl;
    cout << "Дисциплины: " << this->disciplines << endl;
}

// метод изменения значений
void Teachers::Change()
{
    cout << "\n\nВыберете параметр для изменения:" << endl;
    cout << "1 - Ф.И.О. \n"
         << "2 - Группы \n"
         << "3 - Дисциплины \n" << endl;
    string choice;

    try
    {
        cin >> choice;
        if (choice != "1" or choice != "2" or choice != "3") throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
        exit(1);
    }
    catch (const char*mssg)
    {
        cout << "Неверный выбор" << endl;
        exit(1);
    }

    cout << "Введите новое значение" << endl;
    if (choice == "1")
    {
        cout << "Ф.И.О: ";
        cin >> this->fname_lname_tname;
    }
    else if (choice == "2")
    {
        cout << "Группа: ";
        cin >> this->groups;
    }
    else
    {
        cout << "Дисциплины: ";
        cin >> this->disciplines;
    }
}

// метод выгрузки данных из файла
void Teachers::Load(int count, string line)
{
    if (count == 0) this->fname_lname_tname = line;
    else if (count == 1) this->groups = line;
    else if (count == 2) this->disciplines = line;
}

// Метод загрузки в файл
string Teachers::Save(int count)
{
    if (count == 0) return this->fname_lname_tname;
    else if (count == 1) return this->groups;
    else if (count == 2) return this->disciplines;
}

// Класс Head
// конструктор без параметра класса Head
Head::Head()
{
    this->fname_lname_tname = "NONE"; // ФИО
    this->post = "NONE"; // должность
    this->number_of_phone = "NONE"; // номер телефона
    this->area_of_responsibility = "NONE"; // область ответственности
    this->indeficator = 3;

    cout << "Вызван конструктор без параметра класса - Head" << endl;
}

// конструктор с параметром класса Head
Head::Head(string fname_lname_tname, string post, string number_of_phone, string area_of_responsibility)
{
    this->fname_lname_tname = fname_lname_tname; // ФИО
    this->post = post; // должность
    this->number_of_phone = number_of_phone; // номер телефона
    this->area_of_responsibility = area_of_responsibility; // область ответственности
    this->indeficator = 3;

    cout << "Вызван конструктор с параметром класса - Head" << endl;
}

// конструктор копирования класса Head
Head::Head(const Head &H)
{
    this->fname_lname_tname = H.fname_lname_tname; // ФИО
    this->post = H.post; // должность
    this->number_of_phone = H.number_of_phone; // номер телефона
    this->area_of_responsibility = H.area_of_responsibility; // область ответственности
    this->indeficator = H.indeficator;

    cout << "Вызван конструктор копирования класса - Head" << endl;
}

// деструктор
Head::~Head()
{
    cout << "Вызван деструктор класса Head" << endl;
}

// основыне методы
// метод установки значения
void Head::Set()
{
    cout << "\n\nВведите данные об административном персонале:" << endl;

    cout << "Ф.И.О: ";
    cin >> this->fname_lname_tname;

    cout << "Должность: ";
    cin >> this->post;

    cout << "Номер телефона: ";
    cin >> this->number_of_phone;

    cout << "Область ответственности: ";
    cin >> this->area_of_responsibility;
}

// меод получения значений
void Head::Get()
{
    cout << "\n\nИнформация об административном персонале:" << endl;
    cout << "Ф.И.О.: " << this->fname_lname_tname << endl;
    cout << "Должность: " << this->post << endl;
    cout << "Номер телефона: " << this->number_of_phone << endl;
    cout << "Область ответственности: " << this->area_of_responsibility << endl;
}

// метод изменения значений
void Head::Change()
{
    cout << "\n\nВыберете параметр для изменения:" << endl;
    cout << "1 - Ф.И.О. \n"
         << "2 - Должность \n"
         << "3 - Номер телефона \n"
         << "4 - Область ответственности \n" << endl;
    string choice;

    try
    {
        cin >> choice;
        if (choice != "1" or choice != "2" or choice != "3" or choice != "4") throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
        exit(1);
    }
    catch (const char*mssg)
    {
        cout << "Неверный выбор" << endl;
        exit(1);
    }

    cout << "Введите новое значение" << endl;
    if (choice == "1")
    {
        cout << "Ф.И.О: ";
        cin >> this->fname_lname_tname;
    }
    else if (choice == "2")
    {
        cout << "Должность: ";
        cin >> this->post;
    }
    else if (choice == "3")
    {
        cout << "Номер телефона: ";
        cin >> this->number_of_phone;
    }

    else
    {
        cout << "Область ответсвтенности: ";
        cin >> this->area_of_responsibility;
    }
}

// метод выгрузки данных из файла
void Head::Load(int count, string line)
{
    if (count == 0) this->fname_lname_tname = line;
    else if (count == 1) this->post = line;
    else if (count == 2) this->number_of_phone = line;
    else if (count == 3) this->area_of_responsibility = line;
}

// Метод загрузки в файл
string Head::Save(int count)
{
    if (count == 0) return this->fname_lname_tname;
    else if (count == 1) return this->post;
    else if (count == 2) return this->number_of_phone;
    else if (count == 3) return this->area_of_responsibility;
}

int Students::TypeID()
{
    return this->indeficator;
}

int Teachers::TypeID()
{
    return this->indeficator;
}

int Head::TypeID()
{
    return this->indeficator;
}
