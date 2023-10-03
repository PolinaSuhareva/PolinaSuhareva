#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

// ОСНОВНОЙ КЛАСС
class Base
{
private:
    string **array_of_students; // двумерный массив для хранения данных о студентах
    string **array_of_teachers; // двумерный массив для хранения данных о учителях
    string **array_of_heads; // двумерный массив для хранения данных об административном персонале

public:
// создание конструкторов и деструктора
    Base(); // конструктор по умолчанию
    Base(int flag_to_load); // конструктор с параметром
    Base(const Base &B); // конструктор копирования
    ~Base(); // деструктор

// основные методы
    void Set(int choice); // добавить элемент
    void Get(); // получить элемент
    void Delete(int choice); // удалить элемент
    void Change(int choice); // изменить данные

};

// КЛАСС ДЛЯ СОЗДАНИЕ ДАННЫХ О СТУДЕНТЕ
class Students:public Base
{
private:
    string fname_lname_tname; // ФИО
    string group; // группа
    string name_of_major; // название специальности
    string course_of_study; // номер курса
    string average_score; // средний балл

public:
// создание конструкторов и деструктора
    Students(); // конструктор по умолчанию
    Students(string fname_lname_tname, string group, string name_of_major, string course_of_study, string average_score); // конструктор с параметром
    Students(const Students &S); // конструктор копирования
    ~Students(); // деструктор

// создание основных методов
    void Set(string fname_lname_tname, string group, string name_of_major, string course_of_study, string average_score); // добавление данных о студенте
    void Get(); // получение данных о студенте
    void Delete(int choice); // удаление данных о студенте
    void Change(int choice); // изменение данных о студенте
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
    void Set(string fname_lname_tname, string groups, string disciplines); // добавление данных о преподавателе
    void Get(); // получение данных о преподавателе
    void Delete(int choice); // удаление данных о преподавателе
    void Change(int choice); // изменение данных о преподавателе
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
    void Set(string fname_lname_tname, string post, string number_of_phone, string area_of_responsibility); // добавление данных об административном персонале
    void Get(); // получение данных об административном персонале
    void Delete(int choice); // удаление данных об административном персонале
    void Change(int choice); // изменение данных об административном персонале
};

#endif
