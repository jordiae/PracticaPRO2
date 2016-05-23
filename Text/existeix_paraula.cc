#include "Text.hh"

bool Text::existeix_paraula(string paraula){
    for (int i = 0; i < linies.size(); i++){
        if (Text::conte_paraula(linies[i], paraula))
            return true;
    }
    return false;
}
