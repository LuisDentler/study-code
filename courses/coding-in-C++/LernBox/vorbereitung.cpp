#include "vorbereitung.hpp"

#include <iostream>
#include <string>


int main(){

    Haus h("City 8");
    h.addZimmer("Wohnzimmer", 25);
    h.addZimmer("Küche", 22);
    h.zeigeZimmer();

    return 0;
}
