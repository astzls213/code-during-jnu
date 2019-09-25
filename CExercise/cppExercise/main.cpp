#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int ci=1,*ir=&ci;
    decltype((ci)) k=ci;

    return 0;
}