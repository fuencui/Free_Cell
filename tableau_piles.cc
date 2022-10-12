#include "tableau_piles.h"


bool Tableau_piles::addBack(std::string s){
    if (this->checkEmpty()) return Piles::addBack(s);
    if (this->getColor(s) == this->getColor(this->getLast())){
        return false;
    } else if (this->getSuit(s) == this->getSuit(this->getLast())){
        return false;
    } else if ((this->getDigit(this->getLast()) - this->getDigit(s)) != 1){
        return false;
    } else {
        return Piles::addBack(s); 
    }
}

void Tableau_piles::print(std::ostream& out) const {
    for (int i = 0; i < this->getVector().size(); i++){
        out << this->getVector().at(i) << "  ";
    }
}