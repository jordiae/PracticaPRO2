#include "Cites.hh"

Cites::Cites() {

}
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
        for (int n = 0; n < (*i).second+1; n++){
            stringstream nref;
            nref << n;
            string aux = referencia + nref.str();
            map<string, cita>::iterator it = cites.find(aux);
            if (it != cites.end() && ((*it).second.titol_text == titol_text and (*it).second.frase_inicial == frase_inicial and (*it).second.frase_final == frase_final)){
                cout << "error" << endl;
                n = (*i).second+1;
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
void Cites::eliminar_cita(string referencia) {
    map<string, cita>::iterator it = cites.find(referencia);
    if (it == cites.end())
        cout << "error" << endl;
    else
        cites.erase(it);
}
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
void Cites::imprimir_cites_text(string titol_text) {
    map<string, cita>::iterator i = cites.begin();
    while(i != cites.end()){
		if ((*i).second.titol_text == titol_text) {
            cout << (*i).first << endl;
			int n = (*i).second.frases.size();
			for (int k = 0; k < n; k++)
	    		cout << (*i).second.frase_inicial +k << " " << (*i).second.frases[k] << endl;
            cout << (*i).second.autor << " \"" << (*i).second.titol_text << "\"" << endl;
		}
		i++;
	}
}
void Cites::imprimir_totes_cites() {
    map<string, cita>::iterator it = cites.begin();
    while (it != cites.end()){
	 	cout << (*it).first << endl;
	 	for (int i = 0; i < (*it).second.frases.size(); i++)
            cout << (*it).second.frase_inicial + i << " " << (*it).second.frases[i] << endl;
        cout << (*it).second.autor << " \"" << (*it).second.titol_text << "\"" << endl;
        it++;
	 }
}

string Cites::inicials_autor(string autor){
    stringstream ss;
    ss << autor;
    string word;
    string inicials;
    while(ss >> word)
        inicials += word[0];
    return inicials;
}

Cites::~Cites() {

}
