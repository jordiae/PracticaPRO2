#include "Cjt_autors.hh"

void afegir_cita() {
	int frase_inicial;
  	int frase_final;
  	vector<string> frases;
  	cin >> frase_inicial >> frase_final;
  	Text text = *it1;
  	frases = text.frases_x_fins_y(frase_inicial, frase_final);
  	cites.afegir_cita(frase_inicial, frase_final, frases);
}