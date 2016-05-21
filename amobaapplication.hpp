#ifndef AMOBAAPPLICATION_HPP_INCLUDED
#define AMOBAAPPLICATION_HPP_INCLUDED

#include <iostream>

using namespace std;

enum Allapot {MENU, JATEK, EREDMENY, KILEPES};

class AmobaApplication {
private:
    Allapot _allapot = Allapot::MENU;

public:
    string player1, player2;
    string players [2] = {player1, player2};
    int activePlayer;
    inline void changeActivePlayer(){activePlayer = 1 - activePlayer;};
    int run();
    inline void changeState(Allapot a) {_allapot = a;};
};

#endif // AMOBAAPPLICATION_HPP_INCLUDED
