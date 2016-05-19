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
    StaticText *text = new StaticText(150, 30, 100,30, "Eredmény...");
    widgets.push_back(text);

    ClickButton *kilepesGomb = new ClickButton([&]() {
        kilepesClicked();
    }, 10, 150, 30, 30);

    widgets.push_back(kilepesGomb);
}

void ResultWindow::kilepesClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
}

