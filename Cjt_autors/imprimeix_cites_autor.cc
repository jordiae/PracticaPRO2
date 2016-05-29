#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_cites_autor() {
	string autor, word;
	primera_linea.ignore(10, '"');
	getline(primera_linea, autor);
	autor.erase(autor.size()-3, 3);
	cites.imprimir_cites_autor(autor);
}
