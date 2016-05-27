#include "Cjt_autors.hh"

void Cjt_autors::substituir() {
	string paraula_a_substituir, paraula_que_substitueix;
	char useless;
	string annoying;
	primera_linea >> useless >> paraula_a_substituir >> useless >> annoying >> useless >> paraula_que_substitueix;
	(*it1).second.substituir(paraula_a_substituir,paraula_que_substitueix);
}