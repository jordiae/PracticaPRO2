#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_textos_autor() {
	string autor;
	primera_linea.ignore(10, '"');
	primera_linea >> autor;
	autor.erase(autor.size()-1, 1);
	map<string, Text>::iterator it;
	for (it = it2 -> second.begin(); it != it2 -> second.end(); it++)
		cout << it -> first << endl;
}
