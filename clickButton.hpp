#ifndef CLICKBUTTON_HPP_INCLUDED
#define CLICKBUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include <functional>

// typedef std::function<void()> ClickHandler;

class ClickButton : public Widget {
private:
    std::function<void()> _clickFunction;

public:
    inline ClickButton(std::function<void()> myFunction, int x, int y, int sx, int sy) : Widget(x,y,sx,sy), _clickFunction(myFunction) {};
    virtual void draw() const ;
    virtual void handle(genv::event ev);
};

#endif // CLICKBUTTON_HPP_INCLUDED
