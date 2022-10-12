#include "free_cell.h"

bool Free_Cell::addBack(std::string s){
    if (this->checkEmpty()) return Piles::addBack(s);
    return false;
}