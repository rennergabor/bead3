#ifndef MENUWINDOW_HPP_INCLUDED
#define MENUWINDOW_HPP_INCLUDED

#include "window.hpp"
#include "amobaapplication.hpp"

class MenuWindow : public Window {
private:
    AmobaApplication &_app;
protected:
    void kilepesClicked();
    void jatekClicked();
    void textEditorChanged(ValueChangedEvent event);
    void textEditorChanged2(ValueChangedEvent event);

public:
    MenuWindow(AmobaApplication &app, int x, int y);
};


#endif // MENUWINDOW_HPP_INCLUDED
