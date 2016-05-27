#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_cites_autor() {
	string autor;
	primera_linea.ignore(10, '"');
	primera_linea >> autor;
	autor.erase(autor.size() - 1, 1);
	cites.imprimir_cites_autor(autor);
}
