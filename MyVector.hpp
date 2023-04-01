#ifndef __MY_VECTOR_HPP__
#define __MY_VECTOR_HPP__


/**
 * @brief Класс пользовательского вектора
 * 
 */
class MyVector {
private:
    int sz;         ///< Размер вектора
    uint8_t *data;  ///< Данные векторы
public:
    MyVector(void);
    explicit MyVector(int n);
    MyVector(const MyVector &cls);
    MyVector(MyVector &&cls);
    ~MyVector(void);

    int size(void) const;

    MyVector &operator=(const MyVector &cls);
    MyVector &operator=(MyVector &&cls);
    uint8_t &operator[](int i);
    const uint8_t &operator[](int i) const;
    friend std::ostream &operator<<(std::ostream &out, const MyVector &cls);
    
    uint8_t *begin(void) const;
    uint8_t *end(void) const;
};

MyVector operator+(const MyVector &left, const MyVector &right);
MyVector operator-(const MyVector &left, const MyVector &right);
MyVector operator*(const MyVector &left, const MyVector &right);
MyVector operator/(const MyVector &left, const MyVector &right);
MyVector operator%(const MyVector &left, const MyVector &right);


#endif /* __MY_VECTOR_HPP__ */
