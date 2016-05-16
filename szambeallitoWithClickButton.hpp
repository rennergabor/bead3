#ifndef SzambeallitoWithClickButton_HPP_INCLUDED
#define SzambeallitoWithClickButton_HPP_INCLUDED

#include "clickButton.hpp"
#include "statictext.hpp"

class SzambeallitoWithClickButton : public Widget {
private:
    ClickButton* _up;
    ClickButton* _down;
    StaticText* _text;

protected:
    int _val;
    int _alsoK;
    int _felsoK;
    void updateStaticText();

public:
    SzambeallitoWithClickButton(int kezdoErtek,int alsoKorlat,int felsoKorlat,int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    inline bool focusable() const { return true;};
    inline int value() { return _val; };

    virtual void upClicked();
    virtual void downClicked();
};

#endif // SzambeallitoWithClickButton_HPP_INCLUDED
