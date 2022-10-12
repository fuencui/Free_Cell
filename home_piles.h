#ifndef __HOME_PILES_H__
#define __HOME_PILES_H__

#include "piles.h"


/*
    subclass for home pile 
    overriden addback and print method(only different from it's base class in this design)
*/
class Home_piles : public Piles {
    public:
        Home_piles(): Piles(){};
        bool addBack(std::string s);
        void print(std::ostream& out) const;
};


#endif