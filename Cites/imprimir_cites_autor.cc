#include "Cites.hh"

void Cites::imprimir_cites_autor(string nom_autor) {
	for (map<string, cita>::const_iterator i = cites.begin(); i != cites.end(); i++) {
		if ((*i).second.autor == nom_autor) {
			cout << (*i).first << endl;
			int n = (*i).second.frases.size();
            for (int k = 0; k < n; k++)
                cout << (*i).second.frase_inicial + k << " " << (*i).second.frases[k] << endl;
			cout << "\"" << (*i).second.titol_text << "\"" << endl;
		}
	}
}
