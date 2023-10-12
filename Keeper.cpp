#include <iostream>
#include <fstream>
#include <typeinfo>
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

    for (int count = 0; count < count_element; count++)
    {
        this->array_with_element[count] = K.array_with_element[count]; // копируем каждый элемент
    }
    cout << "Вызван конструктор копирования класса - Keeper" << endl;
}

// Деструктор
Keeper::~Keeper()
{
    delete [] this->array_with_element; // удаляем память под массив

    cout << "Вызван деструктор класса - Keeper" << endl;
}

// Определение метода Set класса Keeper
void Keeper::Set()
{
    cout << "\n\nВыберете, какой элемент вы хотите добавить:" << endl;
    cout << "|=========================================|" << endl;
    cout << "|Студент---------------------1            |\n"
            "|Преподаватель---------------2            |\n"
            "|Административный персонал---3            |" << endl;
    cout << "|=========================================|\n\n" << endl;

    string choice; // переменная для выбора

    // отлавливаем невернный ввод
    try
    {
        cin >> choice; // ввод выбора

        // если выбор не лежит в диапазоне
        if (choice != "1" and choice != "2" and choice != "3") throw "Error"; // выбрасываем исключение
    }
    catch(const std::exception& e)
    {
        cout << "К сожалению, вы неверно ввели выбор (указаны некоректные символы)" << endl;
        exit(1);
    }
    catch(const char* mssg)
    {
        cout << "Вы ввели другое число или вы неверно ввели выбор (указаны некоректные символы)" << endl;
        exit(1);
    }

    // если массив переполнен
    if (this->count_element == this->size)
    {
        Base **buf_array = new Base*[size]; // создаем буферный массив для копирования объектов

        for (int count = 0; count < size; count++)
        {
            buf_array[count] = this->array_with_element[count]; // копируем элементы
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
            exit(1);
        }

        this->size = size * 2; // увеличиваем размер массива

        // копируем старые элементы
        for (int count = 0; count < count_element; count++)
        {
            this->array_with_element[count] = buf_array[count]; // копируем элементы
        }
    }

    // если выбрали добавить студента
    if (choice == "1")
    {
        Base *ptr_student = new Students(); // создаем объект - студент
        ptr_student->Set(); // устанавливаем значения

        this->array_with_element[count_element++] = ptr_student; // добавляем в массив
    }

    // если выбрали добавить преподавателя
    else if (choice == "2")
    {
        Base *ptr_teacher = new Teachers(); // создаем объект - учитель
        ptr_teacher->Set(); // устанавливае значения

        this->array_with_element[count_element++] = ptr_teacher; // добавляем в массив
    }
    // если выбрали добавить административный персонал
    else
    {
        Base *ptr_head = new Head(); // создаем объект - административный персонал
        ptr_head->Set(); // устанавливаем значения

        this->array_with_element[count_element++] = ptr_head; // добавляем в массив
    }

}

