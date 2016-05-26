#include "Cjt_autors.hh"

void Cjt_autors::afegir_text(){
	string nom_autor, titol_text, s;
	char temp;
	primera_linea >> temp;
	getline(primera_linea, titol_text);
	titol_text.erase(titol_text.size() - 1, 1);
	cin >> s;
	cin >> temp;
	getline(cin, nom_autor);
	nom_autor.erase(nom_autor.size() - 1, 1);
	Mautors[nom_autor][titol_text].afegeix_contingut();
	}
