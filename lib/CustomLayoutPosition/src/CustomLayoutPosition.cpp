#include "CustomLayoutPosition.h"
#include "LayoutPosition.h"
#include <stdint.h>

#define L1 500
#define L2 50

//const uint16_t LayoutPosition_cross::n_pos_custom = N_CUSTOM_POS;
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

class Position_B :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_minADC_point.x;
        this->min.x = x;
        int y = abs_centerADC_point.y - (L1/2);
        this->min.y=(y>=abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_minADC_point.x + L2;
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_centerADC_point.y + (L1/2);
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};

class Position_C :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_centerADC_point.x - (L1/2);
        this->min.x = (x >= abs_minADC_point.x)? x:abs_minADC_point.x;
        int y = abs_maxADC_point.y - L2;
        this->min.y=(y>= abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_centerADC_point.x +(L1/2);
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_maxADC_point.y;
        this->max.y=y;
    }
};

class Position_D :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_maxADC_point.x - L2;
        this->min.x = (x>= abs_minADC_point.x)?x:abs_minADC_point.x;
        int y = abs_centerADC_point.y - (L1/2);
        this->min.y=(y>=abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_maxADC_point.x;
        this->max.x = x;
        y = abs_centerADC_point.y + (L1/2);
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};


Position* custom_position_array[LayoutPosition::n_pos_default+LayoutPosition_cross::n_pos_custom];
Position_A A_pos;
Position_B B_pos;
Position_C C_pos;
Position_D D_pos;

/*
    this->position.position=default_position_array;
    this->position.size=SIZE_DEFAULT_POSITION;
    this->setOrientation(LayoutPosition::or_0_deg);
    this->calibration(this->abs_minADC_point, this->abs_maxADC_point, this->abs_centerADC_point);
*/
LayoutPosition_cross::LayoutPosition_cross(){
    //copy in new array default position
    for(uint16_t i = 0; i< LayoutPosition::n_pos_default; i++){
        custom_position_array[i] = this->position.position[i];
    }
    this->position.position = custom_position_array;
    this->position.size = LayoutPosition::n_pos_default+LayoutPosition_cross::n_pos_custom;

    this->setOrientation(this->or_0_deg);
    this->calibration(this->abs_minADC_point, this->abs_maxADC_point, this->abs_centerADC_point);
}
        
        
void LayoutPosition_cross::setOrientation(orientation_t orient){
    switch (orient){
    case LayoutPosition::or_0_deg:
        A_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&A_pos;

        B_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&B_pos;

        C_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&C_pos;

        D_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&D_pos;
        break;
    
    case LayoutPosition::or_90_deg:
        A_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&A_pos;

        B_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&B_pos;

        C_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&C_pos;

        D_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&D_pos;
        break;

    case LayoutPosition::or_180_deg:
        A_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&A_pos;

        B_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&B_pos;

        C_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&C_pos;

        D_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&D_pos;
        break;
    
    case LayoutPosition::or_270_deg:
        A_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&A_pos;

        B_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&B_pos;

        C_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&C_pos;

        D_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&D_pos;
        break;
        
    default:
        while(1){
            Serial.println("ERRORE");
            delay(1000);
        }
        break;
    }
} 


/**************************************************************************************
 * 
 * ***********************************************************************************/

#define L1_CROSS 500
#define L2_CROSS L1_CROSS

//const uint16_t LayoutPosition_cross::n_pos_custom = N_CUSTOM_POS;
/***************************************************************************************
                                A                L1_CROSS
                     <------------------         ___ 
                    H    |__|  |__| |__| E       |__| L2_CROSS
                         |             |
                         |__         __|
                    D    |__|       |__|  B
                         |             |
                         |__    __   __|
                    G    |  |  |  | |  |  F
                          -------------|
                                C      V

 **************************************************************************************/
class Position_A_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_centerADC_point.x - (L1_CROSS/2);
        this->min.x = (x >= abs_minADC_point.x)? x:abs_minADC_point.x;
        int y = abs_minADC_point.y;
        this->min.y=y;
        
        x=abs_centerADC_point.x +(L1_CROSS/2);
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_minADC_point.y + L2_CROSS;
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};

