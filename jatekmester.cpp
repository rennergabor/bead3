#include "jatekmester.hpp"
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

LepesEredmeny JatekMester::lepes(Mezo *mezo){
    for (Mezo *m :_lepesek) {
        if(*m == *mezo) return HIBAS_LEPES;
    }
    // else
    _lepesek.push_back(mezo);

    // jatek vege ellenorzes
    if(_lepesek.size() == _meret * _meret)
        return DONTETLEN;

    // itt jon a lenyeg, lett-e most evvel 5 hosszu Vonal
    // befejezni

    // egyebkent
    return LEPES_OK;
}

vector<Mezo*> JatekMester::getLepesek(){
    return _lepesek;
}
