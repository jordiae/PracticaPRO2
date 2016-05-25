#include "Cjt_autors.hh"

void Cjt_autors::eliminar_text() {
    (*it2).second.erase(it1);
    it2 = Mautors.end();
}
