#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_autors() {
	map<string, map<string, Text> >::iterator it;
	for (it = Mautors.begin(); it != Mautors.end(); it++)
		cout << it -> first << endl;
}
