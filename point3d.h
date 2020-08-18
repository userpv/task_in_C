#ifndef POINT3D_H
#define POINT3D_H


class Point3D
{
    public:
        Point3D();
        Point3D(double x, double y, double z);
        Point3D(const Point3D &p);
        ~Point3D();

        virtual void out_debug_info();

        void SetX(double x);
        void SetY(double y);
        void SetZ(double z);

        double GetX();
        double GetY();
        double GetZ();

        Point3D& operator=(Point3D& p);

    protected:
        double X;
        double Y;
        double Z;

    private:
};

#endif // POINT3D_H
