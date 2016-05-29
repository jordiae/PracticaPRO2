#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_textos_autor() {
	string autor;
	primera_linea.ignore(10, '"');
	getline(primera_linea, autor);
	autor.erase(autor.size() - 1, 1);
    autor.pop_back();
    autor.pop_back();
	map<string, Text>::iterator it;
	for (it = Mautors.find(autor) -> second.begin(); it != Mautors.find(autor) -> second.end(); it++)
		cout << '"' << it -> first << '"' << endl;
}