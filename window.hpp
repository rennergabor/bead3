#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
private:
    int _sx, _sy;
    bool _exit;
protected:
    std::vector<Widget*> widgets;
public:
    Window(int sx, int sy);
    void event_loop();
    void exit_event_loop();
    void torles();
};



#endif // WINDOW_HPP_INCLUDED
