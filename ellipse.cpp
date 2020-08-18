#include <ellipse.h>
#include <iostream>
#include <math.h>

ellipse::ellipse()
{
    this->a = 0.0;
    this->b = 0.0;
}

ellipse::ellipse(double a, double b, Point3D cp)
{
    this->a = fabs(a);
    this->b = fabs(b);

    this->Cp = cp;
    (this->Cp).SetZ(0.0);
}

ellipse::ellipse(double a, double b, double xc, double yc)
{
    this->a = fabs(a);
    this->b = fabs(a);

    (this->Cp).SetX(xc);
    (this->Cp).SetY(yc);
    (this->Cp).SetZ(0.0);
}

ellipse::~ellipse()
{

}

std::string ellipse::get_CurveType()
{
    return "ellipse";
}

Point3D ellipse::get_3Dpoint(double t)
{
    Point3D point;

    double x = (this->a) * cos(t) + (this->Cp).GetX();
    double y = (this->b) * sin(t) + (this->Cp).GetY();

    point.SetX(x);
    point.SetY(y);
    point.SetZ(0.0);

    return point;
}

Vector3D ellipse::get_firstDerivative(double t)
{
    Vector3D vec;

    double x_der = -1.0 * (this->a) * sin(t);
    double y_der = (this->b) * cos(t);

    vec.SetX(x_der);
    vec.SetY(y_der);
    vec.SetZ(0.0);

    return vec;
}

void ellipse::out_debug_info()
{
    std::cout << "ellipse" << " a = " << a << " b = " << b << " xc = " << Cp.GetX() << " yc = " << Cp.GetY() << " zc = " << Cp.GetZ() << std::endl;
}

double  ellipse::GetA()
{
    return a;
}

double  ellipse::GetB()
{
    return b;
}

Point3D ellipse::GetCp()
{
    return Cp;
}

