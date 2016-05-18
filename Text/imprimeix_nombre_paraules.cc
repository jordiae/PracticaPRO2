#include "Text.hh"

void Text::imprimeix_nombre_paraules() {
    int c = 1;
	int n = linies.size();
	for (int i = 0; i < n; i++) {
		int m = linies[i].size();
		for (int j = 0; j < m; j++)
			if (linies[i][j] == 32)
				c++;
	}
   cout << c << endl;
}