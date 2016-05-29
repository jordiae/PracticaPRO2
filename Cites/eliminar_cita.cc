#include "Cites.hh"

void Cites::eliminar_cita(string referencia) {
    map<string, cita>::iterator it = cites.find(referencia);
    if (it == cites.end())
        cout << "error" << endl;
    else
        cites.erase(it);
}
