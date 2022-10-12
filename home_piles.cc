#include "home_piles.h"

bool Home_piles::addBack(std::string s){
    if (this->checkEmpty() && this->getDigit(s) == 1) {
        return Piles::addBack(s);
    } else if (
        (this->getSuit(s) == this->getSuit(this->getLast()))
        &&
        (this->getDigit(s) - this->getDigit(this->getLast()) == 1)
        &&
        (this->getColor(s) == this->getColor(this->getLast()))
    ){
        return Piles::addBack(s);
    } else {
        return false;
    }
}

void Home_piles::print(std::ostream& out) const {
    out << this->getLast();
}