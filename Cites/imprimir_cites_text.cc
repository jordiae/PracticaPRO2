#include "Cites.hh"

Cites::imprimir_cites_text(string titol_text) {
	for (map<string, cita>::const_iterator i = cites.begin(); i != cites.end(); i++) {
		if ((*i).second.titol_text == titol_text) {
			cout << (*i).second.autor << endl << (*i).second.titol_text << endl << (*i).second.frase_inicial << endl << (*i).second.frase_final << endl;
			int n = (*i).second.frases.size();
			for (int i = 0; i < n; i++)
	    		cout << (*i).second.frases[i];
			cout << endl;
		}
	}
}