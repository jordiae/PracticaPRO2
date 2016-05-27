#include "Cjt_autors.hh"

void Cjt_autors::substituir() {
	string paraula_a_substituir, paraula_que_substitueix;
	primera_linea.ignore(10, '"');
	primera_linea >> paraula_a_substituir;
	paraula_a_substituir.erase(paraula_a_substituir.size() - 1, 1);
	primera_linea.ignore(10, '"');
	primera_linea >> paraula_que_substitueix;
	paraula_que_substitueix.erase(paraula_que_substitueix.size() - 1, 1);
	(*it1).second.substituir(paraula_a_substituir,paraula_que_substitueix);
}