class Position_B_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_minADC_point.x;
        this->min.x = x;
        int y = abs_centerADC_point.y - (L1_CROSS/2);
        this->min.y=(y>=abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_minADC_point.x + L2_CROSS;
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_centerADC_point.y + (L1_CROSS/2);
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};

class Position_C_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_centerADC_point.x - (L1_CROSS/2);
        this->min.x = (x >= abs_minADC_point.x)? x:abs_minADC_point.x;
        int y = abs_maxADC_point.y - L2_CROSS;
        this->min.y=(y>= abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_centerADC_point.x +(L1_CROSS/2);
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_maxADC_point.y;
        this->max.y=y;
    }
};

class Position_D_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_maxADC_point.x - L2_CROSS;
        this->min.x = (x>= abs_minADC_point.x)?x:abs_minADC_point.x;
        int y = abs_centerADC_point.y - (L1_CROSS/2);
        this->min.y=(y>=abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_maxADC_point.x;
        this->max.x = x;
        y = abs_centerADC_point.y + (L1_CROSS/2);
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};


class Position_E_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_minADC_point.x;
        this->min.x = x;
        int y = abs_minADC_point.y;
        this->min.y=y;
        
        x=abs_minADC_point.x+L1_CROSS;
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_minADC_point.y + L2_CROSS;
        this->max.y = (y<= abs_maxADC_point.y)?y:abs_maxADC_point.y;
    }
};

class Position_F_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_minADC_point.x;
        this->min.x = x;
        int y = abs_maxADC_point.y - L2_CROSS;
        this->min.y=(y>=abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_minADC_point.x + L1_CROSS;
        this->max.x = (x <= abs_maxADC_point.x)? x: abs_maxADC_point.x;
        y = abs_maxADC_point.y;
        this->max.y = y;
    }
};


class Position_G_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_maxADC_point.x-L1_CROSS;
        this->min.x = (x>=abs_minADC_point.x)?x:abs_minADC_point.x;
        int y = abs_maxADC_point.y - L2_CROSS;
        this->min.y=(y>=abs_minADC_point.y)?y:abs_minADC_point.y;
        
        x=abs_maxADC_point.x;
        this->max.x = x;
        y = abs_maxADC_point.y;
        this->max.y = y;
    }
};

class Position_H_edge :public Position{
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
        int x = abs_maxADC_point.x-L1_CROSS;
        this->min.x = (x>=abs_minADC_point.x)?x:abs_minADC_point.x;
        int y = abs_minADC_point.y;
        this->min.y=y;
        
        x=abs_maxADC_point.x;
        this->max.x = x;
        y = abs_minADC_point.y+L2_CROSS;
        this->max.y = (y<=abs_minADC_point.y)?y:abs_minADC_point.y;
    }
};

Position* custom_position_array_star[LayoutPosition::n_pos_default+LayoutPosition_star::n_pos_custom];
Position_A_edge A_edge_pos;
Position_B_edge B_edge_pos;
Position_C_edge C_edge_pos;
Position_D_edge D_edge_pos;
Position_E_edge E_edge_pos;
Position_F_edge F_edge_pos;
Position_G_edge G_edge_pos;
Position_H_edge H_edge_pos;

