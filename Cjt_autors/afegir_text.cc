#include "Cjt_autors.hh"

Cjt_autors::afegir_text(){
	string nom_autor, titol_text, empty;
	char temp;
	cin >> temp;
	getline(cin, titol_text);
	cin >> empty;
	cin >> temp;
	getline(cin, nom_autor);
	Mautors[nom_autor][titol_text].afegeix_contingut();
	}
