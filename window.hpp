#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
private:
    int _sx, _sy;
protected:
    std::vector<Widget*> widgets;
    virtual void saveToFile();
public:
    Window(int sx, int sy);
    void event_loop();
    void torles();
};



#endif // WINDOW_HPP_INCLUDED
