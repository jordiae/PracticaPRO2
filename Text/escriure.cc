#include "Text.hh"

void Text::escriure(){
    for (int i = 0; i < linies.size(); i++){
        cout << i + 1 << " " << linies[i] << endl;
    }
}
