#include "Cjt_autors.hh"

void Cjt_autors::afegir_cita() {
	int frase_inicial;
  	int frase_final;
  	vector<string> frases;
  	cin >> frase_inicial >> frase_final;
  	frases = (*it1).second.frases_x_fins_y(frase_inicial, frase_final);
  	cites.afegir_cita(frase_inicial, frase_final, frases, (*it2).first, (*it1).first);
}
