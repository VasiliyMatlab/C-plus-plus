#ifndef __MY_VECTOR_HPP__
#define __MY_VECTOR_HPP__

#include <cinttypes>

using namespace std;

/**
 * @brief Класс пользовательского вектора
 * 
 */
class MyVector {
private:
    size_t sz;      ///< Размер вектора
    uint8_t *data;  ///< Данные векторы
public:
    MyVector(void);
    explicit MyVector(size_t n);
    ~MyVector(void);

    size_t size(void) const;

    friend uint8_t *begin(const MyVector &cls);
    friend uint8_t *end(const MyVector &cls);
    uint8_t &operator[](size_t i);
    friend ostream &operator<<(ostream &out, const MyVector &cls);
};

#endif /* __MY_VECTOR_HPP__ */
