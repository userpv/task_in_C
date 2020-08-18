#ifndef XOY_CIRCLE_H
#define XOY_CIRCLE_H

#include <curve.h>
#include <point3d.h>
#include <vector3d.h>

class xoy_circle : public curve
{
    public:
        xoy_circle();
        xoy_circle(double r, Point3D cp);
        xoy_circle(double r, double xc, double yc);

        ~xoy_circle();

        std::string get_CurveType();
        bool operator > (xoy_circle right);
        bool operator < (xoy_circle right);
        bool operator == (xoy_circle right);
        bool operator != (xoy_circle right);
        Point3D  get_3Dpoint(double t);
        Vector3D get_firstDerivative(double t);
        void out_debug_info();

        double  GetR();
        Point3D GetCp();

    protected:
        double R;
        Point3D Cp;

    private:
};

#endif // CIRCLE_H
