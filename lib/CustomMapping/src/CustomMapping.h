#ifndef CUSTOM_MAPPING_H_
#define CUSTOM_MAPPING_H_

#include "Handler.h"


class CustomMapping{

  public:
    CustomMapping();

    LayoutPosition_cross layoutPosition_cross;
    LayoutPosition_star layoutPosition_star;

    Handler_position* Mapping_F1F2F3F4;
/*    Handler_position* Mapping_youtube;

    Handler_position* Mapping_browserF1F2F3F4;
    Handler_position* Mapping_audio;
    Handler_position* Mapping_muose;
*/
    
};

extern CustomMapping GlobalCustomMapping;
#endif /*CUSTOM_MAPPING_H_*/
