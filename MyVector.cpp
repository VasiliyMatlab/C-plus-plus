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
MyVector::MyVector(int n): sz(n), data(new uint8_t[n]) {
    for (int i = 0; i < n; i++)
        this->data[i] = 0;
}

/**
 * @brief Копирующий конструктор класса MyVector
 * 
 * @param[in] cls Ссылка на экземпляр класса, откуда происходит копирование
 */
MyVector::MyVector(const MyVector &cls): sz(cls.sz), data(new uint8_t[cls.sz]) {
    for (int i = 0; i < this->sz; i++)
        this->data[i] = cls.data[i];
}

/**
 * @brief Перемещающий конструктор класса MyVector
 * 
 * @param[in,out] cls Ссылка на rvalue
 */
MyVector::MyVector(MyVector &&cls): sz(cls.sz), data(cls.data) {
    cls.sz   = 0;
    cls.data = nullptr;
}

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
int MyVector::size(void) const {
    return this->sz;
}

/**
 * @brief Оператор копирующего присваивания
 * 
 * @param[in] cls Ссылка на экземпляр класса, из которого
 * происходит копирование
 * @return Ссылка на экземпляр класса, в который происходило
 * копирование
 */
MyVector &MyVector::operator=(const MyVector &cls) {
    uint8_t *ptr = new uint8_t[cls.sz];
    for (int i = 0; i < cls.sz; i++)
        ptr[i] = cls.data[i];
    delete [] this->data;
    this->data = ptr;
    this->sz   = cls.sz;
    return *this;
}

/**
 * @brief Оператор перемещающего присваивания
 * 
 * @param[in,out] cls Ссылка на rvalue
 * @return Ссылка на экземпляр класса, в который происходило
 * перемещение содержимого
 */
MyVector &MyVector::operator=(MyVector &&cls) {
    this->sz   = cls.sz;
    this->data = cls.data;
    cls.sz   = 0;
    cls.data = nullptr;
    return *this;
}

/**
 * @brief Перегрузка взятия значения из вектора по индексу
 * 
 * @param[in] i Индекс возвращаемого элемента
 * @return Ссылка на индексируемый элемент
 */
uint8_t &MyVector::operator[](int i) {
    if ((i < 0) || (i >= this->sz))
        throw std::out_of_range("MyVector::operator[]");

    return this->data[i];
}

/**
 * @brief Перегрузка чтения значения вектора по индексу
 * 
 * @param[in] i Индекс читаемого элемента
 * @return Ссылка на константный индексируемый элемент
 */
const uint8_t &MyVector::operator[](int i) const {
    if ((i < 0) || (i >= this->sz))
        throw std::out_of_range("MyVector::operator[]");

    return this->data[i];
}

/**
 * @brief Перегрузка вставки в текстовый поток
 * 
 * @param[in] out Ссылка на входящий текстовый поток
 * @param[in] cls Ссылка на экземпляр класса
 * @return Ссылка на исходящий текстовый поток
 */
std::ostream &operator<<(std::ostream &out, const MyVector &cls) {
    out << "Size: " << cls.sz << std::endl;
    out << "Data: ";
    for (const auto &x: cls)
        out << "0x" << std::hex << unsigned(x) << " ";
    return out << std::endl;
}

/**
 * @brief Итератор класса MyVector (начальный)
 * 
 * @param[in] cls Ссылка на экземпляр класса
 * @return Итерируемое значение
 */
uint8_t *MyVector::begin(void) const {
    return &this->data[0];
}

/**
 * @brief Итератор класса MyVector (конечный)
 * 
 * @param[in] cls Ссылка на экземпляр класса
 * @return Итерируемое значение
 */
uint8_t *MyVector::end(void) const {
    return &this->data[this->sz];
}

/**
 * @brief Перегрузка операции сложения
 * 
 * @param[in] left Левый вектор
 * @param[in] right Правый вектор
 * @return Результирующий вектор
 */
MyVector operator+(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator+(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] + right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка операции вычитания
 * 
 * @param[in] left Левый вектор
 * @param[in] right Правый вектор
 * @return Результирующий вектор
 */
MyVector operator-(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator+(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] - right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка операции умножения
 * 
 * @param[in] left Левый вектор
 * @param[in] right Правый вектор
 * @return Результирующий вектор
 */
MyVector operator*(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator+(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] * right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка операции деления
 * 
 * @param[in] left Левый вектор
 * @param[in] right Правый вектор
 * @return Результирующий вектор
 */
MyVector operator/(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator+(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] / right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка операции взятия остатка от деления
 * 
 * @param[in] left Левый вектор
 * @param[in] right Правый вектор
 * @return Результирующий вектор
 */
MyVector operator%(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator+(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] % right[i];

    return std::move(res);
}
