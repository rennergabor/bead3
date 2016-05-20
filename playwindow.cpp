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

    StaticText *text = new StaticText(170, 30, 100,30, "Amöba");
    widgets.push_back(text);

    ClickButton *visszaGomb = new ClickButton([&]() {visszaClicked();}, 40, 50, 100, 35);
    widgets.push_back(visszaGomb);

    StaticText *exit = new StaticText(65, 60, 40, 20, "VISSZA");
    widgets.push_back(exit);

    Palya *palya = new Palya(*this, 0, 50, 450, 450);
    widgets.push_back(palya);

    ClickButton *tovabbGomb = new ClickButton([&]() { tovabbClicked(); }, 260, 320, 100, 35);
    widgets.push_back(tovabbGomb);

}

void PlayWindow::visszaClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(MENU);
}

void PlayWindow::tovabbClicked() {
    cout << "eredmény clicked!" << endl;
}

void PlayWindow::changeActivePlayer() {
    // TODO: _app-ba athívni!!!
}

int PlayWindow::getActivePlayerId(){
    // TODO: _app-ba athívni!!!
}

void PlayWindow::nyert(){
    exit_event_loop();
    _app.changeState(EREDMENY);
}
