#include <iostream>
#include <vector>

using namespace std;

// Базовый класс Detail
class Detail
{
protected:
    Detail() { cout << "Detail created" << endl; }

public:
    virtual ~Detail() { cout << "Detail deleted" << endl; }

    virtual void info() const = 0;

    template <typename T>
    static T *create()
    {
        return new T();
    }
};

// Производный класс Assembly
class Assembly : public Detail
{
protected:
    Assembly() { cout << "Assembly created" << endl; }

public:
    ~Assembly() override { cout << "Assembly deleted" << endl; }

    void info() const override { cout << "This is an assembly." << endl; }

    friend class Detail;
};

// Производный класс Part
class Part : public Detail
{
protected:
    Part() { cout << "Part created" << endl; }

public:
    ~Part() override { cout << "Part deleted" << endl; }

    void info() const override { cout << "This is a part." << endl; }

    friend class Detail;
};

// Шаблонная функция для создания объекта и добавления его в хранилище
template <typename T>
void create_and_store(vector<Detail *> &storage)
{
    storage.push_back(Detail::create<T>());
}

int main()
{
    vector<Detail *> storage;

    // Создаем объекты типа Assembly и Part и выводим их информацию
    create_and_store<Assembly>(storage);
    create_and_store<Part>(storage);

    for (const auto &obj : storage)
    {
        obj->info();
    }

    // Цикл для освобождения памяти
    for (auto &obj : storage)
    {
        delete obj;
        obj = nullptr; // Обнуляем указатель
    }
    storage.clear(); // Очищаем вектор

    return 0;
}
