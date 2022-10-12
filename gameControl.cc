#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "piles.h"
#include "tableau_piles.h"
#include "free_cell.h"
#include "home_piles.h"


using namespace std;

// overriden operator<<
std::ostream& operator<<(std::ostream& out, const Piles& p) {
    p.print(out);
    return out;
}

//print a vector of piles
void printVector(const std::vector<Piles*>& piles) {
    if (piles.size() == 16){
        std::cout << "<Free cells>" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "   #" << i << ":" 
            << "[ " << *piles[i] << "]";
        }
        std::cout << "\n<Home piles>" << std::endl;
        for (int i = 4; i < 8; i++) {
            std::cout << "   #" << i << ":" 
            << "[ " << *piles[i] << "]";
        }
        std::cout << "\n<Tableau piles>" << std::endl;
        for (int i = 8; i < piles.size(); i++) {
            std::cout << "   #" << i << ":" 
            << "[ " << *piles[i] << "]" << std::endl;
        }
    } else {
        for (int i = 0; i < piles.size(); i++) {
            std::cout << "   #" << i << ":" 
            << "[ " << *piles[i] << "]" << std::endl;
        }
    }
}

/*
    card generator
    return a vector pf piles for gameControler method
*/
std::vector<Piles*> cardGenerator(){
    string pflo[4] = {"C","D","H","S"};
    string pnum[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    std::vector<string> poker;
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
            if (pflo[j] == "C"|| pflo[j] == "S"){
                poker.push_back(pnum[i] + pflo[j] + "-");
            } else {
                poker.push_back(pnum[i] + pflo[j] + "+");
            }
        }
    }
    
    //shuffle the vector
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    shuffle(poker.begin(), poker.end(), std::default_random_engine(seed));
    
    //adding the piles to vector
    std::vector<Piles*> piles;
    for (int i = 0; i < 4; i++){
        piles.push_back(new Free_Cell());
    }
    for (int i = 0; i < 4; i++){
        piles.push_back(new Home_piles());
    }
    for (int i = 0; i < 8; i++){
        piles.push_back(new Tableau_piles());
    }
    for (int i = 8; i < 12; i++){
        for(int j = 0; j < 7; j++){
            piles.at(i)->Piles::addBack(poker.back());
            poker.pop_back();
        }
    }
    for (int i = 12; i < 16; i++){
        for(int j = 0; j < 6; j++){
            piles.at(i)->Piles::addBack(poker.back());
            poker.pop_back();
        }
    }
    return piles;
}

// game Controler
void gameControler(std::vector<Piles*> &piles, string input_Op){
    int num_from;
    int num_to;
    int pointer = 0;
    //check input string available
    if (!isdigit(input_Op[0])) return;
    // update nums
    for(int i = 0; i < input_Op.size(); i++){
        while(i < input_Op.size() - 1 && isdigit(input_Op[i])){
            i++;
        }
        if (pointer == 0){
            num_from = stoi(input_Op.substr(pointer, i));
            pointer = i + 1;
        } else {
            num_to = stoi(input_Op.substr(pointer, i)); 
        }
    }
    if (num_from < 0 || num_from > 15 || num_to < 0 || num_to > 15) return;
    if (piles.at(num_to)->addBack(piles.at(num_from)->getLast())){
        piles.at(num_from)->removeLast();
    } 
}

// detect the game is finished
bool isWin(std::vector<Piles*> &piles){
    for (int i = 4; i < 8; i++){
        if (piles.at(i)->getVector().size() != 13){
            return false;
        }
    }
    return true;
}


/*
    main function
    the test play went well
*/
int main() {
    std::vector<Piles*> piles = cardGenerator();
    string str = "";

    while (true){
        system("clear");
        gameControler(piles, str);
        printVector(piles);
        if (isWin(piles)) break; 
        cout << "" << endl;
        cout << "Enter your move (e.g. '8 0' to move a card from pile #8 to pile #0):";
        getline(cin, str);
    }

    cout << "You Win" << endl;
    system("pause");
}