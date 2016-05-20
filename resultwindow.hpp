#ifndef RESULTWINDOW_HPP_INCLUDED
#define RESULTWINDOW_HPP_INCLUDED

#include "window.hpp"
#include "amobaapplication.hpp"


class ResultWindow : public Window {
private:
    AmobaApplication &_app;
protected:
    void kilepesClicked();

public:
    ResultWindow(AmobaApplication &app, int x, int y);
};

#endif // RESULTWINDOW_HPP_INCLUDED
