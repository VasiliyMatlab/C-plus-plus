#define BOOST_TEST_MODULE MyVectorTest
#include <boost/test/included/unit_test.hpp>

#include "MyVector.hpp"

// Проверка конструктора без аргументов
BOOST_AUTO_TEST_CASE(constructor_without_arguments) {
    MyVector k;
    BOOST_REQUIRE_EQUAL(k.size(), 0);
}

// Проверка конструктора с аргументом в виде целого числа
BOOST_AUTO_TEST_CASE(constructor_with_integer) {
    MyVector k(5);
    BOOST_REQUIRE_EQUAL(k.size(), 5);
    for (int i = 0; i < k.size(); i++) {
        BOOST_CHECK_EQUAL(k[i], 0);
    }
}

// Проверка конструктора с аргументом в виде инициализирующего списка
BOOST_AUTO_TEST_CASE(constructor_with_vector) {
    std::initializer_list<double> lst = {0, -3.12, 5, 7};
    MyVector k(lst);
    BOOST_REQUIRE_EQUAL(lst.size(), k.size());
    BOOST_CHECK_EQUAL(k[0], 0);
    BOOST_CHECK_EQUAL(k[1], -3.12);
    BOOST_CHECK_EQUAL(k[2], 5);
    BOOST_CHECK_EQUAL(k[3], 7);
}

// Проверка конструктора копирования
BOOST_AUTO_TEST_CASE(copy_constructor) {
    MyVector k1(5);
    k1[0] = 1;
    k1[1] = -3;
    k1[3] = 10;
    MyVector k2(k1);
    MyVector k3 = k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
        BOOST_CHECK_EQUAL(k1[i], k3[i]);
    }
}

// Проверка перемещающего конструктора
BOOST_AUTO_TEST_CASE(moving_constructor) {
    MyVector k1 = {1, 2, 3, 4, 5};
    MyVector k2 = k1;
    MyVector k3(std::move(k1));
    BOOST_REQUIRE_EQUAL(k1.size(), 0);
    BOOST_REQUIRE_EQUAL(k3.size(), k2.size());
    for (int i = 0; i < k3.size(); i++)
        BOOST_CHECK_EQUAL(k3[i], k2[i]);
}

// Проверка деструктора класса
BOOST_AUTO_TEST_CASE(destructor) {
    MyVector k(10);
    k.~MyVector();
    BOOST_REQUIRE_EQUAL(k.size(), 0);
}
