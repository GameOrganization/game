#ifndef VEC3F_H
#define VEC3F_H

#include <iostream>

struct Vec3f {
    //The components of the vector, public for accessibility
    float x, y, z;

    //Constructs a vector with zero magnitude
    Vec3f();
    //Constructs a vector with the specified components
    Vec3f(float x0, float y0, float z0);
    //Copy constructor
    Vec3f(const Vec3f &toCopy);

    //Returns the magnitude of the vector
    float mag() const;
    //Returns a normalized copy of the vector
    Vec3f norm() const;
    //Normalizes the vector
    void normalize();

    //Returns the vector sum of this vector and the RHS
    Vec3f operator+(const Vec3f &rhs) const;
    //Returns the vector difference of this vector and the RHS
    Vec3f operator-(const Vec3f &rhs) const;
    //Returns the scaled vector of this and the RHS
    Vec3f operator*(float rhs) const;
    //Returns the scaled vector of this and the inverse of the RHS
    Vec3f operator/(float rhs) const;

    //Adds the RHS to this vector
    void operator+=(const Vec3f &rhs);
    //Subtracts the RHS from this vector
    void operator-=(const Vec3f &rhs);
    //Scales this vector by the RHS
    void operator*=(float rhs);
    //Scales this vector by the inverse of the RHS
    void operator/=(float rhs);

    //Output stream function, prints in the format <x, y, z>
    friend std::ostream &operator<<(std::ostream &os, const Vec3f &vec);
};

#endif // VEC3F_H