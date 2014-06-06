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
    std::cout << "Magnitude of a: " << a.mag() << std::endl;
    std::cout << "Magnitude of b: " << b.mag() << std::endl;
    std::cout << "Normalized a: " << a.norm() << std::endl;
    std::cout << "Normalized b: " << b.norm() << std::endl;
    std::cout << "a + b: " << a+b << std::endl;
    std::cout<< "a dot b: " <<Vec3f::dot(a,b)<<std::endl;
    std::cout<< "a cross b: " <<Vec3f::cross(a,b)<<std::endl;
    std::cout << "Angle between " <<a<<" and "<<b<<": "<<Vec3f::angle(a, b) << std::endl;
}
