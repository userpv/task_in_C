#ifndef ELIPSE_H
#define ELIPSE_H

#include <curve.h>
#include <point3d.h>
#include <vector3d.h>

class ellipse : public curve
{
    public:
        ellipse();
        ellipse(double a, double b, Point3D cp);
        ellipse(double a, double b, double xc, double yc);
        ~ellipse();

        std::string get_CurveType();
        Point3D get_3Dpoint(double t);
        Vector3D get_firstDerivative(double t);
        void out_debug_info();

        double  GetA();
        double  GetB();
        Point3D GetCp();

    protected:
        double a;
        double b;
        Point3D Cp;

    private:
};

#endif // ELIPSE_H
