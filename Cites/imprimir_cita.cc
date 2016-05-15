#include "Cites.hh"

Cites::imprimir_cita(string referencia) {
	map<string, int>::const_iterator i = cites.find(referencia);
	cout << (*i).autor << endl << (*i).titol_text << endl << (*i).frase_inicial << endl << (*i).frase_final << endl;
	int n = frases.size();
	for (int i = 0; i < n; i++)
	    cout << frases[i];
	cout << endl; 
}