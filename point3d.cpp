#include "point3d.h"
#include <iostream>

Point3D::Point3D()
{
    this->X = 0.0;
    this->Y = 0.0;
    this->Z = 0.0;
}

Point3D::Point3D(double x, double y, double z)
{
    this->X = x;
    this->Y = y;
    this->Z = z;
}

Point3D::Point3D(const Point3D &p)
{
    this->X = p.X;
    this->Y = p.Y;
    this->Z = p.Z;
}

Point3D::~Point3D()
{

}

void Point3D::out_debug_info()
{
    std::cout << "x = " << GetX() << " y = " << GetY() << " z = " << GetZ() << std::endl;
}

void Point3D::SetX(double x)
{
    this->X = x;
}

void Point3D::SetY(double y)
{
    this->Y = y;
}

void Point3D::SetZ(double z)
{
    this->Z = z;
}

double Point3D::GetX()
{
    return this->X;
}

double Point3D::GetY()
{
    return this->Y;
}

double Point3D::GetZ()
{
    return this->Z;
}

Point3D& Point3D::operator=(Point3D& p)
{
    this->X = p.X;
    this->Y = p.Y;
    this->Z = p.Z;

    return *this;
}
