#include "Cjt_autors.hh"

void Cjt_autors::frases() {
	char c;
	primera_linea >> c;
	if (c == '(') {
		string expressio;
		getline(primera_linea,expressio);
		expressio += '(';
		expressio.pop_back();
		expressio.pop_back();
		vector<string> frases_a_avaluar = (*it1).second.frases_x_fins_y(0, (*it1).second.comptar_linies());
		int n = frases_a_avaluar.size();
		for (int i = 0; i < n; i++)
			if ((*it1).second.avalua_frase_expressio(expressio, frases_a_avaluar[i]))
				(*it1).second.imprimeix_linies(i, i);
	}

	else {
		list<string> paraules;
		list<string>::iterator it = paraules.begin();
		string paraula;
		primera_linea >> paraula;
		while (paraula[paraula.size()-1] != '"') {
			paraules.insert(it,paraula);
			++it;
			primera_linea >> paraula;
		}
		paraula.pop_back();
        paraules.insert(it,paraula);
		(*it1).second.imprimeix_frases_paraules(paraules);
	}
}