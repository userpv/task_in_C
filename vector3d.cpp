#include "vector3d.h"
#include <iostream>

Vector3D::Vector3D():Point3D()
{

}

Vector3D::Vector3D(double x, double y, double z):Point3D(x, y, z)
{

}

Vector3D::Vector3D(Point3D p)
{
    this->X = p.GetX();
    this->Y = p.GetY();
    this->Z = p.GetZ();
}

Vector3D& Vector3D::operator=(Vector3D& v)
{
    this->X = v.X;
    this->Y = v.Y;
    this->Z = v.Z;

    return *this;
}

Vector3D::~Vector3D()
{

}

void Vector3D::out_debug_info()
{
    std::cout << "dx/dt = " << GetX() << " dy/dt = " << GetY() << " dz/dt = " << GetZ() << std::endl;
}
