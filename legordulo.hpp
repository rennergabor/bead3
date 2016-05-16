#ifndef LEGORDULO_HPP_INCLUDED
#define LEGORDULO_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "pushbutton.hpp"
#include "statictext.hpp"
#include <vector>

using namespace std;

enum Allapot { ALAP, LEGORDULT };

const unsigned int SOROK_SZAMA = 3;
class KivalaszthatoText;

class Legordulo : public Widget {
private:
    PushButton* _down;
    StaticText* _text;
    vector<KivalaszthatoText*> _szovegek;
    int _sorokSzama,_sormagagassag;
protected:
    Allapot _allapot;
    int _kivalasztott;
    vector<string> _valasztek;
    void unfocus();
    bool is_selected(int mouse_x, int mouse_y) const;
    int _showFrom;
    void showSzovegek();
public:
    Legordulo( vector<string> valasztek, int x, int y, int sx, int sy);
    void hozzaAd(string uj) {_valasztek.push_back(uj);};

    virtual void draw() const;
    virtual void handle(genv::event ev);
    inline bool focusable() const {return true;};
    inline string value(){ return _valasztek[_kivalasztott];};
    virtual void downClicked();
};


class LegorduloButton : public PushButton {
private:
    Legordulo * _legordulo;
    void buttonClicked(){_legordulo->downClicked();};
public:
    LegorduloButton(Legordulo *l, int x, int y, int sx, int sy) : PushButton (DOWN, x, y, sx, sy), _legordulo(l) {};
};

#endif // LEGORDULO_HPP_INCLUDED
