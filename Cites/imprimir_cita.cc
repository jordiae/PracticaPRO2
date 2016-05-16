#include "Cites.hh"

void Cites::imprimir_cita(string referencia) {
	map<string, cita>::const_iterator i = cites.find(referencia);
	cout << (*i).second.autor << endl << (*i).second.titol_text << endl << (*i).second.frase_inicial << endl << (*i).second.frase_final << endl;
	int n = (*i).second.frases.size();
	for (int k = 0; k < n; k++)
	    cout << (*i).second.frases[k];
	cout << endl;
}
