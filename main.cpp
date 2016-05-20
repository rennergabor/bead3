#include <graphics.hpp>
#include <vector>
using namespace genv;
using namespace std;



void rajzol(vector<vector<bool> > tabla, bool kijatszik);

void valtoztat(vector<vector<bool> > &tabla, int x, int y);

int main() {
    bool kijatszik=true;

    vector<vector<bool> > tabla(40);
    for (unsigned int i = 0; i < tabla.size(); i++)

    {
        tabla[i].resize(40);
        for (unsigned int j = 0; j < tabla[i].size(); j++)
            tabla[i][j] = false;
    }
    gout.open(400,400);
    event ev;
    while (gin >> ev) {
        rajzol(tabla, kijatszik);

        if (ev.type == ev_mouse && ev.button == btn_left)

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

            gout << move_to(i*10, j*10);
            if (tabla[i][j]) {
                if (kijatszik==true) {
                    gout << color(255,25,255);
                } else
                    gout << color(255,255,25);
            } else gout << color(0,234,0);
            gout << box(9,9);

        }
    }
    gout << refresh;
}

void valtoztat(vector<vector<bool> > &tabla, int x, int y) {
    tabla[x / 10][y / 10] = !tabla[x / 10][y / 10];

}
