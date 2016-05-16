#include "Cjt_autors.hh"

void Cjt_autors::substituir() {
	string paraula_a_substituir, paraula_que_substitueix;
	cin >> paraula_a_substituir >> paraula_que_substitueix;
	(*it1).second.substituir(paraula_a_substituir,paraula_que_substitueix);
}
