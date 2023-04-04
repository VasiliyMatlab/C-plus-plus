#ifndef __MY_VECTOR_HPP__
#define __MY_VECTOR_HPP__


/**
 * @brief Класс пользовательского вектора
 * 
 */
class MyVector {
private:
    int sz;         ///< Размер вектора
    double *data;   ///< Данные векторы
public:
    MyVector(void);
    explicit MyVector(int n);
    MyVector(const MyVector &cls);
    MyVector(MyVector &&cls);
    ~MyVector(void);

    int size(void) const;

    MyVector &operator=(const MyVector &cls);
    MyVector &operator=(MyVector &&cls);
    double &operator[](int i);
    const double &operator[](int i) const;
    friend std::ostream &operator<<(std::ostream &out, const MyVector &cls);

    MyVector &operator+=(const MyVector &cls);
    MyVector &operator+=(const double num);
    MyVector &operator-=(const MyVector &cls);
    MyVector &operator-=(const double num);
    MyVector &operator*=(const MyVector &cls);
    MyVector &operator*=(const double num);
    MyVector &operator/=(const MyVector &cls);
    MyVector &operator/=(const double num);
    
    double *begin(void) const;
    double *end(void) const;
};

MyVector operator+(const MyVector &left, const MyVector &right);
MyVector operator-(const MyVector &left, const MyVector &right);
MyVector operator*(const MyVector &left, const MyVector &right);
MyVector operator/(const MyVector &left, const MyVector &right);

MyVector operator+(const MyVector &cls, const double num);
MyVector operator+(const double num, const MyVector &cls);
MyVector operator-(const MyVector &cls, const double num);
MyVector operator-(const double num, const MyVector &cls);
MyVector operator*(const MyVector &cls, const double num);
MyVector operator*(const double num, const MyVector &cls);
MyVector operator/(const MyVector &cls, const double num);
MyVector operator/(const double num, const MyVector &cls);


#endif /* __MY_VECTOR_HPP__ */
