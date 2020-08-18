#include "helix.h"
#include <iostream>
#include <math.h>
#define M_PI		3.14159265358979323846

helix::helix()
{
    this->a = 0.0;
    this->step = 0.0;
}

helix::helix(double a, double step, Point3D cp)
{
    this->a = abs(a);
    this->step = abs(step);
    this->Cp = cp;
}
helix::helix(double a, double step, double xc, double yc, double zc)
{
    this->a = fabs(a);
    this->step = fabs(step);

    (this->Cp).SetX(xc);
    (this->Cp).SetY(yc);
    (this->Cp).SetZ(zc);
}
helix::~helix()
{

}

std::string helix::get_CurveType()
{
    return "helix";
}

Point3D helix::get_3Dpoint(double t)
{
    Point3D point;
    double x = (this->a) * cos(t) + (this->Cp).GetX();
    double y = (this->a) * sin(t) + (this->Cp).GetY();
    double z = ((this->step) * t)/(2*M_PI) + (this->Cp).GetZ();

    point.SetX(x);
    point.SetY(y);
    point.SetZ(z);
    return point;
}
Vector3D helix::get_firstDerivative(double t)
{
    Vector3D vec;
    double x_der = -1.0 * (this->a) * sin(t);
    double y_der = (this->a) * cos(t);
    double z_der = (this->step)/(2*M_PI);

    vec.SetX(x_der);
    vec.SetY(y_der);
    vec.SetZ(z_der);
    return vec;
}
void helix::out_debug_info()
{
    std::cout << "helix" << " a = " << a << " step = " << step << " xc = " << Cp.GetX() << " yc = " << Cp.GetY() << " zc = " << Cp.GetZ() << std::endl;
}
double  helix::GetA()
{
    return a;
}
double  helix::GetStep()
{
    return step;
}
Point3D helix::GetCp()
{
    return Cp;
}
