#include <iostream>

struct s1 {
    float f1;
    char* p1;
    int i1;
    union {
        unsigned int ui1;
        double d1;
    } u1;
};

int main()
{
    std::cout << sizeof(s1) << std::endl;
}

