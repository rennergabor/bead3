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

    StaticText *text = new StaticText(170, 30, 100, 30, "Amöba");
    widgets.push_back(text);

    ClickButton *visszaGomb = new ClickButton([&]() {visszaClicked();}, 40, 30, 100, 35);
    widgets.push_back(visszaGomb);

    StaticText *exit = new StaticText(65, 40, 40, 20, "VISSZA");
    widgets.push_back(exit);

    Palya *palya = new Palya(*this, 0, 50, x-10, y-60);
    widgets.push_back(palya);

}

void PlayWindow::visszaClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(MENU);
}

void PlayWindow::changeActivePlayer() {
    _app.changeActivePlayer();
}

int PlayWindow::getActivePlayerId(){
    return _app.activePlayer;
}

void PlayWindow::nyert(){
    exit_event_loop();
    _app.changeState(EREDMENY);
}
