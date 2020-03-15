#pragma once

#include "LayoutPosition.h"
#include <stdint.h>

#define N_CUSTOM_POS    4

class LayoutPosition_cross : public LayoutPosition{

    public:
        LayoutPosition_cross();
        static const uint16_t n_pos_custom = N_CUSTOM_POS;
        //enum n_pos {}
        enum id_pos_custom {id_pos_up=id_pos_unknown+1, id_pos_down, id_pos_left, id_pos_right};
        
        virtual void setOrientation(orientation_t orient);    
 
};

#define N_CUSTOM_POS_STAR    8

class LayoutPosition_star : public LayoutPosition{

    public:
        LayoutPosition_star();
        static const uint16_t n_pos_custom = N_CUSTOM_POS_STAR;
        //enum n_pos {}
        enum id_pos_custom {id_pos_up=id_pos_unknown+1, id_pos_down, id_pos_left, 
            id_pos_right, id_pos_up_right, id_pos_up_left, id_pos_down_left, id_pos_down_right};
        
        virtual void setOrientation(orientation_t orient);    
 
};
