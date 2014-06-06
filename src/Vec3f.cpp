#include <math.h>
#include "Vec3f.h"

Vec3f::Vec3f() : x(0.0f), y(0.0f), z(0.0f) { }

Vec3f::Vec3f(float x0, float y0, float z0) : x(x0), y(y0), z(z0) { }

Vec3f::Vec3f(const Vec3f &v) : x(v.x), y(v.y), z(v.z) { }

float Vec3f::mag() const {
    return sqrtf(x*x + y*y + z*z);
}

float Vec3f::lengthSquared() const {
    return x*x + y*y + z*z;
}

Vec3f Vec3f::norm() const {
    float m = mag();
    return Vec3f(x/m, y/m, z/m);
}

void Vec3f::normalize() {
    float m = mag();
    x /= m;
    y /= m;
    z /= m;
}

Vec3f Vec3f::operator+(const Vec3f &rhs) const {
    return Vec3f(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vec3f Vec3f::operator-(const Vec3f &rhs) const {
    return Vec3f(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vec3f Vec3f::operator*(const Vec3f &rhs) const {
    return Vec3f(x * rhs.x, y * rhs.y, z * rhs.z);
}

void Vec3f::operator+=(const Vec3f &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
}

void Vec3f::operator-=(const Vec3f &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
}

void Vec3f::operator*=(const Vec3f &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
}

void Vec3f::operator*=(float rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
}

void Vec3f::operator/=(float rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
}

bool Vec3f::operator==(const Vec3f &rhs) {
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool operator!=(const Vec3f &rhs) {
    return x != rhs.x || y != rhs.y || z != rhs.z;
}

Vec3f operator*(const Vec3f &vec, float scl) {
    return Vec3f(vec.x * scl, vec.y * scl, vec.z * scl);
}

Vec3f operator/(const Vec3f &vec, float scl) {
    return Vec3f(vec.x / scl, vec.y / scl, vec.z / scl);
}

Vec3f operator*(float scl, const Vec3f &vec) {
    return Vec3f(vec.x * scl, vec.y * scl, vec.z * scl);
}

Vec3f operator/(float scl, const Vec3f &vec) {
    return Vec3f(vec.x / scl, vec.y / scl, vec.z / scl);
}

std::ostream &operator<<(std::ostream &os, const Vec3f &vec) {
    os << "<" << vec.x << ", " << vec.y << ", " << vec.z << ">";
    return os;
}
