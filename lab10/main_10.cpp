 #include <iostream>
#include "Ceg.h"

 using namespace std;

int main() {

    Ceg ceg("Microsoft");

Alkalmazott *a1 = new Alkalmazott("Nagy", "Krisztian", 1999, "");
Alkalmazott *a2 = new Alkalmazott("Kovacs", "Ferenc", 1997, "");
Alkalmazott *a3 = new Alkalmazott("Kiss", "Krisztian", 1998, "");
Alkalmazott *a4 = new Alkalmazott("Tivadar", "Levente", 2000, "");

ceg.ujSzemelyHozzaadasa(a1);
ceg.ujSzemelyHozzaadasa(a2);
ceg.ujSzemelyHozzaadasa(a3);
ceg.ujSzemelyHozzaadasa(a4);

ceg.osszesAlkalmazottListaz();

    return 0;
}