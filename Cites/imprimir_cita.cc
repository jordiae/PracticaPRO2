#include "Cites.hh"

Cites::imprimir_cita(string referencia) {
	map<string, int>::const_iterator i = cites.find(referencia);
	cout << (*i).second.autor << endl << (*i).second.titol_text << endl << (*i).second.frase_inicial << endl << (*i).second.frase_final << endl;
	int n = (*i).second.frases.size();
	for (int i = 0; i < n; i++)
	    cout << (*i).second.frases[i];
	cout << endl; 
}