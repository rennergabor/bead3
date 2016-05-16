#include "szambeallito.hpp"
#include "graphics.hpp"

#include "iostream"
#include <sstream>

using namespace genv;

Szambeallito::Szambeallito(int kezdoErtek,int alsoKorlat,int felsoKorlat,int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy) {
    _val = kezdoErtek;
    _alsoK = alsoKorlat;
    _felsoK= felsoKorlat;

    _up = new UpButton(this, x+sx-sy/2, y, sy/2, sy/2);
    _down = new DownButton(this, x+sx-sy/2, y+sy/2, sy/2, sy/2);

    _text = new StaticText(x+2, y+2, sx-sy/2-4, sy-4, "");
    updateStaticText();
}

void Szambeallito::updateStaticText() {
    std::ostringstream convert;
    convert << _val;
    _text->setText(convert.str());
}

void Szambeallito::upClicked() {
    if (_val < _felsoK){
        _val++;
        updateStaticText();
    }
}

void Szambeallito::downClicked() {
    if (_val> _alsoK) {
        _val--;
        updateStaticText();
    }
}

void Szambeallito::draw() const {
    int r, g, b;
    if (_focused) {
        r = g = b = 255;
    } else {
        r = g = b = 155;
    }
    gout  << color(r, g, b);
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout  << color(r, g, b);
    _up->draw();

    gout  << color(r, g, b);
    _down->draw();

    gout  << color(r, g, b);
    _text->draw();

}

void Szambeallito::handle(event ev) {
    if(ev.type == ev_mouse && ev.button==btn_left){
        _up->handle(ev);
        _down->handle(ev);
    }
    if (ev.type == ev_key) {
        switch (ev.keycode) {
            case key_up:    upClicked();
                break;
            case key_down: downClicked();
                break;
            case key_pgup: upClicked();
                break;
            case key_pgdn: downClicked();
                break;
        }
    }
}

