#include "DynamicArray.h"
#include <windows.h>

DynamicArray vvodDynamicArray() {
    size_t size;
    std::cout << "введите размер массива: " << "\n";
    std::cin >> size;
    DynamicArray arr(size);
    for (size_t i = 0; i < size; ++i) {
        int value;
        std::cout << "введите значение для индекса " << i << " (от -100 до 100): " << "\n";
        std::cin >> value;
        arr.setter(i, value);
    }
    return arr;
}

int main() {
    SetConsoleOutputCP(65001);
    
    std::cout << "введите ПЕРВЫЙ массив:" << "\n";
    DynamicArray arr1 = vvodDynamicArray();
    std::cout << "первый массив: " << "\n";
    arr1.print();
    
    std::cout << "введите ВТОРОЙ массив:" << "\n";
    DynamicArray arr2 = vvodDynamicArray();
    std::cout << "второй массив: " << "\n";
    arr2.print();
    
    std::cout << "\n";
    std::cout << "КОНСТРУКТОР КОПИРОВАНИЯ" << "\n";
    DynamicArray arr3 = arr1;
    std::cout << "скопированный массив: " << "\n";
    arr3.print();
    
    std::cout << "\n";
    std::cout << "ДОБАВЛЕНИЕ ЭЛЕМЕНТА" << "\n";
    int value;
    std::cout << "введите значение для добавления в конец первого массива (от -100 до 100): " << "\n";
    std::cin >> value;
    arr1.append(value);
    std::cout << "первый массив после добавления: " << "\n";
    arr1.print();
    
    std::cout << "\n";
    std::cout << "СЛОЖЕНИЕ МАССИВОВ" << "\n";
    arr1.summ(arr2);
    std::cout << "первый массив после сложения со вторым: " << "\n";
    arr1.print();
    
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}