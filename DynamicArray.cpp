#include "DynamicArray.h"
#include <stdexcept>

DynamicArray::DynamicArray(size_t n) {
    size = n;
    arr = new int[size]();
}

DynamicArray::~DynamicArray() {
    delete[] arr;
}

DynamicArray::DynamicArray(const DynamicArray& arr1) { //arr1 берет обычный arr
    size = arr1.size;
    arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = arr1.arr[i];
    }
}

void DynamicArray::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << "; ";
    }
    std::cout << "\n";
}

void DynamicArray::setter(size_t i, int value) {
    if (i >= size) {
        throw std::out_of_range("Индекс за границами массива");
    }
    if (value < -100 or value > 100) {
        throw std::invalid_argument("Значение должно быть от -100 до 100");
    }
    arr[i] = value;
}

int DynamicArray::getter(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Индекс за границами массива");
    }
    return arr[index];
}

void DynamicArray::append(int value) {
    if (value < -100 or value > 100) {
        throw std::invalid_argument("Значение должно быть от -100 до 100");
    }
    int* newArr = new int[size + 1];

    for (size_t i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}

void DynamicArray::summ(const DynamicArray& arr1){
     for (size_t i = 0; i < size; ++i) {
        int valueToAdd = 0;
        if (i < arr1.size) { //проверка индекса
            valueToAdd = arr1.arr[i]; 
        }
        arr[i] += valueToAdd;
    }
}

void DynamicArray::subtract(const DynamicArray& arr1){
     for (size_t i = 0; i < size; ++i) {
        int valueToAdd = 0;
        if (i < arr1.size) { //проверка индекса
            valueToAdd = arr1.arr[i]; 
        }
        arr[i] -= valueToAdd;
    }
}
