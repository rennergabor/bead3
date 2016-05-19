#include "amobaapplication.hpp"
#include "menuwindow.hpp"
#include "playwindow.hpp"
#include "resultwindow.hpp"

int AmobaApplication::run() {
    bool exit = false;
    while(!exit) {
        if (_allapot == MENU) {
            MenuWindow *w = new MenuWindow(*this, 400, 400);
            w->event_loop();
        }
        if (_allapot == JATEK) {
            PlayWindow *w = new PlayWindow(*this, 400, 400);
            w->event_loop();
        }
        if (_allapot == EREDMENY) {
            ResultWindow *w = new ResultWindow(*this, 400, 400);
            w->event_loop();
        }
        if (_allapot == KILEPES) {
            exit = true;
        }
    }
    return 0;
}


int main() {
    AmobaApplication app;
    app.run();
}
