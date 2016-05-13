#include "Cjt_autors.hh"

Cjt_autors::frases() {
	char c;
	cin >> c;
	Text text = *it1;
	if (c == '(') {
		string expressio;
		getline(cin,expressio)
		expressio += '('; 
		expressio.pop_back();
		expressio.pop_back();
		text.imprimeix_frases_expressio(expressio);
	}
	else {
		list<string> paraules;
		list<string>::iterator it = paraules.begin();
		string paraula;
		cin >> paraula;
		while (paraula[paraula.size()-1] != '"') {
			paraules.insert(it,paraula)
			++it;
			cin >> paraula;
		}
		paraula.pop_back();
        paraules.insert(iy,paraula);
		text.imprimeix_frases_paraules(paraules);
	}
}