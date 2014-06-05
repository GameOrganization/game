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
}


//Kevin is a huge fucking retard, so yeah, there's that
