#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <point3d.h>


class Vector3D : public Point3D
{
    public:
        Vector3D();
        Vector3D(double x, double y, double z);
        Vector3D(Point3D p);
        ~Vector3D();

        Vector3D& operator=(Vector3D& v);
        void out_debug_info();

    protected:

    private:
};

#endif // VECTOR3D_H
