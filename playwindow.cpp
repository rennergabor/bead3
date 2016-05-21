#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "clickButton.hpp"
#include "statictext.hpp"
#include "amobaapplication.hpp"
#include "playwindow.hpp"
#include "palya.hpp"

#include <vector>
#include <iostream>

using namespace std;

PlayWindow::PlayWindow(AmobaApplication &app, int x, int y) : Window (x, y), _app(app) {

    _player = new StaticText(170, 10, 100, 30, _app.players[_app.activePlayer]);
    widgets.push_back(_player);

    ClickButton *visszaGomb = new ClickButton([&]() {visszaClicked();}, 40, 10, 100, 35);
    widgets.push_back(visszaGomb);

    StaticText *exit = new StaticText(65, 20, 40, 20, "VISSZA");
    widgets.push_back(exit);

    Palya *palya = new Palya(*this, 0, 50, x-10, x-10);
    widgets.push_back(palya);

}

void PlayWindow::visszaClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(MENU);
}

void PlayWindow::changeActivePlayer() {
    _app.changeActivePlayer();
    _player->setText(_app.players[_app.activePlayer]);
}

int PlayWindow::getActivePlayerId(){
    return _app.activePlayer;
}

void PlayWindow::nyert(){
    exit_event_loop();
    _app.changeState(EREDMENY);
}
