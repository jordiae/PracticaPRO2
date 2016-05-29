#include "Cjt_autors.hh"

void Cjt_autors::afegir_cita() {
	int frase_inicial;
  	int frase_final;
  	vector<string> frases;
    primera_linea >> frase_inicial >> frase_final;
    if( frase_inicial > frase_final or frase_inicial < 1 or frase_final < 1 or frase_inicial > (*it1).second.comptar_linies() or frase_final > (*it1).second.comptar_linies())
        cout << "error" << endl;
    else{
        frases = (*it1).second.frases_x_fins_y(frase_inicial, frase_final);
        cites.afegir_cita(frase_inicial, frase_final, frases, (*it2).first, (*it1).first);
    }
}
