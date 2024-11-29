#include <iostream>
using namespace std;

int main()
{
    int size = 10;
    short *arr = new short[size]; // задание динамического массива

    // заполнение массива
    cout << "Enter 10 short integers:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    // выводим в консоль полученный массив
    cout << "Array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // отображаем адрес первого элемента массива
    cout << "Address of the array's first element: " << static_cast<void *>(arr) << endl;

    // вычисляем и отображаем расстояние от первого элемента массива
    cout << "Distance of each element from beginning of the array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "arr[" << i << "]" << "is at address : " << static_cast<void *>(&arr[i]) << " distance from beginning is : "
             << i * sizeof(arr[i]) << " Bytes" << endl;
    }

    delete[] arr; // удаляем динамически выделенную память массива

    return 0;
}
