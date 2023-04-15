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

// Проверка оператора копирующего присваивания
BOOST_AUTO_TEST_CASE(copying_assignment) {
    MyVector k1 = {-10, 11, 7, -2.7, 4};
    MyVector k2;
    k2 = k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
}

// Проверка оператора перемещающего присваивания
BOOST_AUTO_TEST_CASE(moving_assignment) {
    MyVector k1 = {-23.1, 0.9923, 3, -17};
    MyVector k2 = k1;
    MyVector k3;
    k3 = std::move(k1);
    BOOST_REQUIRE_EQUAL(k1.size(), 0);
    BOOST_REQUIRE_EQUAL(k2.size(), k3.size());
    for (int i = 0; i < k2.size(); i++)
        BOOST_CHECK_EQUAL(k3[i], k2[i]);
}

// Проверка операторов begin и end
BOOST_AUTO_TEST_CASE(begin_end) {
    MyVector k1 = {0.4, 3, -2, 1};
    MyVector k2 = k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    int i = 0;
    for (auto x = std::begin(k1); x != std::end(k1); ++x, i++)
        BOOST_CHECK_EQUAL(*x, k2[i]);
    i = 0;
    for (auto &x: k1) {
        BOOST_CHECK_EQUAL(x, k2[i]);
        i++;
    }
}

// Проверка оператора унарного плюса
BOOST_AUTO_TEST_CASE(unary_add) {
    MyVector k1 = {1, -2, 3, -4};
    MyVector k2 = +k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
    k2[0] = 2;
    k2[1] = 3;
    k2[2] = -4;
    k2[3] = -5;
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_NE(k1[i], k2[i]);
}

// Проверка оператора унарного минуса
BOOST_AUTO_TEST_CASE(unary_sub) {
    MyVector k1 = {1, -2, 3, -4};
    MyVector k2 = -k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i], -k2[i]);
}

// Проверка оператора инкремента (префикс)
BOOST_AUTO_TEST_CASE(inc_prefix) {
    MyVector k1 = {0, 1, 2, 3, 4};
    MyVector k2 = ++k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], i + 1);
        BOOST_CHECK_EQUAL(k2[i], i + 1);
    }
}

// Проверка оператора инкремента (постфикс)
BOOST_AUTO_TEST_CASE(inc_postfix) {
    MyVector k1 = {0, 1, 2, 3, 4};
    MyVector k2 = k1++;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i], k2[i] + 1);
}

// Проверка оператора декремента (префикс)
BOOST_AUTO_TEST_CASE(dec_prefix) {
    MyVector k1 = {0, 1, 2, 3, 4};
    MyVector k2 = --k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], i - 1);
        BOOST_CHECK_EQUAL(k2[i], i - 1);
    }
}

// Проверка оператора декремента (постфикс)
BOOST_AUTO_TEST_CASE(dec_postfix) {
    MyVector k1 = {0, 1, 2, 3, 4};
    MyVector k2 = k1--;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i], k2[i] - 1);
}

// Проверка оператора += MyVector
BOOST_AUTO_TEST_CASE(operation_add_equally_MyVector) {
    MyVector k1 = {0, 1, 2, 3, 4};
    MyVector k2 = {1, 2, 3, 4, 5};
    MyVector k3 = k2;
    k2 += k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], i);
        BOOST_CHECK_EQUAL(k2[i] - k1[i], k3[i]);
    }

    MyVector k4 = {4, 5, 6};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 += k4, std::length_error);
}

// Проверка оператора -= MyVector
BOOST_AUTO_TEST_CASE(operation_sub_equally_MyVector) {
    MyVector k1 = {0, 1, 2, 3, 4};
    MyVector k2 = {1, 2, 3, 4, 5};
    MyVector k3 = k2;
    k2 -= k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], i);
        BOOST_CHECK_EQUAL(k2[i] + k1[i], k3[i]);
    }

    MyVector k4 = {4, 5, 6};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 -= k4, std::length_error);
}

