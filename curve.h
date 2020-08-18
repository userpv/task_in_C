#ifndef CURVE_H
#define CURVE_H

#include <string>
#include <point3d.h>
#include <vector3d.h>

class curve
{
    public:
        curve();
        virtual ~curve();


        virtual Point3D get_3Dpoint(double t) = 0;
        virtual Vector3D get_firstDerivative(double t) = 0;
        virtual void out_debug_info() = 0;
        virtual std::string get_CurveType() = 0;

    protected:

};

#endif // CURVE_H