// метод изменения данных
void Keeper::Change()
{
    cout << "Введите номер, данные которого вы хотите изменить: ";
    string id;
    try
    {
        cin >> id;
        for (int i = 0; i < id.length(); i++)
       {
            if ((id[i] >= 'A' and id[i] <= 'Z') or (id[i] >= 'a' and id[i] <= 'z')) throw "Error";
       }
        if (stoi(id) > count_element or stoi(id) < 0) throw "Error";
        if (count_element == 0 and stoi(id) == 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
        exit(1);
    }

    array_with_element[stoi(id)]->Change();
}

// Определение метода Get класса Keeper
void Keeper::GetAll()
{
    // выводим весь массив
    cout << "\nВся информация:" << endl;
    for (int count = 0; count < count_element; count++)
    {
        this->array_with_element[count]->Get();
    }
    cout << "\n=========================" << endl;
}

void Keeper::GetChoice()
{
    cout << "Выберете номер, чтобы получить о нем информацию: " << endl;
    string choice; // переменная для выбора

    // ввод
    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
       {
            if ((choice[i] >= 'A' and choice[i] <= 'Z') or (choice[i] >= 'a' and choice[i] <= 'z')) throw "Error";
       }
        if (stoi(choice) < 0 or stoi(choice) > count_element-1) throw "Error";
        if (count_element == 0 and stoi(choice) == 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен номер!" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
        exit(1);
    }
    int choice_digit = stoi(choice);
    // вывод информации по выбранному объекту
    try
    {
        this->array_with_element[choice_digit]->Get();
    }
    catch(const std::exception& e)
    {
        cout << "К сожалению объекта под номером - " << choice_digit << " нет" << endl;
        exit(1);
    }
}

void Keeper::Delete()
{
    cout << "Выберете номер, чтобы удалить о нем информацию: " << endl;
    string choice; // переменная для выбора

    // ввод
    try
    {
        cin >> choice;

        for (int i = 0; i < choice.length(); i++)
        {
            if ((choice[i] >= 'A' and choice[i] <= 'Z') or (choice[i] >= 'a' and choice[i] <= 'z')) throw "Error";
        }
        if (stoi(choice) < 0 or stoi(choice) > count_element-1) throw "Error";
        if (count_element == 0 and stoi(choice) == 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректно введен номер!" << endl;
        exit(1);
    }
    catch(const char*mssg)
    {
        cout << "Некорректно введен номер!" << endl;
        exit(1);
    }

    // сдвигаем все элементы
    for (int count = stoi(choice); count < count_element-1; count++)
    {
        int buf_count = count + 1;
        array_with_element[count] = array_with_element[buf_count];
    }
    this->count_element--;
}

// Определение метода Load класса Keeper
void Keeper::LoadK()
{
    cout << "\nLOAD" << endl;

    ifstream loadS;
    ifstream loadT;
    ifstream loadH;
    loadS.open("students.txt");
    loadT.open("teacher.txt");
    loadH.open("head.txt");

    if (loadS.is_open() and loadT.is_open() and loadH.is_open())
    {
        string line; // строка, в которую будем считывать
        int count = 0; // счетчик для записи

        while (true)
        {
            if (this->count_element == this->size)
            {
                Base **buf_array = new Base*[size]; // создаем буферный массив для копирования объектов

                for (int count = 0; count < size; count++)
                {
                    buf_array[count] = this->array_with_element[count]; // копируем элементы
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
                    exit(1);
                }

                this->size = size * 2; // увеличиваем размер массива

                // копируем старые элементы
                for (int count = 0; count < count_element; count++)
                {
                    this->array_with_element[count] = buf_array[count]; // копируем элементы
                }
            }

            if (!getline(loadS, line)) break;

            Base *ptr_student = new Students(); // создаем объект - студент

            ptr_student->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_student->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_student->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_student->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_student->Load(count, line);

            count = 0;

            this->array_with_element[count_element++] = ptr_student; // добавляем в массив
        }

        count = 0; // счетчик для записи

        while (true)
        {
            if (this->count_element == this->size)
            {
                Base **buf_array = new Base*[size]; // создаем буферный массив для копирования объектов

                for (int count = 0; count < size; count++)
                {
                    buf_array[count] = this->array_with_element[count]; // копируем элементы
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
                    exit(1);
                }

                this->size = size * 2; // увеличиваем размер массива

                // копируем старые элементы
                for (int count = 0; count < count_element; count++)
                {
                    this->array_with_element[count] = buf_array[count]; // копируем элементы
                }
            }

            if (!getline(loadT, line)) break;

            Base *ptr_teacher = new Teachers(); // создаем объект - студент

            ptr_teacher->Load(count, line);
            count++;

            getline(loadT, line);
            ptr_teacher->Load(count, line);
            count++;

            getline(loadT, line);
            ptr_teacher->Load(count, line);

            count = 0;

            this->array_with_element[count_element++] = ptr_teacher; // добавляем в массив
        }

        count = 0; // счетчик для записи

        while (true)
        {
            if (this->count_element == this->size)
            {
                Base **buf_array = new Base*[size]; // создаем буферный массив для копирования объектов

                for (int count = 0; count < size; count++)
                {
                    buf_array[count] = this->array_with_element[count]; // копируем элементы
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
                    exit(1);
                }

                this->size = size * 2; // увеличиваем размер массива

                // копируем старые элементы
                for (int count = 0; count < count_element; count++)
                {
                    this->array_with_element[count] = buf_array[count]; // копируем элементы
                }
            }

            if (!getline(loadH, line)) break;

            Base *ptr_head = new Head(); // создаем объект - студент

            ptr_head->Load(count, line);
            count++;

            getline(loadH, line);
            ptr_head->Load(count, line);
            count++;

            getline(loadH, line);
            ptr_head->Load(count, line);
            count++;

            getline(loadH, line);
            ptr_head->Load(count, line);

            count = 0;

            this->array_with_element[count_element++] = ptr_head; // добавляем в массив
        }

        cout << "\nLOAD COMPLETE" << endl;
    }

    else
    {
        cout << "\nОшибка открытия файлов" << endl;
    }

    loadS.close();
    loadT.close();
    loadH.close();
}

// Определение метода Save класса Keeper
void Keeper::SaveK()
{
    cout << "\nSAVE" << endl;

    ofstream loadS;
    ofstream loadT;
    ofstream loadH;
    loadS.open("students.txt");
    loadT.open("teacher.txt");
    loadH.open("head.txt");

    int countS = 0;
    int countT = 0;
    int countH = 0;

    for (int i = 0; i < count_element; i++)
    {
        if (this->array_with_element[i]->TypeID() == 1)
        {
            loadS << this->array_with_element[i]->Save(countS) << endl;
            countS++;

            loadS << this->array_with_element[i]->Save(countS) << endl;
            countS++;

            loadS << this->array_with_element[i]->Save(countS) << endl;
            countS++;

            loadS << this->array_with_element[i]->Save(countS) << endl;
            countS++;

            loadS << this->array_with_element[i]->Save(countS) << endl;
            countS = 0;
        }

        else if (this->array_with_element[i]->TypeID() == 2)
        {
            loadT << this->array_with_element[i]->Save(countT) << endl;
            countT++;

            loadT << this->array_with_element[i]->Save(countT) << endl;
            countT++;

            loadT << this->array_with_element[i]->Save(countT) << endl;
            countT = 0;
        }

        else if (this->array_with_element[i]->TypeID() == 3)
        {
            loadH << this->array_with_element[i]->Save(countH) << endl;
            countH++;

            loadH << this->array_with_element[i]->Save(countH) << endl;
            countH++;

            loadH << this->array_with_element[i]->Save(countH) << endl;
            countH++;

            loadH << this->array_with_element[i]->Save(countH) << endl;
            countH = 0;
        }
    }

    cout << "\nSAVE COMPLETE" << endl;

    loadS.close();
    loadT.close();
    loadH.close();
}
