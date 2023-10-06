#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Node; // класс узла

class Keeper
{
private:
    Base **array_with_element; // массив элементов
    int size; // размер массива
    int count_element; // кол-во элементов в массиве

public:
// создание конструкторов и деструктора
    Keeper(); // конструктор по умолчанию
    Keeper(int size); // конструктор с параметром
    Keeper(const Keeper &K); // конструктор копирования
    ~Keeper(); // деструктор

// основные методы
    void Load(); // загрузить данные из файла
    void Set(); // добавить элемент
    void GetAll(); // получить элемент
    void GetChoice(); // получить элемент
    void Delete(); // удалить элемент
    void Save(); // сохранить данные в файл
};

#endif
