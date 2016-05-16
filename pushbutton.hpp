#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"

enum ButtonStyle {UP, DOWN};

class PushButton : public Widget {
protected:
    ButtonStyle _stilus;
    virtual void buttonClicked();

public:
    inline PushButton(ButtonStyle stilus, int x, int y, int sx, int sy) : Widget(x,y,sx,sy), _stilus(stilus) {};
    virtual void draw() const ;
    virtual void handle(genv::event ev);
};

#endif // PUSHBUTTON_HPP_INCLUDED
