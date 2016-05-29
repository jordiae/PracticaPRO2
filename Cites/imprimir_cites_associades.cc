#include "Cites.hh"

void Cites::imprimir_cites_associades(string titol_text) {
	for (map<string, cita>::const_iterator i = cites.begin(); i != cites.end(); i++) {
		if ((*i).second.titol_text == titol_text) {
            cout << (*i).first << endl;
			int n = (*i).second.frases.size();
			for (int k = 0; k < n; k++)
	    		cout << (*i).second.frase_inicial +k << " " << (*i).second.frases[k] << endl;;
		}
	}
}
