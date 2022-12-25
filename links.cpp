#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

// Пример использования ссылок.
// Они являются "красивой" оберткой над указателями.
int main(void) {
    int k = 10, m = 20;
    swap(k, m);
    cout << k << ' ' << m << endl;
    return 0;
}
