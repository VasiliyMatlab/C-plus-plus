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
MyVector::MyVector(int n): sz(n), data(new double[n]) {
    for (int i = 0; i < n; i++)
        this->data[i] = 0;
}

/**
 * @brief Конструктор класса MyVector
 * 
 * @param[in] lst Инициализирующий список
 */
MyVector::MyVector(const std::initializer_list<double> &lst): sz(lst.size()), data(new double[lst.size()]) {
    std::copy(lst.begin(), lst.end(), data);
}

/**
 * @brief Копирующий конструктор класса MyVector
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector, откуда происходит копирование
 */
MyVector::MyVector(const MyVector &cls): sz(cls.sz), data(new double[cls.sz]) {
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
 * @param[in] cls Ссылка на экземпляр класса MyVector, из которого
 * происходит копирование
 * @return Ссылка на экземпляр класса MyVector, в который происходило
 * копирование
 */
MyVector &MyVector::operator=(const MyVector &cls) {
    double *ptr = new double[cls.sz];
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
 * @return Ссылка на экземпляр класса MyVector, в который происходило
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
double &MyVector::operator[](int i) {
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
const double &MyVector::operator[](int i) const {
    if ((i < 0) || (i >= this->sz))
        throw std::out_of_range("MyVector::operator[]");

    return this->data[i];
}

/**
 * @brief Перегрузка оператора "+=" при сложении экземпляра класса MyVector с
 * другим экземпляром
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector, с которым происходит сложение
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator+=(const MyVector &cls) {
    if (this->sz != cls.sz)
        throw std::length_error("operator+=(const MyVector &cls)");
    
    for (int i = 0; i < this->sz; i++)
        this->data[i] += cls.data[i];
    
    return *this;
}

/**
 * @brief Перегрузка оператора "+=" при сложении экземпляра класса MyVector с
 * числом
 * 
 * @param[in] num Число, с которым происходит сложение
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator+=(const double num) {
    for (int i = 0; i < this->sz; i++)
        this->data[i] += num;
    return *this;
}

/**
 * @brief Перегрузка оператора "-=" при вычитании из экземпляра класса MyVector
 * другого экземпляра
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector, который вычитают из исходного
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator-=(const MyVector &cls) {
    if (this->sz != cls.sz)
        throw std::length_error("operator+=(const MyVector &cls)");
    
    for (int i = 0; i < this->sz; i++)
        this->data[i] -= cls.data[i];
    
    return *this;
}

/**
 * @brief Перегрузка оператора "-=" при вычитании из экземпляра класса MyVector
 * числа
 * 
 * @param[in] num Число, которое вычитают
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator-=(const double num) {
    for (int i = 0; i < this->sz; i++)
        this->data[i] -= num;
    return *this;
}

/**
 * @brief Перегрузка оператора "*=" при умножении экземпляра класса MyVector на
 * другой экземпляр
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector, на который происходит умножение
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator*=(const MyVector &cls) {
    if (this->sz != cls.sz)
        throw std::length_error("operator+=(const MyVector &cls)");
    
    for (int i = 0; i < this->sz; i++)
        this->data[i] *= cls.data[i];
    
    return *this;
}

/**
 * @brief Перегрузка оператора "*=" при умножении экземпляра класса MyVector
 * на число
 * 
 * @param[in] num Число, на которое происходит умножение
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator*=(const double num) {
    for (int i = 0; i < this->sz; i++)
        this->data[i] *= num;
    return *this;
}

/**
 * @brief Перегрузка оператора "/=" при делении экземпляра класса MyVector
 * на другой экземпляр класса MyVector
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector, на который происходит деление
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator/=(const MyVector &cls) {
    if (this->sz != cls.sz)
        throw std::length_error("operator+=(const MyVector &cls)");
    
    for (int i = 0; i < this->sz; i++)
        this->data[i] /= cls.data[i];
    
    return *this;
}

/**
 * @brief Перегрузка оператора "/=" при делении экземпляра класса MyVector
 * на число
 * 
 * @param[in] num Число, на которое происходит деление
 * @return Ссылка на экземпляр класса MyVector с результатом выполнения операции
 */
MyVector &MyVector::operator/=(const double num) {
    for (int i = 0; i < this->sz; i++)
        this->data[i] /= num;
    return *this;
}

/**
 * @brief Перегрузка операции инкремента (префикс)
 * 
 * @return Ссылка на экземпляр класса MyVector
 */
MyVector &MyVector::operator++(void) {
    for (auto &x: *this)
        x++;
    return *this;
}

/**
 * @brief Перегрузка операции инкремента (постфикс)
 * 
 * @return Экземпляр класса MyVector
 */
MyVector MyVector::operator++(int) {
    MyVector tmp(*this);
    ++(*this);
    return tmp;
}

/**
 * @brief Перегрузка операции декремента (префикс)
 * 
 * @return Ссылка на экземпляр класса MyVector
 */
MyVector &MyVector::operator--(void) {
    for (auto &x: *this)
        x--;
    return *this;
}

/**
 * @brief Перегрузка операции декремента (постфикс)
 * 
 * @return Экземпляр класса MyVector
 */
MyVector MyVector::operator--(int) {
    MyVector tmp(*this);
    --(*this);
    return tmp;
}

/**
 * @brief Перегрузка операции унарного минуса
 * 
 * @return Экземпляр класса MyVector
 */
MyVector MyVector::operator-(void) const {
    MyVector tmp(*this);
    for (auto &x: tmp)
        x = -x;
    return tmp;
}

/**
 * @brief Перегрузка операции унарного плюса
 * 
 * @return Экземпляр класса MyVector
 */
MyVector MyVector::operator+(void) const {
    MyVector tmp(*this);
    return tmp;
}

/**
 * @brief Перегрузка операции отрицания
 * 
 * @return Экземпляр класса MyVector
 */
MyVector MyVector::operator!(void) const {
    MyVector tmp(*this);
    for (int i = 0; i < tmp.size(); i++)
        tmp[i] = !tmp[i];
    return std::move(tmp);
}

/**
 * @brief Итератор класса MyVector (начальный)
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Итерируемое значение
 */
double *MyVector::begin(void) const {
    return &this->data[0];
}

/**
 * @brief Итератор класса MyVector (конечный)
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Итерируемое значение
 */
double *MyVector::end(void) const {
    return &this->data[this->sz];
}

/**
 * @brief Перегрузка вставки в выходящий поток
 * 
 * @param[in,out] out Ссылка на выходящий поток
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Ссылка на выходящий поток
 */
std::ostream &operator<<(std::ostream &out, const MyVector &cls) {
    out << "Size: " << cls.size() << std::endl;
    out << "Data: [";
    if (cls.size() == 0)
        return out << "]" << std::endl;
    for (const auto &x: cls)
        out << x << ", ";
    return out << "\b\b]" << std::endl;
}

/**
 * @brief Перегрузка чтения из входящего потока
 * 
 * @param[in,out] in Ссылка на входящий поток
 * @param[in,out] cls Ссылка на экземпляр класса MyVector
 * @return Ссылка на входящий поток
 */
std::istream &operator>>(std::istream &in, MyVector &cls) {
    if (cls.size() == 0)
        return in;
    for (auto &x: cls)
        in >> x;
    return in;
}

/**
 * @brief Перегрузка операции сложения экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
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
 * @brief Перегрузка операции вычитания экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator-(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator-(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] - right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка операции умножения экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator*(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator*(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] * right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка операции деления экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator/(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator/(const MyVector &left, const MyVector &right)");
    
    MyVector res(left.size());
    for (int i = 0; i < left.size(); i++)
        res[i] = left[i] / right[i];

    return std::move(res);
}

/**
 * @brief Перегрузка оператора сложения экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число, с которым происходит сложение
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator+(const MyVector &cls, const double num) {
    MyVector res(cls);
    for (int i = 0; i < res.size(); i++)
        res[i] += num;
    
    return std::move(res);
}

/**
 * @brief Перегрузка оператора сложения числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector,
 * с которым происходит сложение
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator+(const double num, const MyVector &cls) {
    return std::move(cls + num);
}

/**
 * @brief Перегрузка оператора вычитания числа из экземпляра класса MyVector
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число, которое вычитаем
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator-(const MyVector &cls, const double num) {
    MyVector res(cls);
    for (int i = 0; i < res.size(); i++)
        res[i] -= num;
    
    return std::move(res);
}

/**
 * @brief Перегрузка оператора вычитания экземпляра класса MyVector из числа
 * 
 * @param[in] num Число, из которого вычитаем 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator-(const double num, const MyVector &cls) {
    MyVector res(cls);
    for (int i = 0; i < res.size(); i++)
        res[i] = num - res[i];
    
    return std::move(res);
}

/**
 * @brief Перегрузка оператора умножения экземпляра класса MyVector на число
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число, на которое происходит умножение
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator*(const MyVector &cls, const double num) {
    MyVector res(cls);
    for (int i = 0; i < res.size(); i++)
        res[i] *= num;
    
    return std::move(res);
}

/**
 * @brief Перегрузка оператора умножения числа на экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator*(const double num, const MyVector &cls) {
    return std::move(cls * num);
}

/**
 * @brief Перегрузка оператора деления экземпляра класса MyVector на число
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число, на которое происходит деление
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator/(const MyVector &cls, const double num) {
    MyVector res(cls);
    for (int i = 0; i < res.size(); i++)
        res[i] /= num;
    
    return std::move(res);
}

/**
 * @brief Перегрузка оператора деления числа на экземпляр класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Экземпляр класса MyVector, который является результатом
 * вычисления выражения
 */
MyVector operator/(const double num, const MyVector &cls) {
    MyVector res(cls);
    for (int i = 0; i < res.size(); i++)
        res[i] = num / res[i];
    
    return std::move(res);
}

/**
 * @brief Перегрузка оператора проверки на равенство двух экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator==(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator==(const MyVector &left, const MyVector &right)");

    MyVector tmp(left.size());
    for (int i = 0; i < left.size(); i++)
        tmp[i] = (left[i] == right[i]);
    return std::move(tmp);
}

/**
 * @brief Перегрузка оператора проверки на неравенство двух экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator!=(const MyVector &left, const MyVector &right) {
    return std::move(!(left == right));
}

/**
 * @brief Перегрузка оператора "меньше" для двух экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator<(const MyVector &left, const MyVector &right) {
    if (left.size() != right.size())
        throw std::length_error("operator==(const MyVector &left, const MyVector &right)");

    MyVector tmp(left.size());
    for (int i = 0; i < left.size(); i++)
        tmp[i] = (left[i] < right[i]);
    return std::move(tmp);
}

/**
 * @brief Перегрузка оператора "больше" для двух экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator>(const MyVector &left, const MyVector &right) {
    return std::move(right < left);
}

/**
 * @brief Перегрузка оператора "меньше или равно" для двух экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator<=(const MyVector &left, const MyVector &right) {
    return std::move(!(right < left));
}

/**
 * @brief Перегрузка оператора "больше или равно" для двух экземпляров класса MyVector
 * 
 * @param[in] left Левый экземпляр класса MyVector
 * @param[in] right Правый экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator>=(const MyVector &left, const MyVector &right) {
    return std::move(!(left < right));
}

/**
 * @brief Перегрузка оператора проверки на равенство экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator==(const MyVector &cls, const double num) {
    MyVector tmp(cls.size());
    for (int i = 0; i < tmp.size(); i++)
        tmp[i] = (cls[i] == num);
    return std::move(tmp);
}

/**
 * @brief Перегрузка оператора проверки на равенство числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator==(const double num, const MyVector &cls) {
    return std::move(cls == num);
}

/**
 * @brief Перегрузка оператора проверки на неравенство экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator!=(const MyVector &cls, const double num) {
    return std::move(!(cls == num));
}

/**
 * @brief Перегрузка оператора проверки на неравенство числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator!=(const double num, const MyVector &cls) {
    return std::move(!(cls == num));
}

/**
 * @brief Перегрузка оператора "меньше" для экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator<(const MyVector &cls, const double num) {
    MyVector tmp(cls.size());
    for (int i = 0; i < tmp.size(); i++)
        tmp[i] = (cls[i] < num);
    return std::move(tmp);
}

/**
 * @brief Перегрузка оператора "меньше" для числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator<(const double num, const MyVector &cls) {
    return std::move(cls > num);
}

/**
 * @brief Перегрузка оператора "больше" для экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator>(const MyVector &cls, const double num) {
    MyVector tmp(cls.size());
    for (int i = 0; i < cls.size(); i++)
        tmp[i] = (cls[i] > num);
    return std::move(tmp);
}

/**
 * @brief Перегрузка оператора "больше" для числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator>(const double num, const MyVector &cls) {
    return std::move(cls < num);
}

/**
 * @brief Перегрузка оператора "меньше или равно" для экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator<=(const MyVector &cls, const double num) {
    return std::move(!(cls > num));
}

/**
 * @brief Перегрузка оператора "меньше или равно" для числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator<=(const double num, const MyVector &cls) {
    return std::move(!(cls < num));
}

/**
 * @brief Перегрузка оператора "больше или равно" для экземпляра класса MyVector и числа
 * 
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @param[in] num Число
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator>=(const MyVector &cls, const double num) {
    return std::move(!(cls < num));
}

/**
 * @brief Перегрузка оператора "больше или равно" для числа и экземпляра класса MyVector
 * 
 * @param[in] num Число
 * @param[in] cls Ссылка на экземпляр класса MyVector
 * @return Результирующий экземпляр класса MyVector
 */
MyVector operator>=(const double num, const MyVector &cls) {
    return std::move(!(cls > num));
}

