#include "palya.hpp"
#include "jatekmester.hpp"
#include "widgets.hpp"
#include "amobaapplication.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace genv;

Palya::Palya(PlayWindow& win, int x, int y, int sx, int sy) : Widget(x, y, sx, sy), _win(win) {
    _mester = new JatekMester();
}

void Palya::handle(event ev) {
    if (ev.type == ev_mouse && ev.button==btn_left) {
        // TODO kikalkulalni, hogy melyik mezore kattintott..
        Mezo *m = new Mezo(_win.getActivePlayerId(), 12, 35);

        LepesEredmeny eredmeny = _mester->lepes(m);
        if (eredmeny != HIBAS_LEPES) {
            _lepesek.push_back(m);
            if (eredmeny == LEPES_OK) {
                _win.changeActivePlayer();
            } else if (eredmeny == NYERT) {
                _win.nyert();
//            } else if (eredmeny == DONTETLEN) {
//                _win.exit_event_loop();
            }
        } else {
            // nem váltjuk a jatekost, de nem is fogadjuk el a lepest!
        }
    }

}

void Palya::draw() const {
    // TODO palyat kirajzolni, és az eddigi lepeseket (_lepesek) a megfelelõ szinnel

}
