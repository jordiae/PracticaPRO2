#include "Text.hh"

void Text::imprimeix_frases_paraules(list<string> &paraules){
	int n = linies.size();
	for (int i = 0; i < n; i++) {
		int m = paraules.size();
		for (list<string>::iterator j = paraules.begin(); j != paraules.end(); j++) {
			int p;
			if (linies[i].find(*j) != string::npos) {
				p = linies[i].find(*j);
				int k = p, l = p;
				while (k != 0 and linies[i][k] != '.')
					k--;
				while (linies[i][l] != '.')
					l++;
				for (int z = k; z <= l; z++)
					cout << linies[i][z];
				cout << endl;
			}
		}
	}
}