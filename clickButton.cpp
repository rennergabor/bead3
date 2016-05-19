#include "clickButton.hpp"
#include "widgets.hpp"

using namespace genv;

void ClickButton::draw() const {
    gout << move_to(_x, _y) << color(150,150,150) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

}

void ClickButton::handle(genv::event ev) {
    if (ev.type == ev_mouse && ev.button==btn_left && is_selected(ev.pos_x, ev.pos_y)) {
        _clickFunction();
    }
}
