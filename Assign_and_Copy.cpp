#include <algorithm>

class IntArray {
    public:
        // Конструктор
        explicit IntArray(unsigned a): size_(a), data_(new int[size_]) {};

        // Деструктор
        ~IntArray(void) { delete [] data_; };

        // Оператор присваивания
        IntArray &operator=(IntArray const &a) {
            if (this != &a) {
                delete [] data_;
                size_ = a.size_;
                data_ = new int[size_];
                for (unsigned i = 0; i != size_; i++)
                    data_[i] = a.data_[i];
            }
            return *this;
        }

        // Конструктор копирования
        IntArray(IntArray const &a): size_(a.size_), data_(new int[size_]) {
            for (unsigned i = 0; i != size_; i++)
                data_[i] = a.data_[i];
        }

        // Обмен содержимым у двух экземпляров класса
        void swap(IntArray &a) {
            std::swap(size_, a.size_);
            std::swap(data_, a.data_);
        }

    private:
        unsigned size_;
        int *data_;
};

// Пример использования конструктора копирования, оператора присваивания
// и обмена содержимым
// Если конструктор копирования явно не задан, то используется конструктор копирования по умолчанию.
// Если оператор присваивания явно не задан, то используется оператор присваивания по умолчанию.
// Чтобы запретить копирование или присваивание, 
// необходимо объявить конструктор копирования и оператор присваивания
// как private и не определять их.
int main(void) {
    IntArray a1(10);
    IntArray a2(20);
    IntArray a3 = a1;   // копирование
    a2 = a1;            // присваивание
    IntArray a4(30);
    a4.swap(a2);        // обмен содержимым
    return 0;
}