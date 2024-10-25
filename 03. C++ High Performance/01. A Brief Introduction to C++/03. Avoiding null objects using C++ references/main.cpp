/* In addition to strict ownership, C++ also has the concept of references, which
is different from references in Java. Internally, a reference is a pointer which is
not allowed to be null or repointed; therefore no copying is involved when passing
it to a function. As a result, a function signature in C++ can explicitly restrict
the programmer from passing a null object as a parameter. In Java the programmer
must use documentation or annotations to indicate non-null parameters

Take a look at these two Java functions for computing the volume of a sphere. The
first one throws a runtime exception if a null object is passed to it; whereas the
second one silently ignores null objects

This first implementation in Java throws a runtime exception if passed a null object */
// Java
float getVolume(Sphere s)
{
    float cube = Math.pow(s.radius(), 3);
    return (Math.PI * 4 / 3) * cube;
}

// This second implementation in Java silently handles null objects
// Java
float getVolume2(Sphere s)
{
    /* -> */ float rad = a == null ? 0.0f : s.radius();
    float cube = Math.pow(rad, 3);
    return (Math.PI * 4 / 3) * cube;
}

/* In both function implemented in Java, the caller of the function has to inspect
the implementation of the function in order to determine whether null objects are
allowed or not. In C++, the first function signature explicitly accepts only
initialized objects by using references which cannot be null. The second version
using pointers as arguments, explicitly shows that null objects are handled */

#include <iostream>

/* Personal note: I don't know if this class has the correct properties, it's not
exemplified in the book */
class Sphere
{
    private:
        float _radius;

    public:
        float radius() const
        {
            return _radius;
        }
};

// C++ arguments passed as references indicates that null values are not allowed
auto get_volume1(const Sphere& s)
{
    auto cube = std::pow(s.radius(), 3);
    auto pi = 3.14f;
    return (pi * 4 / 3) * cube;
}

// C++ arguments passed as pointers indicates that null values are being handled
auto get_volume2(const Sphere* s)
{
    auto rad = s ? s->radius() : 0.0f;
    auto cube = std::pow(rad, 3);
    auto pi = 3.14f;
    return (pi * 4 / 3) * cube;
}