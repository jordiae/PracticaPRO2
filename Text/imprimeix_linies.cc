#include "Text.hh"

void Text::imprimeix_linies(int primera_linia, int ultima_linia){
	for (int i = primera_linia; i <= ultima_linia; i++)
		cout << linies[i] << endl;
}