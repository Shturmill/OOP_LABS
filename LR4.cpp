#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

// Базовый класс средство передвижения
class Vehicle
{
protected:
    string manufacturer; // Производитель
    double price;        // Стоимость

public:
    Vehicle(const string &manufacturer, double price)
        : manufacturer(manufacturer), price(price) {}

    virtual void describe() const = 0;
    virtual ~Vehicle() = default;
};

// Производный класс велосипед
class Bicycle : public Vehicle
{
public:
    Bicycle(const string &manufacturer, double price)
        : Vehicle(manufacturer, price) {}

    void describe() const override
    {
        cout << "This is a bicycle, manufacturer: " << manufacturer
             << ", price: " << price << " RUB." << endl;
    }
};

// Производный класс автомобиль
class Car : public Vehicle
{
private:
    int seatingCapacity; // Вместимость пассажиров

public:
    Car(const string &manufacturer, double price, int seatingCapacity)
        : Vehicle(manufacturer, price), seatingCapacity(seatingCapacity) {}

    void describe() const override
    {
        cout << "This is a car, manufacturer: " << manufacturer
             << ", price: " << price << " RUB, seating capacity: "
             << seatingCapacity << " people." << endl;
    }
};

// Производный класс грузовик
class Truck : public Vehicle
{
private:
    double payloadCapacity; // Грузоподъемность

public:
    Truck(const string &manufacturer, double price, double payloadCapacity)
        : Vehicle(manufacturer, price), payloadCapacity(payloadCapacity) {}

    void describe() const override
    {
        cout << "This is a truck, manufacturer: " << manufacturer
             << ", price: " << price << " RUB, payload capacity: "
             << payloadCapacity << " tons." << endl;
    }
};

// Шаблонный класс для хранения массива указателей
template <typename T>
class PointerArray
{
private:
    vector<T *> data;

public:
    void add(T *element)
    {
        if (!element)
        {
            throw invalid_argument("Cannot add a null pointer.");
        }
        data.push_back(element);
    }

    T *&operator[](size_t index)
    {
        if (index >= data.size())
        {
            throw out_of_range("Index is out of bounds.");
        }
        return data[index];
    }

    size_t size() const
    {
        return data.size();
    }

    ~PointerArray()
    {
        for (T *element : data)
        {
            delete element;
        }
    }
};

int main()
{

    // Включение проверки на утечки памяти
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    try
    {
        // Создание объектов средств
        PointerArray<Vehicle> vehicles;

        vehicles.add(new Bicycle("Cube", 40000));
        vehicles.add(new Car("Toyota", 2000000, 5));
        vehicles.add(new Truck("Volvo", 5000000, 20));

        cout << "List of vehicles:" << endl;
        for (size_t i = 0; i < vehicles.size(); ++i)
        {
            vehicles[i]->describe();
        }

        // Попытка обращения к несуществующему индексу
        try
        {
            vehicles[5]->describe();
        }
        catch (const out_of_range &e)
        {
            cerr << "Error: " << e.what() << endl;
        }

        // Проверка исключения invalid_argument
        try
        {
            vehicles.add(nullptr);
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}
