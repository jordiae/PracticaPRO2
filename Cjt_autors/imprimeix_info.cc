#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_info() {
    cout << (*it2).first << " \"" << (*it1).first << "\" " << endl;
    (*it1).second.imprimeix_nombre_frases();
    cout << " ";
    (*it1).second.imprimeix_nombre_paraules();
    cout << endl << "Cites Associades:" << endl;
    cites.imprimir_cites_text((*it1).first);
}
