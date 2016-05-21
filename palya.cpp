#include "palya.hpp"
#include "jatekmester.hpp"
#include "widgets.hpp"
#include "amobaapplication.hpp"
#include "playwindow.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace genv;

const int palya_meret = 40;

Palya::Palya(PlayWindow& win, int x, int y, int sx, int sy) : Widget(x, y, sx, sy), _win(win) {
    _mester = new JatekMester(palya_meret);
}

void Palya::handle(event ev) {
    if (ev.type == ev_mouse && ev.button==btn_left) {

        int mezoMeret = _size_x / palya_meret;
        Mezo *m = new Mezo(_win.getActivePlayerId(), ev.pos_x / mezoMeret, ev.pos_y / mezoMeret);

        // jatekmester lepes ellenorzes
        LepesEredmeny eredmeny = _mester->lepes(m);

        if (eredmeny != HIBAS_LEPES) {
            if (eredmeny == LEPES_OK) {
                _win.changeActivePlayer();
            } else if (eredmeny == NYERT) {
                _win.nyert();
            } else if (eredmeny == DONTETLEN) {
                // TODO....
//                _win.exit_event_loop();
            }
        } else {
            // nem váltjuk a jatekost, de nem is fogadjuk el a lepest!
        }
    }

}

const color player_szinek[2] = {color(0,255,255), color(255,255,0)};

void Palya::draw() const {
    // TODO palyat kirajzolni, és az eddigi lepeseket (_lepesek) a megfelelõ szinnel
    int mezoMeret = _size_x / palya_meret;

    gout<<move_to(_x, _y)<<color(122,121,76)<<box_to(palya_meret * mezoMeret, palya_meret * mezoMeret);
    gout<<color(0,0,0);
    for (int i=_x; i < _size_x; i = i+mezoMeret ) {
        gout<<move_to(_x, i)<<line_to(_size_x, i);
    }
    for (int j=_y; j < _size_x; j+=mezoMeret ) {
        gout<<move_to(j, _y)<<line_to(j, _size_y);
    }

    for(int i=0; i < _mester->getLepesek().size(); i++){
        Mezo *m = _mester->getLepesek()[i];
        gout << move_to(mezoMeret * m->_i, mezoMeret * m->_j);
        gout << color( player_szinek[m->_player]);
        gout << box(mezoMeret, mezoMeret);
    }
}
