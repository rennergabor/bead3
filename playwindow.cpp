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
    StaticText *text = new StaticText(150, 30, 100,30, "Játék");
    widgets.push_back(text);

    ClickButton *kilepesGomb = new ClickButton([&]() { kilepesClicked(); }, 10, 30, 30, 30);
    widgets.push_back(kilepesGomb);

    Palya *palya = new Palya(*this, 0, 50, 450, 450);
    widgets.push_back(palya);

}


void PlayWindow::kilepesClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(MENU);
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
