#include "CustomLayoutPosition.h"
#include "LayoutPosition.h"

#define L1 500
#define L2 50
/***************************************************************************************
                                A
                     <------------------         __L1___
                         |   |_____|   |        |_______| L2
                         |__         __|
                         |  |       |  |
                    D    |  |       |  |    B
                         |__|       |__|
                         |   _______   |
                         |   |     |   |
                          -------------|
                                C      V

 **************************************************************************************/
class Position_A :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_centerADC_point.x - (L1/2);
        this->min.x = (x >= abs_minADC_point.x)? x:abs_minADC_point.x;
        int y = abs_minADC_point.y;
        this->min.y=y;
        
        x=abs_centerADC_point.x +(L1/2);
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_minADC_point.y + L2;
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};