#include "DynamicArray.h"
#include <windows.h>
#include <stdexcept>

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

    // ~~~Тестирование
    std::cout << "ТЕСТИРОВАНИЕ ИСКЛЮЧЕНИЙ\n";

    std::cout << "1. Тест std::invalid_argument на значение вне диапазона -100..100:\n";
    try {
        arr1.setter(0, 150); 
        std::cout << "Исключение не сработало!\n"; 
    } 
    catch (const std::invalid_argument& e) {
        std::cout << "Сработало исключение: " << e.what() << "\n";
    }


    std::cout << "\n2. Тест std::out_of_range на индекс за границами массива:\n";
    try {
        int val = arr1.getter(1000); 
        std::cout << "Исключение не сработало!\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Сработало исключение: " << e.what() << "\n";
    }


    std::cout << "\n3. Тест std::bad_alloc на ошибку выделения памяти:\n";
    try {
        std::cout << "Попытка создать массив размером 10 триллионов элементов...\n";
        DynamicArray huge_arr(10000000000000ULL); 
        std::cout << "Исключение не сработало!\n";
    } 
    catch (const std::bad_alloc& e) {
        std::cout << "Сработало исключение: " << e.what() << "\n";
    }
    
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}