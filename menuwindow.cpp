#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "clickButton.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "amobaapplication.hpp"
#include "menuwindow.hpp"
#include "legordulo.hpp"

#include <vector>
#include <iostream>

using namespace std;

MenuWindow::MenuWindow(AmobaApplication &app, int x, int y) : Window (x, y), _app(app) {
    StaticText *text = new StaticText(170, 30, 100,30, "Amöba");
    widgets.push_back(text);

    ClickButton *kilepesGomb = new ClickButton([&]() { kilepesClicked(); }, 40, 320, 100, 35);
    widgets.push_back(kilepesGomb);

    StaticText *exit = new StaticText(70, 330, 40, 20, "EXIT");
    widgets.push_back(exit);

    ClickButton *jatekGomb = new ClickButton([&]() { jatekClicked(); }, 260, 320, 100, 35);
    widgets.push_back(jatekGomb);

    StaticText *play = new StaticText(290, 330, 40, 20, "PLAY");
    widgets.push_back(play);

    StaticText *kek = new StaticText(40, 230, 100, 35, "Kék játékos:");
    widgets.push_back(kek);

    TextEditor *kekJatekos = new TextEditor (40, 250, 100, 35, "");
    widgets.push_back(kekJatekos);

    StaticText *piros = new StaticText(260, 230, 100, 35, "Piros játékos:");
    widgets.push_back(piros);

    TextEditor *pirosJatekos = new TextEditor (260, 250, 100, 35, "");
    widgets.push_back(pirosJatekos);

    StaticText *meret = new StaticText(130, 100, 100, 35, "Pálya mérete:");
    widgets.push_back(meret);

    vector<string> v1 = {"40 x 40", "20 x 20" };
    Legordulo *palyaMeret = new Legordulo (v1, 130, 120, 140, 35);
    widgets.push_back(palyaMeret);
}

void MenuWindow::kilepesClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(KILEPES);
}
void MenuWindow::jatekClicked() {
    cout << "play clicked!" << endl;
    exit_event_loop();
    _app.changeState(JATEK);
}

