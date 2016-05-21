#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "clickButton.hpp"
#include "statictext.hpp"
#include "amobaapplication.hpp"
#include "resultwindow.hpp"
#include <vector>
#include <iostream>

using namespace std;

ResultWindow::ResultWindow(AmobaApplication &app, int x, int y) : Window (x, y), _app(app){
    StaticText *amoba = new StaticText(170, 50, 100, 30, "Amöba");
    widgets.push_back(amoba);

    StaticText *nyero1 = new StaticText(130, 120, 100, 30, "Gratulálok");
    widgets.push_back(nyero1);

    StaticText *nyero3 = new StaticText(130, 140, 100, 30, _app.players[_app.activePlayer]);
    widgets.push_back(nyero3);

    StaticText *nyero2 = new StaticText(130, 160, 100, 30, "nyert!");
    widgets.push_back(nyero2);

    ClickButton *kilepesGomb = new ClickButton([&]() {kilepesClicked();}, 40, 320, 100, 35);
    widgets.push_back(kilepesGomb);

    StaticText *exit = new StaticText(70, 330, 40, 20, "EXIT");
    widgets.push_back(exit);

    ClickButton *jatekGomb = new ClickButton([&]() { jatekClicked(); }, 260, 320, 100, 35);
    widgets.push_back(jatekGomb);

    StaticText *visszavago = new StaticText(270, 330, 40, 20, "VISSZAVÁGÓ");
    widgets.push_back(visszavago);
}

void ResultWindow::kilepesClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(KILEPES);
}

void ResultWindow::jatekClicked() {
    cout << "play clicked!" << endl;
    exit_event_loop();
    _app.changeState(JATEK);
}

