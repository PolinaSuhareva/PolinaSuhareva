#include <iostream>
#include "Keeper.h"
#include "Base.h"

using namespace std;

// Конструктор без параметра
Keeper::Keeper()
{
    this->array_with_element = new Base*[1]; // выделяем память под 1 элемент
    this->size = 1; // размер = 1
    this->count_element = 0; // кол-во элементов = 0

    cout << "Вызван конструктор без параметра класса - Keeper" << endl;
}

// Конструктор с параметром
Keeper::Keeper(int size)
{
    this->array_with_element = new Base*[size]; // выделяем память под size объектов
    this->size = size; // размер = size
    this->count_element = 0; // кол-во элементов = 0

    cout << "Вызван конструктор с параметром класса - Keeper" << endl;
}

// Конструктор копирования
Keeper::Keeper(const Keeper &K)
{
   this->size = K.size; // копируем размер массива
   this->count_element = K.count_element; // кол-во элементов
   this->array_with_element = new Base*[this->size]; // выделяем память под size объектов

    for (int count = 0; count < size; count++)
    {
        this->array_with_element[count] = K.array_with_element[count]; // копируем каждый элемент
    }
    cout << "Вызван конструктор копирования класса - Keeper" << endl;
}

// Деструктор
Keeper::~Keeper()
{
    for (int count = 0; count < size; count++)
    {
        delete [] this->array_with_element[count]; // удаляем память под каждый элемент
    }

    delete [] this->array_with_element; // удаляем память под массив

    cout << "Вызван деструктор класса - Keeper" << endl;
}

// Определение метода Load класса Keeper
void Keeper::Load()
{
    cout << "LOAD" << endl;
}

// Определение метода Set класса Keeper
void Keeper::Set()
{
    cout << "Выберете, какой элемент вы хотите добавить:" << endl;
    cout << "|=========================================|" << endl;
    cout << "|Студент---------------------1            |\n"
            "|Преподаватель---------------2            |\n"
            "|Административный персонал---3            |" << endl;
    cout << "|=========================================|" << endl;

    int choice = 0; // переменная для выбора

    // отлавливаем невернный ввод
    try
    {
        cin >> choice; // ввод выбора

        // если выбор не лежит в диапазоне
        if (choice > 3 or choice < 1) throw "Error"; // выбрасываем исключение
    }
    catch(const std::exception& e)
    {
        cout << "К сожалению, вы неверно ввели выбор (указаны некоректные символы)" << endl;
    }
    catch(const char* mssg)
    {
        cout << "Вы ввели другое число" << endl;
    }

    // если массив переполнен
    if (this->count_element == this->size)
    {
        Base **buf_array = new Base*[size]; // создаем буферный массив для копирования объектов

        for (int count = 0; count < size; count++)
        {
            buf_array[count] = this->array_with_element[count]; // копируем элементы
        }

        // удаляем старую память
        for (int count = 0; count < size; count++)
        {
            delete [] this->array_with_element[count]; // удаляем память под каждый элемент
        }

        delete [] this->array_with_element; // удаляем память под массив

        // выделяем новую память под наш массив
        try
        {
            this->array_with_element = new Base*[size*2]; // выделяем доп. память
        }
        catch(const std::exception& e)
        {
            std::cerr << "Память не удалось выделить" << endl;
        }

        this->size = size * 2; // увеличиваем размер массива

        // копируем старые элементы
        for (int count = 0; count < count_element; count++)
        {
            this->array_with_element[count] = buf_array[count]; // копируем элементы
        }

        // удаляем память буферного массива
        for (int count = 0; count < count_element; count++)
        {
            delete [] buf_array[count]; // удаляем память под каждый элемент
        }

        delete [] buf_array; // удаляем память под массив

    }

    // если выбрали добавить студента
    if (choice == 1)
    {
        Base *ptr_student = new Students(); // создаем объект - студент
        ptr_student->Set(); // устанавливаем значения

        this->array_with_element[count_element++] = ptr_student; // добавляем в массив
    }

    // если выбрали добавить преподавателя
    else if (choice == 2)
    {
        Base *ptr_teacher = new Teachers(); // создаем объект - учитель
        ptr_teacher->Set(); // устанавливае значения

        this->array_with_element[count_element++] = ptr_teacher; // добавляем в массив
    }
    // если выбрали добавить административный персонал
    else
    {
        Base *ptr_head = new Teachers(); // создаем объект - административный персонал
        ptr_head->Set(); // устанавливаем значения

        this->array_with_element[count_element++] = ptr_head; // добавляем в массив
    }

}

// Определение метода Get класса Keeper
void Keeper::GetAll()
{
    // выводим весь массив
    for (int count = 0; count < count_element; count++)
    {
        this->array_with_element[count]->Get();
    }
}

void Keeper::GetChoice()
{
    cout << "Выберете номер, чтобы получить о нем информацию" << endl;
    int choice; // переменная для выбора

    // ввод
    try
    {
        cin >> choice;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен номер!" << endl;
    }

    // вывод информации по выбранному объекту
    try
    {
        this->array_with_element[choice]->Get();
    }
    catch(const std::exception& e)
    {
        cout << "К сожалению объекта под номером - " << choice << " нет" << endl;
    }
}

void Keeper::Delete()
{
    cout << "Выберете номер, чтобы удалить о нем информацию" << endl;
    int choice; // переменная для выбора

    // ввод
    try
    {
        cin >> choice;
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен номер!" << endl;
    }

    // попытка удаления
    try
    {
        delete [] array_with_element[choice];
    }
    catch(const std::exception& e)
    {
        cout << "Не удалось удалить элемент" << endl;
    }

    // сдвигаем все элементы
    for (int count = choice; count < count_element-1; count++)
    {
        int buf_count = count + 1;
        array_with_element[count] = array_with_element[buf_count];
    }
}

void Keeper::Save()
{
    cout << "SAVE" << endl;
}
