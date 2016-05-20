#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <functional>

using namespace std;

enum value_change_event_type {ev_type_text=1, ev_type_numeric};

struct ValueChangedEvent {
    value_change_event_type eventType;
    string newValueString;
    int newValueInt;
};

class Widget {
protected:
    bool _focused;
    int _x, _y, _size_x, _size_y;
    function<void(ValueChangedEvent)> _valueChanged;
public:
    Widget(int x, int y, int sx, int sy);
    void addValueChangeListener(function<void(ValueChangedEvent)> listener){_valueChanged = listener;};
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const =0;
    virtual void handle(genv::event ev);
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();
};


#endif // WIDGETS_HPP_INCLUDED
