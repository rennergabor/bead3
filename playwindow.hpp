#ifndef PLAYWINDOW_HPP_INCLUDED
#define PLAYWINDOW_HPP_INCLUDED

#include "window.hpp"
#include "amobaapplication.hpp"

class PlayWindow : public Window {
private:
    AmobaApplication &_app;
protected:
    void visszaClicked();
public:
    PlayWindow(AmobaApplication &app, int x, int y);
    int getActivePlayerId();
    void changeActivePlayer();
    void nyert();
};


#endif // PLAYWINDOW_HPP_INCLUDED
