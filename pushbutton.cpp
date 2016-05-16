#include "pushbutton.hpp"
#include "widgets.hpp"

using namespace genv;

void PushButton::draw() const {
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout << color(155,155,155); //TODO: meg kene tudni valahogy az aktualis rajzolasi szint es azt ken itt beallitani...
    if (_stilus == UP){
        gout << move_to(_x + _size_x/2, _y + _size_y/4) << line_to(_x+_size_x/4, _y + _size_y*3/4);
        gout << move_to(_x + _size_x/2, _y + _size_y/4) << line_to(_x+_size_x*3/4, _y + _size_y*3/4);
    } else { //DOWN
        gout << move_to(_x + _size_x/2, _y + _size_y*3/4) << line_to(_x+_size_x/4, _y + _size_y/4);
        gout << move_to(_x + _size_x/2, _y + _size_y*3/4) << line_to(_x+_size_x*3/4, _y + _size_y/4);
    }
}

void PushButton::handle(genv::event ev) {
    if (ev.type == ev_mouse && ev.button==btn_left && is_selected(ev.pos_x, ev.pos_y)) {
        buttonClicked();
    }
}
