#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDED

#include "pushbutton.hpp"
#include "statictext.hpp"

// forward declaration:
class UpButton;
class DownButton;

class Szambeallito : public Widget {
private:
    UpButton* _up;
    DownButton* _down;
    StaticText* _text;

protected:
    int _val;
    int _alsoK;
    int _felsoK;
    void updateStaticText();

public:
    Szambeallito(int kezdoErtek,int alsoKorlat,int felsoKorlat,int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    inline bool focusable() const { return true;};
    inline int value() { return _val; };

    virtual void upClicked();
    virtual void downClicked();
};


class UpButton : public PushButton {
protected:
    Szambeallito *_sz;
    void buttonClicked(){_sz->upClicked();};
public:
    inline UpButton(Szambeallito *sz2, int x, int y, int sx, int sy) : PushButton (UP, x, y, sx, sy), _sz(sz2){};
};

class DownButton : public PushButton {
protected:
    Szambeallito *_sz;
    void buttonClicked(){ _sz->downClicked(); };
public:
    inline DownButton(Szambeallito *sz2,int x, int y, int sx, int sy) : PushButton (DOWN, x, y, sx, sy), _sz(sz2){};
};


#endif // SZAMBEALLITO2_HPP_INCLUDED
