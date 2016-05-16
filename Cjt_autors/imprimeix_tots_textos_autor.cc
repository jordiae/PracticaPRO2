#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_textos_autor() {
	string autor;
	cin >> autor;
	map<string, Text>::iterator it;
	for (it = it2 -> second.begin(); it != it2 -> second.end(); it++)
		cout << it -> first << endl;
}
