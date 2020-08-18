#ifndef HELIX_H
#define HELIX_H

#include <curve.h>
#include <point3d.h>
#include <vector3d.h>

class helix : public curve
{
    public:
        helix();
        helix(double a, double step, Point3D cp);
        helix(double a, double step, double xc, double yc, double zc);
        ~helix();
        std::string get_CurveType();
        Point3D get_3Dpoint(double t);
        Vector3D get_firstDerivative(double t);
        void out_debug_info();
        double  GetA();
        double  GetStep();
        Point3D GetCp();

    protected:
        double a;
        double step;
        Point3D Cp;

    private:
};

#endif // HELIX_H
