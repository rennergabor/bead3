#ifndef AMOBAAPPLICATION_HPP_INCLUDED
#define AMOBAAPPLICATION_HPP_INCLUDED

enum Allapot {MENU, JATEK, EREDMENY, KILEPES};

class AmobaApplication {
private:
    Allapot _allapot = Allapot::MENU;
public:
    int run();
    inline void changeState(Allapot a) {_allapot = a;};
};

#endif // AMOBAAPPLICATION_HPP_INCLUDED
