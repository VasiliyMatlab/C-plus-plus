#define BOOST_TEST_MODULE MyVectorTest
#include <boost/test/included/unit_test.hpp>

#include <iomanip>
#include <iostream>

#include "MyVector.hpp"

// Проверка конструктора без аргументов
BOOST_AUTO_TEST_CASE(constructor_without_arguments) {
    MyVector k;
    BOOST_REQUIRE_EQUAL(k.size(), 0);
}

// Проверка конструктора аргументом в виде целого числа
BOOST_AUTO_TEST_CASE(constructor_with_integer) {
    MyVector k(5);
    BOOST_REQUIRE_EQUAL(k.size(), 5);
    for (int i = 0; i < k.size(); i++) {
        if (k[i] != 0)
            BOOST_ERROR("k[" << i << "] != 0");
    }
}

// Проверка конструктора копирования
BOOST_AUTO_TEST_CASE(copy_constructor) {
    MyVector k1(5);
    k1[0] = 1;
    k1[1] = -3.2;
    k1[3] = 10;
    MyVector k2(k1);
    MyVector k3 = k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        if (k1[i] != k2[i]) {
            BOOST_ERROR("k1[" << i << "] != k2[" << i << "]" << " (" << std::setw(2) << std::setprecision(2) << k1[i] << " != " << std::setw(2) << k2[i] << ")");
        }
        if (k1[i] != k3[i]) {
            BOOST_ERROR("k1[" << i << "] != k3[" << i << "]" << " (" << std::setw(2) << std::setprecision(2) << k1[i] << " != " << std::setw(2) << k3[i] << ")");
        }
    }
}
