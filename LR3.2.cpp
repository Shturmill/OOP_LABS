#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#define NOMINMAX

using namespace std;

// Базовый класс Base
class Base
{
public:
    virtual ~Base()
    {
        cout << "Base object destroyed." << endl;
    }

    virtual void show() const
    {
        cout << "This is a Base object." << endl;
    }
};

// Производный класс Derived
class Derived : public Base
{
public:
    ~Derived() override
    {
        cout << "Derived object destroyed." << endl;
    }

    void show() const override
    {
        cout << "This is a Derived object." << endl;
    }
};

// Функция добавления объекта в хранилище
void add(vector<Base *> &storage, Base *obj)
{
    try
    {
        storage.push_back(obj); // Добавляем указатель на объект в вектор
    }
    catch (const bad_alloc &e)
    {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }
}

// Функция получения ввода от пользователя с обработкой ошибок
void clearInputBuffer()
{
    char c;
    while (cin.get(c) && c != '\n')
    {
    } // Считываем символы до конца строки
}

int getUserInput(const string &prompt)
{
    int input;
    while (true)
    {
        cout << prompt;
        if (cin >> input)
        {
            return input;
        }
        else
        {
            cout << "Invalid input, please enter a valid number." << endl;
            cin.clear();        // Сбрасываем ошибку
            clearInputBuffer(); // Очищаем буфер с помощью функции
        }
    }
}

int main()
{
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(0)));

    // Вектор для хранения объектов
    vector<Base *> storage;

    // Запрос у пользователя количества объектов для создания
    int numObjects = getUserInput("Enter the number of objects to create: ");

    // Цикл создания случайных объектов
    for (int i = 0; i < numObjects; ++i)
    {
        if (rand() % 2 == 0)
        {
            add(storage, new Base()); // Создаём объект Base с помощью new
        }
        else
        {
            add(storage, new Derived()); // Создаём объект Derived с помощью new
        }
    }

    // Отображаем информацию о каждом объекте
    for (const auto &obj : storage)
    {
        obj->show();
    }

    // Освобождаем память
    for (auto &obj : storage)
    {
        delete obj;
    }

    return 0;
}
