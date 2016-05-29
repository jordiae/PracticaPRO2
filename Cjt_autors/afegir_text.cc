#include "Cjt_autors.hh"

void Cjt_autors::afegir_text(){
	string nom_autor, titol_text, s;
	primera_linea.ignore(10, '"');
	getline(primera_linea, titol_text);
	titol_text.erase(titol_text.size() - 1, 1);
	cin.ignore(10, '"');
	getline(cin, nom_autor);
	nom_autor.erase(nom_autor.size() - 1, 1);
	if (Mautors[nom_autor].find(titol_text) != Mautors[nom_autor].end())
        cout << "error" << endl;
    else
        Mautors[nom_autor][titol_text].afegeix_contingut();
	}
