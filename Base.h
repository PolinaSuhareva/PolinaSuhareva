#ifndef BASE_H
#define BASE_H

#include <string>

using namespace std;

// ОСНОВНОЙ КЛАСС
class Base
{
public:
// // создание конструкторов и деструктора
//     Base(); // конструктор по умолчанию
//     Base(int size); // конструктор с параметром
//     Base(const Base &B); // конструктор копирования
//     ~Base(); // деструктор

// основные методы
    virtual void Set() = 0; // добавить элемент
    virtual void Get() = 0; // получить элемент
    virtual void Change() = 0; // изменить данные
};

// КЛАСС ДЛЯ СОЗДАНИЕ ДАННЫХ О СТУДЕНТЕ
class Students:public Base
{
private:
    string fname_lname_tname; // ФИО
    string group; // группа
    string name_of_major; // название специальности
    int course_of_study; // номер курса
    float average_score; // средний балл

public:
// создание конструкторов и деструктора
    Students(); // конструктор по умолчанию
    Students(string fname_lname_tname, string group, string name_of_major, int course_of_study, float average_score); // конструктор с параметром
    Students(const Students &S); // конструктор копирования
    ~Students(); // деструктор

// создание основных методов
    void Set() override; // добавление данных о студенте
    void Get() override; // получение данных о студенте
    void Change() override; // изменение данных о студенте
};

// КЛАСС ДЛЯ СОЗДАНИЯ ДАННЫХ О ПРЕПОДАВАТЕЛЕ
class Teachers:public Base
{
private:
    string fname_lname_tname; // ФИО
    string groups; // группа
    string disciplines; // предметы

public:
// создание конструкторов и деструктора
    Teachers(); // конструктор по умолчанию
    Teachers(string fname_lname_tname, string groups, string disciplines); // конструктор с параметром
    Teachers(const Teachers &T); // конструктор копирования
    ~Teachers(); // деструктор

// создание основных методов
    void Set() override; // добавление данных о преподавателе
    void Get() override; // получение данных о преподавателе
    void Change() override; // изменение данных о преподавателе
};

class Head:public Base
{
private:
    string fname_lname_tname; // ФИО
    string post; // должность
    string number_of_phone; // номер телефона
    string area_of_responsibility; // область ответственности

public:
// создание конструкторов и деструктора
    Head(); // конструктор по умолчанию
    Head(string fname_lname_tname, string post, string number_of_phone, string area_of_responsibility); // конструктор с параметром
    Head(const Head &S); // конструктор копирования
    ~Head(); // деструктор

// создание основных методов
    void Set() override; // добавление данных об административном персонале
    void Get() override; // получение данных об административном персонале
    void Change() override; // изменение данных об административном персонале
};

#endif
