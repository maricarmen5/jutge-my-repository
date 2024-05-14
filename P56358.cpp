#include <iostream>
using namespace std;

struct Temps {int hora, minut, segon;};

void un_segon(const Temps& t, Temps& t1, Temps& t2) 
{
    t1.segon = t.segon + 1;
    t1.minut = t.minut + t1.segon/60;
    t1.hora = (t.hora + t1.minut/60) % 24;
    t1.segon %= 60;
    t1.minut %= 60;
    
    t2.segon = (t.segon + 59) % 60;
    t2.minut = (t.minut + 60 - t2.segon/59) % 60;
    t2.hora = (t.hora + 24 - t2.segon/59*t2.minut/59) % 24;
}

int main () 
{
    Temps t, t1, t2;
    while (cin >> t.hora >> t.minut >> t.segon) {
        un_segon(t, t1, t2);

        cout << t1.hora << ' ' << t1.minut << ' ' << t1.segon << endl;
        cout << t2.hora << ' ' << t2.minut << ' ' << t2.segon << endl;
    }
}
