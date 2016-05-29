#include "Cites.hh"

void Cites::imprimir_totes_cites() {
	 for (map<string, cita>::iterator it = cites.begin(); it != cites.end(); it++) {
	 	cout << (*it).first << endl;
	 	for (int i = 0; i < (*it).second.frases.size(); i++)
            cout << (*it).second.frase_inicial + i << " " << (*it).second.frases[i] << endl;
        cout << (*it).second.autor << " \"" << (*it).second.titol_text << "\"" << endl;
	 }
}
