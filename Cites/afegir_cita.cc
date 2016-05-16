#include "Cites.hh"

void Cites::afegir_cita(int frase_inicial, int frase_final, vector<string> frases, string nom_autor, string titol_text) {
    cita c;
  	c.autor = nom_autor;
  	c.titol_text = titol_text;
  	c.frase_inicial = frase_inicial;
  	c.frase_final = frase_final;
  	c.frases = frases;

    string referencia;
    referencia += nom_autor[0];
    int n = nom_autor.size();
    if (n > 0) {
        for (int i = 1; i < n-1; i++) {
            if (nom_autor[i] == 32)
                referencia += nom_autor[i+1];
        }
    }

    map<string, int>::iterator i = referencies.find(referencia);
    if (i == referencies.end()) {
        referencies.insert(make_pair(referencia,0));
        cites.insert(make_pair(referencia+'0',c));
    }
    else {
        (*i).second++;
        stringstream nref;
        nref << (*i).second;
        referencia += nref.str();
        cites.insert(make_pair(referencia,c));
    }
  }
