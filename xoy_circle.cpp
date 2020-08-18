#include <xoy_circle.h>
#include <iostream>
#include <math.h>

xoy_circle::xoy_circle()
{
    this->R = 0.0;
}

xoy_circle::xoy_circle(double r, Point3D cp)
{
    this->R = fabs(r);
    this->Cp = cp;
    (this->Cp).SetZ(0.0);
}

xoy_circle::xoy_circle(double r, double xc, double yc)
{
    this->R = fabs(r);

    (this->Cp).SetX(xc);
    (this->Cp).SetY(yc);
    (this->Cp).SetZ(0.0);
}

xoy_circle::~xoy_circle()
{

}

bool xoy_circle::operator > (xoy_circle right)
{
    return this->R > right.R;
}

bool xoy_circle::operator < (xoy_circle right)
{
    return this->R < right.R;
}

bool xoy_circle::operator == (xoy_circle right)
{
    return this->R == right.R;
}

bool xoy_circle::operator != (xoy_circle right)
{
    return this->R != right.R;
}

std::string xoy_circle::get_CurveType()
{
    return "xoy_circle";
}

Point3D xoy_circle::get_3Dpoint(double t)
{
    Point3D point;

    double x = (this->R) * cos(t) + (this->Cp).GetX();
    double y = (this->R) * sin(t) + (this->Cp).GetY();

    point.SetX(x);
    point.SetY(y);
    point.SetZ(0.0);

    return point;
}
Vector3D xoy_circle::get_firstDerivative(double t)
{
    Vector3D vec;

    double x_der = -1.0 * (this->R) * sin(t);
    double y_der = (this->R) * cos(t);

    vec.SetX(x_der);
    vec.SetY(y_der);
    vec.SetZ(0.0);

    return vec;
}

void xoy_circle::out_debug_info()
{
    std::cout << "xoy_circle" << " R = " << R << " xc = " << Cp.GetX() << " yc = " << Cp.GetY() << " zc = " << Cp.GetZ() << std::endl;
}

double xoy_circle::GetR()
{
    return R;
}

Point3D xoy_circle::GetCp()
{
    return Cp;
}
