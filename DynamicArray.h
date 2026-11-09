#pragma once
#include <iostream>

class DynamicArray {
private:
    int* arr;
    size_t size;
public:
    DynamicArray(size_t n);
    ~DynamicArray();

    DynamicArray(const DynamicArray& arr);

    void print() const;
    void setter(size_t index, int value);
    int getter(size_t index) const;

    void append(int value);
    void summ(const DynamicArray& arr);
    void subtract(const DynamicArray& arr);
};
