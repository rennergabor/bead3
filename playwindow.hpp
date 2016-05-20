#ifndef PLAYWINDOW_HPP_INCLUDED
#define PLAYWINDOW_HPP_INCLUDED

#include "window.hpp"
#include "amobaapplication.hpp"

class PlayWindow : public Window {
private:
    AmobaApplication &_app;
protected:
    void visszaClicked();
    void tovabbClicked();
public:
    PlayWindow(AmobaApplication &app, int x, int y);
};


#endif // PLAYWINDOW_HPP_INCLUDED
