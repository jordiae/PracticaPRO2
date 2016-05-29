#include "Cites.hh"

void Cites::afegir_cita(int frase_inicial, int frase_final, vector<string> frases, string nom_autor, string titol_text) {
    cita c;
  	c.autor = nom_autor;
  	c.titol_text = titol_text;
  	c.frase_inicial = frase_inicial;
  	c.frase_final = frase_final;
  	c.frases = frases;

    string referencia = Cites::inicials_autor(nom_autor);
    map<string, int>::iterator i = referencies.find(referencia);
    if (i == referencies.end()) {
        referencies.insert(make_pair(referencia,1)); // era 0
        cites.insert(make_pair(referencia+'1',c)); // era 0
    }
    else{
        bool error = false;
        for (int n = 0; n < (*i).second; n++){
            stringstream nref;
            nref << n;
            string aux = referencia + nref.str();
            map<string, cita>::iterator it = cites.find(aux);
            if (it != cites.end() && ((*it).second.titol_text == titol_text and (*it).second.frase_inicial == frase_inicial and (*it).second.frase_final == frase_final)){
                cout << "error" << endl;
                n = (*i).second;
                error = true;
            }
        }
        if (not error){
            (*i).second++;
            stringstream nref;
            nref << (*i).second;
            referencia += nref.str();
            cites.insert(make_pair(referencia,c));
        }
    }
}

