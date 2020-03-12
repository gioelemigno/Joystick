#pragma once

#include "LayoutPosition.h"

class LayoutPosition_cross : public LayoutPosition{

    public:
        LayoutPosition_cross();
        enum id_pos_custom {id_pos_up=id_pos_unknown+1, id_pos_down, id_pos_left, id_pos_right};
        
        virtual void setOrientation(orientation_t orient);    
 
};