// Проверка оператора *= MyVector
BOOST_AUTO_TEST_CASE(operation_mul_equally_MyVector) {
    MyVector k1 = {1, 2, 3, 4, 5};
    MyVector k2 = {2, 3, 4, 5, 6};
    MyVector k3 = k2;
    k2 *= k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], i + 1);
        BOOST_CHECK_EQUAL(k2[i] / k1[i], k3[i]);
    }

    MyVector k4 = {4, 5, 6};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 *= k4, std::length_error);
}

// Проверка оператора /= MyVector
BOOST_AUTO_TEST_CASE(operation_div_equally_MyVector) {
    MyVector k1 = {1, 2, 3, 4, 5};
    MyVector k2 = {2, 3, 4, 5, 6};
    MyVector k3 = k2;
    k2 /= k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], i + 1);
        BOOST_CHECK_EQUAL(k2[i] * k1[i], k3[i]);
    }

    MyVector k4 = {4, 5, 6};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 /= k4, std::length_error);
}

// Проверка оператора += double
BOOST_AUTO_TEST_CASE(operation_add_equally_double) {
    MyVector k1 = {10, 20, 30, 40, 50};
    MyVector k2 = k1;
    double num  = 3.2;
    k1 += num;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k2[i] + num, k1[i]);
}

// Проверка оператора -= double
BOOST_AUTO_TEST_CASE(operation_sub_equally_double) {
    MyVector k1 = {10, 20, 30, 40, 50};
    MyVector k2 = k1;
    double num  = 3.2;
    k1 -= num;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k2[i] - num, k1[i]);
}

// Проверка оператора *= double
BOOST_AUTO_TEST_CASE(operation_mul_equally_double) {
    MyVector k1 = {10, 20, 30, 40, 50};
    MyVector k2 = k1;
    double num  = 3.2;
    k1 *= num;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k2[i] * num, k1[i]);
}

// Проверка оператора /= double
BOOST_AUTO_TEST_CASE(operation_div_equally_double) {
    MyVector k1 = {10, 20, 30, 40, 50};
    MyVector k2 = k1;
    double num  = 3.2;
    k1 /= num;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k2[i] / num, k1[i]);
}

// Проверка оператора MyVector + MyVector
BOOST_AUTO_TEST_CASE(operation_add_MyVector) {
    MyVector k1 = {1.2, -44, 5, -7, -11};
    MyVector k2 = {0.1, 90.9, -81, 3, 2};
    MyVector k3 = k1 + k2;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] + k2[i], k3[i]);

    MyVector k4 = {1, 2, 3};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 + k4, std::length_error);
}

// Проверка оператора MyVector - MyVector
BOOST_AUTO_TEST_CASE(operation_sub_MyVector) {
    MyVector k1 = {1.2, -44, 5, -7, -11};
    MyVector k2 = {0.1, 90.9, -81, 3, 2};
    MyVector k3 = k1 - k2;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] - k2[i], k3[i]);

    MyVector k4 = {1, 2, 3};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 - k4, std::length_error);
}

// Проверка оператора MyVector * MyVector
BOOST_AUTO_TEST_CASE(operation_mul_MyVector) {
    MyVector k1 = {1.2, -44, 5, -7, -11};
    MyVector k2 = {0.1, 90.9, -81, 3, 2};
    MyVector k3 = k1 * k2;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] * k2[i], k3[i]);

    MyVector k4 = {1, 2, 3};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 * k4, std::length_error);
}

// Проверка оператора MyVector / MyVector
BOOST_AUTO_TEST_CASE(operation_div_MyVector) {
    MyVector k1 = {1.2, -44, 5, -7, -11};
    MyVector k2 = {0.1, 90.9, -81, 3, 2};
    MyVector k3 = k1 / k2;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] / k2[i], k3[i]);

    MyVector k4 = {1, 2, 3};
    BOOST_REQUIRE_NE(k1.size(), k4.size());
    BOOST_CHECK_THROW(k1 / k4, std::length_error);
}

