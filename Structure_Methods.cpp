#include <cmath>
#include <iostream>

struct Point {
    double x;
    double y;

    double veclen(void) {
        return sqrt(this->x * this->x + this->y * this->y);
    }
};

// Пример использования методов структур.
// Объявления структур можно делать в заголовочном файле,
// а определения - в исходном файле.
// Неявный аргумент "this" у методов - указатель на экземпляр структуры.
int main(void) {
    struct Point p = {3, 4};
    std::cout << p.veclen() << std::endl;
    return 0;
}
