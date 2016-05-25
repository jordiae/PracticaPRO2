#include "Cites.hh"

void Cites::imprimir_totes_cites() {
	 map<string, cita>::iterator i;
	 for (map<string, cita>::iterator i = cites.begin(); i != cites.end(); i++) {
	 	cout << (*i).second.autor << endl << (*i).second.titol_text << endl << (*i).second.frase_inicial << endl << (*i).second.frase_final << endl;
	    int n = (*i).second.frases.size();
	    for (int k = 0; k < n; k++)
	        cout << (*i).second.frases[k];
	    cout << endl;
	 }
}