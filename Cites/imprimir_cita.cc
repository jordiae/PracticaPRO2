#include "Cites.hh"

void Cites::imprimir_cita(string referencia) {
	map<string, cita>::const_iterator i = cites.find(referencia);
	if (i == cites.end())
        cout << "error" << endl;
    else{
        cout << (*i).second.autor << " \"" << (*i).second.titol_text << "\"" << endl;
        cout << (*i).second.frase_inicial << "-" << (*i).second.frase_final << endl;
        int n = (*i).second.frases.size();
        for (int k = 0; k < n; k++)
            cout << (*i).second.frase_inicial + k << " " << (*i).second.frases[k] << endl;
    }
}
