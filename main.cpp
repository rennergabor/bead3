/*
Feladat: Osszuk fel a 400*400-as képernyõt 20*20-as mezõkre,
amelyek kezdetben feketék. Fekete mezõre kattintva az fehérre
vált, fehérre kattintva pedig feketére.
*/

#include <graphics.hpp>
#include <vector>
using namespace genv;
using namespace std;


// rajzolást végrehajtó mûvelet
void rajzol(vector<vector<bool> > tabla, bool kijatszik);
// értékváltoztató mûvelet
void valtoztat(vector<vector<bool> > &tabla, int x, int y);

int main() {
    bool kijatszik=true;

    vector<vector<bool> > tabla(20); // mátrix
    for (unsigned int i = 0; i < tabla.size(); i++)
        // elõjezeletlen int a futóindex a size miatt
    {
        tabla[i].resize(20); // mátrix sorainak méretezése
        for (unsigned int j = 0; j < tabla[i].size(); j++)
            tabla[i][j] = false; // kezdõérték legyen hamis (fekete)
    }
    gout.open(400,400);
    event ev;
    while (gin >> ev) {
        rajzol(tabla, kijatszik);

        if (ev.type == ev_mouse && ev.button == btn_left)
            // bal egérgombbal kattintottunk
        {
            kijatszik=!kijatszik;
            valtoztat(tabla, ev.pos_x, ev.pos_y);
        }
    }


    return 0;
}

void rajzol(vector<vector<bool> > tabla, bool kijatszik) {
    for (unsigned int i = 0; i < tabla.size(); i++) {
        for (unsigned int j = 0; j < tabla[i].size(); j++) {

            gout << move_to(i*20, j*20);
            if (tabla[i][j]) {
                if (kijatszik==true) {
                    gout << color(255,25,255);
                } else
                    gout << color(255,255,25);
            } else gout << color(0,34,0);
            gout << box(19,19);



        }
    }
    gout << refresh;
}

void valtoztat(vector<vector<bool> > &tabla, int x, int y) {
    tabla[x / 20][y / 20] = !tabla[x / 20][y / 20];
    // érték változtatása az ellentettre
}
