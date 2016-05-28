#include "Text.hh"

void Text::imprimeix_linies(int primera_linia, int ultima_linia){
	for (int i = primera_linia-1; i <= ultima_linia-1; i++)
		cout << i+1 << " " << linies[i] << endl;
}
