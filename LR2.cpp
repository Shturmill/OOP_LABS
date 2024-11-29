#include <iostream>
#include <string>

using namespace std;

class Publication
{
protected:
    string title; // Название книги или аудиозаписи
    float price;  // Стоимость книги или аудиозаписи

public:
    // Метод для ввода данных
    virtual void GetData()
    {
        cout << "Enter title: ";
        getline(cin, title);

        // Ввод цены с проверкой на корректность
        while (true)
        {
            cout << "Enter price: ";
            cin >> price;
            if (cin.fail() || price < 0)
            {
                cin.clear();            // Очищаем флаг ошибки потока, если ввод был некорректным
                cin.ignore(1000, '\n'); // Игнорируем оставшиеся символы в потоке до конца строки
                cout << "Invalid input. Please enter a valid price." << endl;
            }
            else
            {
                cin.ignore(1000, '\n');
                break;
            }
        }
    }

    // Метод для вывода данных
    virtual void PutData() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Sales
{
protected:
    float sales[3]; // Массив для хранения продаж за три месяца

public:
    // Метод для ввода данных о продажах
    void GetData()
    {
        cout << "Enter sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i)
        {
            while (true)
            {
                cout << "Month " << i + 1 << ": ";
                cin >> sales[i];
                if (cin.fail() || sales[i] < 0)
                {
                    cin.clear();            // Очищаем флаг ошибки потока, если ввод был некорректным
                    cin.ignore(1000, '\n'); // Игнорируем оставшиеся символы в потоке до конца строки
                    cout << "Invalid input. Please enter a valid sales amount." << endl;
                }
                else
                {
                    break;
                }
            }
        }
        cin.ignore(1000, '\n');
    }

    // Метод для вывода данных о продажах
    void PutData() const
    {
        cout << "Sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << "Month " << i + 1 << ": " << sales[i] << endl;
        }
    }

    // Метод для расчета общей суммы продаж
    float total_sales() const
    {
        float total = 0;
        for (int i = 0; i < 3; ++i)
        {
            total += sales[i];
        }
        return total;
    }
};

class Book : public Publication, public Sales
{
private:
    int pages; // Количество страниц

public:
    // Метод для ввода данных
    void GetData() override
    {
        Publication::GetData(); // Вызов метода базового класса Publication
        Sales::GetData();       // Вызов метода базового класса Sales

        // Ввод данных о количестве страниц
        while (true)
        {
            cout << "Enter number of pages: ";
            cin >> pages;
            if (cin.fail() || pages <= 0)
            {
                cin.clear();            // Очищаем флаг ошибки потока, если ввод был некорректным
                cin.ignore(1000, '\n'); // Игнорируем оставшиеся символы в потоке до конца строки
                cout << "Invalid input. Please enter a valid number of pages." << endl;
            }
            else
            {
                cin.ignore(1000, '\n');
                break;
            }
        }
    }

    // Метод для вывода данных
    void PutData() const override
    {
        Publication::PutData(); // Вызов метода базового класса Publication
        Sales::PutData();       // Вызов метода базового класса Sales
        cout << "Pages: " << pages << endl;
        cout << "Total sales: " << total_sales() << endl; // Вывод общей суммы продаж
    }
};

class Tape : public Publication, public Sales
{
private:
    float play_time; // Время записи в минутах

public:
    // Метод для ввода данных
    void GetData() override
    {
        Publication::GetData(); // Вызов метода базового класса Publication
        Sales::GetData();       // Вызов метода базового класса Sales

        // Ввод данных о времени записи
        while (true)
        {
            cout << "Enter play time (in minutes): ";
            cin >> play_time;
            if (cin.fail() || play_time <= 0)
            {
                cin.clear();            // Очищаем флаг ошибки потока, если ввод был некорректным
                cin.ignore(1000, '\n'); // Игнорируем оставшиеся символы в потоке до конца строки
                cout << "Invalid input. Please enter a valid play time." << endl;
            }
            else
            {
                cin.ignore(1000, '\n');
                break;
            }
        }
    }

    // Метод для вывода данных
    void PutData() const override
    {
        Publication::PutData(); // Вызов метода базового класса Publication
        Sales::PutData();       // Вызов метода базового класса Sales
        cout << "Play time: " << play_time << " minutes" << endl;
        cout << "Total sales: " << total_sales() << endl; // Вывод общей суммы продаж
    }
};

int main()
{
    // Ввод для книги
    cout << "Book:" << endl;
    Book myBook;
    myBook.GetData();
    myBook.PutData();

    cout << endl;

    // Ввод для аудиокниги
    cout << "Tape:" << endl;
    Tape myTape;
    myTape.GetData();
    myTape.PutData();

    return 0;
}
