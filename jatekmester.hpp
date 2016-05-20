#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Mezo {
    int _player, _i, _j;
public:
    Mezo(int p, int i, int j): _player(p), _i(i), _j(j){}
};

enum Irany {ED, KNY, EK, ENY};  // �szak-D�l, Kelet-Nyugat, �szak-Kelet, �szak-nyugat

class Vonal {
    Irany _irany;
    vector<Mezo*> mezok;
public:
    Vonal(Mezo *m1, Mezo* m2);  // ha nem szomszedosak, akkor ....
    bool addMezo(Mezo *m);      // false, ha nem esik egybe a jelenlegiekkel
};

enum LepesEredmeny {LEPES_OK=1, HIBAS_LEPES, NYERT, DONTETLEN};

class JatekMester {
//    private <vector<>>[2] =
public:
    LepesEredmeny lepes(Mezo *mezore);
};

#endif // JATEKMESTER_HPP_INCLUDED
