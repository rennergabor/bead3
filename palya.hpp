#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Palya : public Widget {
protected:
    bool _checked;
public:
    Palya(vector<vector<bool> > &tabla,int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
};


#endif // PALYA_HPP_INCLUDED
