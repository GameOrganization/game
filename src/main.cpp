#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Vec3f.h"

//returns float between -2.0f, and 2.0f, multiples of .25
float randFloat() {
    float v = (float)(rand() % 16) / 16.0f;
    return -2.0f + (4.0f * v);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    Vec3f a(randFloat(), randFloat(), randFloat());
    Vec3f b(randFloat(), randFloat(), randFloat());
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c = a + b" << std::endl;
    Vec3f c = a + b;
    std::cout << "c: " << c << std::endl;

    std::cout<< "a dot b" <<std::endl;
    float dot = Vec3f::dot(a,b);
    std::cout<<dot<<std::endl;

    std::cout<< "a cross b" <<std::endl;
    Vec3f cross = Vec3f::cross(a,b);
    std::cout<<cross<<std::endl;
    a = Vec3f(1.0f, 0.0f, 0.0f);
    b = Vec3f(0.0f, 1.0f, 0.0f);
    std::cout << "Angle: " << Vec3f::angle(a, b) << std::endl;
}
