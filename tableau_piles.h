#ifndef __TABLEAU_PILES_H__
#define __TABLEAU_PILES_H__

#include "piles.h"

/*
    subclass for tableau pile 
    overriden addback and print method(only different from it's base class in this design)

*/
class Tableau_piles : public Piles {
    public:
        Tableau_piles(): Piles(){};
        Tableau_piles(std::vector<std::string> & v) : Piles(v){};
        Tableau_piles(Piles& p) : Piles(p){};
        Tableau_piles(Tableau_piles& t) : Piles(t){};
        bool addBack(std::string s);
        virtual void print(std::ostream& out) const;
};



#endif