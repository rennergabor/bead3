#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

using namespace std;

class TextEditor : public Widget{
    string _s;
protected:
    void textChanged();
public:
    TextEditor(int x, int y, int sx, int sy, string s);
    virtual bool focusable() const {return true;}
    virtual void draw() const ;
    virtual void handle(genv::event ev) ;
    inline string value() {return _s;}
};



#endif // TEXTEDITOR_HPP_INCLUDED
