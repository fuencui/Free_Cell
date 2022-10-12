#ifndef __PILES_H__
#define __PILES_H__

#include <iostream>
#include <string>
#include <vector>


/*
    Define a base class for any type pf a pile of cards
    include basic function like get/set, print, etc
*/
class Piles
{
private:
    std::vector<std::string> card_vector_;
    bool isEmpty;
public:
    Piles(){
        this->card_vector_.clear();
        this->isEmpty = true;
    }

    Piles(std::vector<std::string> & v) : card_vector_(v){
        if (v.size() > 0) this->isEmpty = false;
    };

    Piles(Piles& p){
        this->card_vector_ = p.getVector();
        if (p.getVector().size() > 0) this->isEmpty = false;
    };

    virtual ~Piles(){
        this->card_vector_.clear();
    }
    
    virtual bool addBack(std::string s){
        this->card_vector_.push_back(s);
        this->isEmpty = false;
        return true;
    }

    virtual std::string getLast() const{
        if (this->card_vector_.size() != 0){
            return this->card_vector_.back();
        }
        return "";
    }

    virtual bool removeLast(){
        if (this->card_vector_.size() != 0){
            this->card_vector_.pop_back();
            if (this->card_vector_.size() == 0) {
                this->isEmpty = true;
            }
            return true;
        }
        return false;
    }

    virtual int getDigit(std::string s){
        if (s[0] == 'A') return 1;
        if (s[0] == 'J') return 11;
        if (s[0] == 'Q') return 12;
        if (s[0] == 'K') return 13;
        std::string str;
        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i])){
                return std::stoi(str);
            }
            str.push_back(s[i]);
        }
        return 0;
    }

    virtual char getSuit(std::string s){
        for (int i = s.size() - 1; i > 0; i--) {
            if (isalpha(s[i])){
                return s[i];
            }
        }
        return 'n';
    }

    virtual char getColor(std::string s){
        return s.back();
    }

    std::vector<std::string> getVector() const {
        return this->card_vector_;
    }

    virtual void print(std::ostream& out) const {
        for (int i = 0; i < this->card_vector_.size(); i++){
            out << this->card_vector_.at(i);
        }
    }

    bool checkEmpty(){
        return this->isEmpty;
    }
};



#endif 