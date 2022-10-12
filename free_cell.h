#ifndef __FREE_CELL_H__
#define __FREE_CELL_H__

#include "piles.h"


/*
    subclass for free pile 
    overriden addback method
*/

class Free_Cell : public Piles {
    public:
        Free_Cell(): Piles(){};
        Free_Cell(std::vector<std::string> & v) : Piles(v){};
        Free_Cell(Piles& p) : Piles(p){};
        Free_Cell(Free_Cell& t) : Piles(t){};
        bool addBack(std::string s);
};


#endif