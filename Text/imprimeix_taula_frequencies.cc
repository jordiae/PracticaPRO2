#include "Text.hh"

void Text::imprimeix_taula_frequencies() {
	int n = frequencies.size();
	for (int i = 0; i < n; i++)
		cout << frequencies[i].paraula << " " << frequencies[i].freq << endl; 
}