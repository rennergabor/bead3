#include "legordulo.hpp"
#include "graphics.hpp"
#include "pushbutton.hpp"
#include "statictext.hpp"
#include "algorithm"

#include "iostream"
#include <sstream>
using namespace genv;

const color feher = color(255,255,255);
const color fekete = color(0,0,0);

class KivalaszthatoText : public StaticText {
private:
    color betu, hatter;
public:
    KivalaszthatoText(int x, int y, int sx, int sy, string txt) : StaticText (x,y,sx,sy, txt), betu(feher), hatter(fekete) {};
    KivalaszthatoText(string txt) : StaticText (0,0,0,0, txt), betu(feher), hatter(fekete) {};
    void inverz() {
        betu = fekete;
        hatter = feher;
    };
    void alap() {
        betu = feher;
        hatter = fekete;
    };
    void draw() const {
        gout << hatter << move_to(_x, _y) << box(_size_x, _size_y);
        gout << move_to(_x,_y+gout.cascent()) << color(betu) << text(_s);
    }
};

Legordulo::Legordulo( vector<string> valasztek,int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy) {
    _valasztek = valasztek;
    _kivalasztott=-1;
    _sorokSzama = std::min(SOROK_SZAMA, _valasztek.size());
    _sormagagassag= gout.cascent() + gout.cdescent();

    _down = new LegorduloButton(this, x+sx-sy, y, sy, sy);
    _showFrom = 0;
}

void Legordulo::draw() const {
    int r, g, b;
    if (_focused) {
        r = g = b = 255;
    } else {
        r = g = b = 155;
    }
    gout << color(r, g, b);
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout  << color(r, g, b);
    _down->draw();

    if(_text) {
        _text->draw();
    }

    if(_allapot == LEGORDULT) {
        gout  << color(r, g, b);
        gout << move_to(_x, _y+_size_y) << box(_size_x, 4 + _sorokSzama * _sormagagassag);
        gout << move_to(_x+2, _y+_size_y+2) << color(0,0,0) << box(_size_x-4, _sorokSzama * _sormagagassag -4);

        gout  << color(r, g, b);
        for(int i=0; i<_sorokSzama; i++) {
            _szovegek[i]->draw();
        }
    }
}

bool Legordulo::is_selected(int mouse_x, int mouse_y) const {
    if(_allapot == LEGORDULT) {
        bool selected = (mouse_x > _x) && (mouse_x < _x + _size_x)
                     && (mouse_y > _y) && (mouse_y < _y + _size_y + _sorokSzama * _sormagagassag);
//        cout << "selected=" << selected;
        return selected;
    }
    return Widget::is_selected(mouse_x, mouse_y);
}


void Legordulo::handle(event ev) {
    if(_down->is_selected(ev.pos_x, ev.pos_y)){
        _down->handle(ev);
    }

    if(_allapot == LEGORDULT) {
        if(ev.type == ev_mouse) {
            int kivalasztott = -1;
            // ha az eger mozog
            for(int i=0; i<_sorokSzama; i++) {
                if(_szovegek[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    _szovegek[i]->inverz();
                    kivalasztott = i;
                } else {
                    _szovegek[i]->alap();
                }
            }
            if( ev.button == btn_left ) {
                if(kivalasztott != -1) {
                    _kivalasztott = kivalasztott + _showFrom;
                    _text = new StaticText(_x+2, _y+2, _size_x-_size_y-4, _size_y-4, _valasztek[_kivalasztott]);
                    _allapot = ALAP;
                }
            }
            if( ev.button == btn_wheeldown) {
                _showFrom++; //cout << "key_down _showFrom=" << _showFrom << '\n';
                showSzovegek();
            }
            if( ev.button == btn_wheelup) {
                _showFrom--; //cout << "key_down _showFrom=" << _showFrom << '\n';
                showSzovegek();
            }
        }
    }
}

void Legordulo::showSzovegek(){
    int firstToShow = _valasztek.size() - _sorokSzama;
    if(_kivalasztott > firstToShow || _showFrom > firstToShow ) {
        _showFrom = firstToShow;
    }
    if (_showFrom < 0) {
        _showFrom = 0;
    }
    _szovegek.clear();
    for(int i=0; i<_sorokSzama; i++) {
        _szovegek.push_back( new KivalaszthatoText(_x+2, _y+_size_y + (i * _sormagagassag), _size_x -4, _sormagagassag,
                                                   _valasztek[_showFrom + i] ));
    }
}

void Legordulo::downClicked() {
    if(_allapot == ALAP) {
        _allapot = LEGORDULT;
        showSzovegek();
    }
}

void Legordulo::unfocus() {
    _allapot = ALAP;
    Widget::unfocus();
}

