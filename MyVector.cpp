#include <iostream>

#include "MyVector.hpp"

/**
 * @brief Конструктор класса MyVector
 * 
 */
MyVector::MyVector(void): sz(0), data(nullptr) {}

/**
 * @brief Конструктор класса MyVector
 * 
 * @param[in] n Размер вектора
 */
MyVector::MyVector(size_t n): sz(n), data(new uint8_t[n]) {}

/**
 * @brief Деструктор класса MyVector
 * 
 */
MyVector::~MyVector(void) {
    this->sz = 0;
    delete [] this->data;
    this->data = nullptr;
}

/**
 * @brief Получение длины вектора
 * 
 * @return Длина вектора
 */
size_t MyVector::size(void) const {
    return this->sz;
}

/**
 * @brief Итератор класса MyVector (начальный)
 * 
 * @param[in] cls Ссылка на экземпляр класса
 * @return Итерируемое значение
 */
uint8_t *begin(const MyVector &cls) {
    return &cls.data[0];
}

/**
 * @brief Итератор класса MyVector (конечный)
 * 
 * @param[in] cls Ссылка на экземпляр класса
 * @return Итерируемое значение
 */
uint8_t *end(const MyVector &cls) {
    return &cls.data[cls.sz];
}

/**
 * @brief Перегрузка взятия значения из вектора по индексу
 * 
 * @param[in] i Индекс возвращаемого элемента
 * @return Ссылка на индексируемый элемент
 */
uint8_t &MyVector::operator[](size_t i) {
    if ((i < 0) || (i >= this->sz)) {
        throw out_of_range("MyVector::operator[]");
    }

    return this->data[i];
}

/**
 * @brief Перегрузка вставки в текстовый поток
 * 
 * @param[in] out Ссылка на входящий текстовый поток
 * @param[in] cls Ссылка на экземпляр класса
 * @return Ссылка на исходящий текстовый поток
 */
ostream &operator<<(ostream &out, const MyVector &cls) {
    out << "Size: " << cls.sz << endl;
    out << "Data: ";
    for (auto &x: cls) {
        out << "0x" << hex << unsigned(x) << " ";
    }
    return out << endl;
}