// Проверка оператора MyVector + double и double + MyVector
BOOST_AUTO_TEST_CASE(operation_MyVector_add_double) {
    MyVector k1 = {9, 3.4, -2, 1, 999.999};
    MyVector k2 = k1;
    double num  = 0.17;
    MyVector k3 = k1 + num;
    MyVector k4 = num + k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k4.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
        BOOST_CHECK_EQUAL(k1[i] + num, k3[i]);
        BOOST_CHECK_EQUAL(num + k1[i], k4[i]);
    }
}

// Проверка оператора MyVector - double и double - MyVector
BOOST_AUTO_TEST_CASE(operation_MyVector_sub_double) {
    MyVector k1 = {9, 3.4, -2, 1, 999.999};
    MyVector k2 = k1;
    double num  = 0.17;
    MyVector k3 = k1 - num;
    MyVector k4 = num - k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k4.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
        BOOST_CHECK_EQUAL(k1[i] - num, k3[i]);
        BOOST_CHECK_EQUAL(num - k1[i], k4[i]);
    }
}

// Проверка оператора MyVector * double и double * MyVector
BOOST_AUTO_TEST_CASE(operation_MyVector_mul_double) {
    MyVector k1 = {9, 3.4, -2, 1, 999.999};
    MyVector k2 = k1;
    double num  = 0.17;
    MyVector k3 = k1 * num;
    MyVector k4 = num * k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k4.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
        BOOST_CHECK_EQUAL(k1[i] * num, k3[i]);
        BOOST_CHECK_EQUAL(num * k1[i], k4[i]);
    }
}

// Проверка оператора MyVector / double и double / MyVector
BOOST_AUTO_TEST_CASE(operation_MyVector_div_double) {
    MyVector k1 = {9, 3.4, -2, 1, 999.999};
    MyVector k2 = k1;
    double num  = 0.17;
    MyVector k3 = k1 / num;
    MyVector k4 = num / k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k4.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i], k2[i]);
        BOOST_CHECK_EQUAL(k1[i] / num, k3[i]);
        BOOST_CHECK_EQUAL(num / k1[i], k4[i]);
    }
}

// Проверка оператора отрицания
BOOST_AUTO_TEST_CASE(operator_negation) {
    MyVector k1 = {1, 0, -2, 4, 9.99};
    MyVector k2 = !k1;
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_NE(k1[i], k2[i]);
        BOOST_CHECK_EQUAL(k2[i], !k1[i]);
    }
}

// Проверка оператора "равно"
BOOST_AUTO_TEST_CASE(operator_equal) {
    MyVector k1 = {4, 0, 1, -3, 99.77};
    MyVector k2 = {-2, 10, -3, 1, 0};
    MyVector k3 = (k1 == k2);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] == k2[i], k3[i]);

    MyVector k4 = {1, 9, -3};
    BOOST_CHECK_THROW(k1 == k4, std::length_error);
}

// Проверка оператора "не равно"
BOOST_AUTO_TEST_CASE(operator_not_equal) {
    MyVector k1 = {4, 0, 1, -3, 99.77};
    MyVector k2 = {-2, 10, -3, 1, 0};
    MyVector k3 = (k1 != k2);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] != k2[i], k3[i]);

    MyVector k4 = {1, 9, -3};
    BOOST_CHECK_THROW(k1 != k4, std::length_error);
}

// Проверка оператора "больше"
BOOST_AUTO_TEST_CASE(operator_gt) {
    MyVector k1 = {4, 0, 1, -3, 99.77};
    MyVector k2 = {-2, 10, -3, 1, 0};
    MyVector k3 = (k1 > k2);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] > k2[i], k3[i]);

    MyVector k4 = {1, 9, -3};
    BOOST_CHECK_THROW(k1 > k4, std::length_error);
}

// Проверка оператора "меньше"
BOOST_AUTO_TEST_CASE(operator_lt) {
    MyVector k1 = {4, 0, 1, -3, 99.77};
    MyVector k2 = {-2, 10, -3, 1, 0};
    MyVector k3 = (k1 < k2);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] < k2[i], k3[i]);

    MyVector k4 = {1, 9, -3};
    BOOST_CHECK_THROW(k1 < k4, std::length_error);
}

