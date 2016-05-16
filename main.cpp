#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "szambeallito.hpp"
#include "szambeallitoWithClickButton.hpp"
#include "legordulo.hpp"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class MyWindow : public Window {
public:
    ExampleCheckBox *checkbox;
    StaticText *tx1;
    TextEditor *ed1;
    Szambeallito *sz1;
    Szambeallito *sz2;
    SzambeallitoWithClickButton *sz3;
    Legordulo *k1;
    Legordulo *k2;

    //PushButton *button;
    MyWindow(int x, int y) : Window (x, y) {
        checkbox = new ExampleCheckBox(10, 150, 30, 30);
        //button = new PushButton(this, 10, 10, 60, 60,"=", "egyenlo");
        tx1 = new StaticText(10,20,100,40,"Static Text");
        ed1 = new TextEditor(10,100,100,40,"editor");
        sz1 = new Szambeallito(10,5,15,10,200,100,40);
        sz2 = new Szambeallito(52,40,65,10,250,100,40);
        sz3 = new SzambeallitoWithClickButton(52,45,55,10,300,100,40);
        vector<string> v1 = {"hello", "belo", "kakukk", "madar", "galiba", "szánkó", "türelem", "rózsát" };
        vector<string> v2 = {"Alpok", "Kárpátok", "Massive Central", "Himalaja"};
        k1 = new Legordulo (v1, 150, 200, 150, 40);
        k2 = new Legordulo (v2, 150, 250, 150, 40);
        k2->hozzaAd("Andok");

        widgets.push_back(tx1);
        widgets.push_back(ed1);
        widgets.push_back(checkbox);
        widgets.push_back(sz1);
        widgets.push_back(sz2);
        widgets.push_back(sz3);
        widgets.push_back(k1);
        widgets.push_back(k2);
        //widgets.push_back(button);
    }


    void saveToFile() {
        ofstream myfile;
        myfile.open ("data.txt", ios::out | ios::app);
        myfile << "Szambeallito1=" << sz1->value() << '\t';
        myfile << "Szambeallito2=" << sz2->value() << '\t';
        myfile << "Legordulo1=" << k1->value() << '\t';
        myfile << "Legordulo2=" << k2->value() << '\n';
        myfile.close();
    }

};

int main()
{
    cout << "F12-re a 'data.txt' file-ba ment!\n";
    MyWindow *mywindow = new MyWindow(400, 400);
    mywindow->event_loop();
    return 0;
}
