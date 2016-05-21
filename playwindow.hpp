#ifndef PLAYWINDOW_HPP_INCLUDED
#define PLAYWINDOW_HPP_INCLUDED

#include "window.hpp"
#include "statictext.hpp"
#include "amobaapplication.hpp"

class PlayWindow : public Window {
private:
    StaticText *_player;
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
