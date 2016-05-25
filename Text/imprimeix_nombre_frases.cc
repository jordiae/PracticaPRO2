#include "Text.hh"

void Text::imprimeix_nombre_frases() {
	int c = 0;
	int n = linies.size();
	for (int i = 0; i < n; i++) {
		int m = linies[i].size();
		for (int j = 0; j < m; j++) {
			if (linies[i][j] == '.')
				c++;
		}
	}
	cout << c << endl;
}