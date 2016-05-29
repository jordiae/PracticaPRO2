#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_textos_autor() {
	string autor;
	primera_linea.ignore(10, '"');
	getline(primera_linea, autor);
	autor.erase(autor.size()-3, 3);
	map<string, Text>::iterator it;
	for (it = Mautors[autor].begin(); it != Mautors[autor].end(); it++)
		cout << "\"" << it -> first << "\"" << endl;
}