// Проверка оператора "больше или равно"
BOOST_AUTO_TEST_CASE(operator_ge) {
    MyVector k1 = {4, 0, 1, -3, 99.77};
    MyVector k2 = {-2, 10, -3, 1, 0};
    MyVector k3 = (k1 >= k2);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] >= k2[i], k3[i]);

    MyVector k4 = {1, 9, -3};
    BOOST_CHECK_THROW(k1 >= k4, std::length_error);
}

// Проверка оператора "меньше или равно"
BOOST_AUTO_TEST_CASE(operator_le) {
    MyVector k1 = {4, 0, 1, -3, 99.77};
    MyVector k2 = {-2, 10, -3, 1, 0};
    MyVector k3 = (k1 <= k2);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++)
        BOOST_CHECK_EQUAL(k1[i] <= k2[i], k3[i]);

    MyVector k4 = {1, 9, -3};
    BOOST_CHECK_THROW(k1 <= k4, std::length_error);
}

// Проверка оператора MyVector == double и double == MyVector
BOOST_AUTO_TEST_CASE(operator_equal_double) {
    MyVector k1 = {0, 1, 2.2, -2.2, 4.76, 3};
    double num  = 2.2;
    MyVector k2 = (k1 == num);
    MyVector k3 = (num == k1);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i] == num, k2[i]);
        BOOST_CHECK_EQUAL(num == k1[i], k3[i]);
    }
}

// Проверка оператора MyVector != double и double != MyVector
BOOST_AUTO_TEST_CASE(operator_ne_double) {
    MyVector k1 = {0, 1, 2.2, -2.2, 4.76, 3};
    double num  = 2.2;
    MyVector k2 = (k1 != num);
    MyVector k3 = (num != k1);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i] != num, k2[i]);
        BOOST_CHECK_EQUAL(num != k1[i], k3[i]);
    }
}

// Проверка оператора MyVector < double и double < MyVector
BOOST_AUTO_TEST_CASE(operator_lt_double) {
    MyVector k1 = {0, 1, 2.2, -2.2, 4.76, 3};
    double num  = 2.2;
    MyVector k2 = (k1 < num);
    MyVector k3 = (num < k1);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i] < num, k2[i]);
        BOOST_CHECK_EQUAL(num < k1[i], k3[i]);
    }
}

// Проверка оператора MyVector > double и double > MyVector
BOOST_AUTO_TEST_CASE(operator_gt_double) {
    MyVector k1 = {0, 1, 2.2, -2.2, 4.76, 3};
    double num  = 2.2;
    MyVector k2 = (k1 > num);
    MyVector k3 = (num > k1);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i] > num, k2[i]);
        BOOST_CHECK_EQUAL(num > k1[i], k3[i]);
    }
}

// Проверка оператора MyVector <= double и double <= MyVector
BOOST_AUTO_TEST_CASE(operator_le_double) {
    MyVector k1 = {0, 1, 2.2, -2.2, 4.76, 3};
    double num  = 2.2;
    MyVector k2 = (k1 <= num);
    MyVector k3 = (num <= k1);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i] <= num, k2[i]);
        BOOST_CHECK_EQUAL(num <= k1[i], k3[i]);
    }
}

// Проверка оператора MyVector >= double и double >= MyVector
BOOST_AUTO_TEST_CASE(operator_ge_double) {
    MyVector k1 = {0, 1, 2.2, -2.2, 4.76, 3};
    double num  = 2.2;
    MyVector k2 = (k1 >= num);
    MyVector k3 = (num >= k1);
    BOOST_REQUIRE_EQUAL(k1.size(), k2.size());
    BOOST_REQUIRE_EQUAL(k1.size(), k3.size());
    for (int i = 0; i < k1.size(); i++) {
        BOOST_CHECK_EQUAL(k1[i] >= num, k2[i]);
        BOOST_CHECK_EQUAL(num >= k1[i], k3[i]);
    }
}
