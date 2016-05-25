#include "Cites.hh"

void Cites::imprimir_cites_autor(string nom_autor) {
	for (map<string, cita>::const_iterator i = cites.begin(); i != cites.end(); i++) {
		if ((*i).second.autor == nom_autor) {
			cout << (*i).second.autor << endl << (*i).second.titol_text << endl << (*i).second.frase_inicial << endl << (*i).second.frase_final << endl;
			int n = (*i).second.frases.size();
			for (int k = 0; k < n; k++)
	    		cout << (*i).second.frases[k];
			cout << endl;
		}
	}
}
