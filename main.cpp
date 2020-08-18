#include <iostream>
#include <curve.h>
#include <xoy_circle.h>
#include <ellipse.h>
#include <helix.h>
#include <vector>
#include <iterator>
#include <memory>
#define M_PI_4		0.78539816339744830962
#include <random>
#include <ctime>
#include <algorithm>

typedef std::vector<std::unique_ptr<curve> > vector_smart_ptr_curve;
typedef std::vector<std::unique_ptr<curve> >::const_iterator iterator_curve;
typedef std::vector<xoy_circle * >::const_iterator iterator_circle;




bool compare_Circle(xoy_circle* aPtr, xoy_circle* bPtr)
{

    return (*aPtr) < (*bPtr);
}


int main()
{
    //генерирование обЪектов каждого типа со случайными параметрами и добавление их в вектор

    //std::vector<std::unique_ptr<curve> > curves;
    vector_smart_ptr_curve curves;
    std::vector<xoy_circle*>  circles;

    std::mt19937 engine;
    engine.seed(std::time(nullptr));
    std::uniform_int_distribution<> dist_num( 3, 30 );
    std::uniform_int_distribution<> dist_rand( 0, 2 );

    std::uniform_real_distribution<> dist_R_step( 1, 100 );

    int rand_number_circle = dist_num(engine);
    int rand_number_ellipse = dist_num(engine);
    int rand_number_helix = dist_num(engine);

    bool forbiden_num[3] = {false,false,false};

    for(int i = 0, i_c = 0, i_el = 0, i_hel = 0; i<rand_number_circle+rand_number_ellipse+rand_number_helix; i++)
    {
        int ran_num = dist_rand(engine);
        while(((ran_num==0)&&(forbiden_num[0]==true))||
              ((ran_num==1)&&(forbiden_num[1]==true))||
              ((ran_num==2)&&(forbiden_num[2]==true)))
            {
                ran_num = dist_rand(engine);
            }

        if(ran_num==0)
        {
            curves.push_back(std::move(std::unique_ptr<curve>( new xoy_circle(dist_R_step(engine), 0.0, 0.0) )));
            i_c++;
            if(rand_number_circle==i_c){
                forbiden_num[0]=true;
            }
        }
        if(ran_num==1)
        {
            curves.push_back(std::move(std::unique_ptr<curve>( new ellipse(dist_R_step(engine), dist_R_step(engine), 0.0, 0.0) )));
            i_el++;
            if(rand_number_ellipse==i_el){
                forbiden_num[1]=true;
            }
        }
        if(ran_num==2)
        {
            curves.push_back(std::move(std::unique_ptr<curve>( new helix(dist_R_step(engine), dist_R_step(engine), 0.0, 0.0, 0.0))));
            i_hel++;
            if(rand_number_helix==i_hel){
                forbiden_num[2]=true;
            }
        }
    }

    //вывод координат точек и первой производной при t=Pi/4

    iterator_curve pos_curves;
    for (pos_curves = curves.begin(); pos_curves != curves.end(); ++pos_curves)
    {
            (*pos_curves)->get_3Dpoint(M_PI_4).out_debug_info();
            (*pos_curves)->get_firstDerivative(M_PI_4).out_debug_info();
    }

    //заполнение второго вектора обЪектами класса xoy_circle

    for (pos_curves = curves.begin(); pos_curves != curves.end(); ++pos_curves)
        {
            if((*pos_curves)->get_CurveType()=="xoy_circle")
            {
                circles.push_back((xoy_circle*)((*pos_curves).get()));
            }

        }

    //сортировка по возрастанию радиусов окружностей

    std::sort(circles.begin(), circles.end(), compare_Circle);

    iterator_circle pos_circles;
    for (pos_circles = circles.begin(); pos_circles != circles.end(); ++pos_circles) {
        (*pos_circles)->out_debug_info();
    }

    //сумма радиусов кривых во втором векторе

    double sum_R = 0.0;

    for (pos_circles = circles.begin(); pos_circles != circles.end(); ++pos_circles) {
        sum_R = sum_R +((*pos_circles)->GetR());
    }

    std::cout << "sum_R = " << sum_R << std::endl;

    return 0;
}