LayoutPosition_star::LayoutPosition_star(){
    //copy in new array default position
    for(uint16_t i = 0; i< LayoutPosition::n_pos_default; i++){
        custom_position_array_star[i] = this->position.position[i];
    }
    this->position.position = custom_position_array_star;
    this->position.size = LayoutPosition::n_pos_default+LayoutPosition_star::n_pos_custom;

    this->setOrientation(this->or_0_deg);
    this->calibration(this->abs_minADC_point, this->abs_maxADC_point, this->abs_centerADC_point);
}
        
        
void LayoutPosition_star::setOrientation(orientation_t orient){
    switch (orient){
    case LayoutPosition::or_0_deg:
        A_edge_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_star::id_pos_up]=&A_edge_pos;

        B_edge_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_star::id_pos_right]=&B_edge_pos;

        C_edge_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_star::id_pos_down]=&C_edge_pos;

        D_edge_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_star::id_pos_left]=&D_edge_pos;
        
        E_edge_pos.init("Up right", false, this->id_pos_up_right);
        this->position.position[LayoutPosition_star::id_pos_up_right]=&E_edge_pos;

        F_edge_pos.init("Down right", false, this->id_pos_down_right);
        this->position.position[LayoutPosition_star::id_pos_down_right]=&F_edge_pos;

        G_edge_pos.init("Down left", false, this->id_pos_down_left);
        this->position.position[LayoutPosition_star::id_pos_down_left]=&G_edge_pos;

        H_edge_pos.init("Up left", false, this->id_pos_up_left);
        this->position.position[LayoutPosition_star::id_pos_up_left]=&H_edge_pos;
        break;
    
    case LayoutPosition::or_90_deg:
        
        A_edge_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&A_edge_pos;

        B_edge_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&B_edge_pos;

        C_edge_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&C_edge_pos;

        D_edge_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&D_edge_pos;
        
        E_edge_pos.init("Up left", false, this->id_pos_up_left);
        this->position.position[LayoutPosition_star::id_pos_up_left]=&E_edge_pos;

        F_edge_pos.init("Up right", false, this->id_pos_up_right);
        this->position.position[LayoutPosition_star::id_pos_up_right]=&F_edge_pos;

        G_edge_pos.init("Down right", false, this->id_pos_down_right);
        this->position.position[LayoutPosition_star::id_pos_down_right]=&G_edge_pos;

        H_edge_pos.init("Down left", false, this->id_pos_down_left);
        this->position.position[LayoutPosition_star::id_pos_down_left]=&H_edge_pos;
        break;

    case LayoutPosition::or_180_deg:
        A_edge_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&A_edge_pos;

        B_edge_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&B_edge_pos;

        C_edge_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&C_edge_pos;

        D_edge_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&D_edge_pos;

        E_edge_pos.init("Down left", false, this->id_pos_down_left);
        this->position.position[LayoutPosition_star::id_pos_down_left]=&E_edge_pos;

        F_edge_pos.init("Up left", false, this->id_pos_up_left);
        this->position.position[LayoutPosition_star::id_pos_up_left]=&F_edge_pos;

        G_edge_pos.init("Up right", false, this->id_pos_up_right);
        this->position.position[LayoutPosition_star::id_pos_up_right]=&G_edge_pos;

        H_edge_pos.init("Down right", false, this->id_pos_down_right);
        this->position.position[LayoutPosition_star::id_pos_down_right]=&H_edge_pos;
        break;
    
    case LayoutPosition::or_270_deg:
        A_edge_pos.init("Right", false, this->id_pos_right);
        this->position.position[LayoutPosition_cross::id_pos_right]=&A_edge_pos;

        B_edge_pos.init("Down", false, this->id_pos_down);
        this->position.position[LayoutPosition_cross::id_pos_down]=&B_edge_pos;

        C_edge_pos.init("Left", false, this->id_pos_left);
        this->position.position[LayoutPosition_cross::id_pos_left]=&C_edge_pos;

        D_edge_pos.init("Up", false, this->id_pos_up);
        this->position.position[LayoutPosition_cross::id_pos_up]=&D_edge_pos;
        
        E_edge_pos.init("Down right", false, this->id_pos_down_right);
        this->position.position[LayoutPosition_star::id_pos_down_right]=&E_edge_pos;

        F_edge_pos.init("Down left", false, this->id_pos_down_left);
        this->position.position[LayoutPosition_star::id_pos_down_left]=&F_edge_pos;

        G_edge_pos.init("Up left", false, this->id_pos_up_left);
        this->position.position[LayoutPosition_star::id_pos_up_left]=&G_edge_pos;

        H_edge_pos.init("Up right", false, this->id_pos_up_right);
        this->position.position[LayoutPosition_star::id_pos_up_right]=&H_edge_pos;
        break;
        
    default:
        while(1){
            Serial.println("ERRORE");
            delay(1000);
        }
        break;
    }
} 
 