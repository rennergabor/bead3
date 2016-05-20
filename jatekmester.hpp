#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include <string>

using namespace std;

class Mezo {
public:
    int _player, _i, _j;
    Mezo(int p, int i, int j): _player(p), _i(i), _j(j){}
};

enum LepesEredmeny {LEPES_OK=1, HIBAS_LEPES, NYERT, DONTETLEN};

class JatekMester {
public:
    LepesEredmeny lepes(Mezo *mezore);
};
#endif // JATEKMESTER_HPP_INCLUDED
