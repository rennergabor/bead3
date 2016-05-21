#include "jatekmester.hpp"
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

LepesEredmeny JatekMester::lepes(Mezo *mezo){
    // befejezni!!!!
    if(find(_lepesek.begin(), _lepesek.end(), mezo) != _lepesek.end()) {
        // már benne van
        return HIBAS_LEPES;
    }
    // else
    _lepesek.push_back(mezo);
    return LEPES_OK;
}

vector<Mezo*> JatekMester::getLepesek(){
    return _lepesek;
}
