#include "Text.hh"

void Text::substituir(string paraula_a_substituir, string paraula_que_substitueix) {
	for (int i = 0; i < n; i++)
		linies[i].replace(linies[i].find(paraula_a_substituir), paraula_a_substituir.size(), paraula_que_substitueix);
}