#include "Text.hh"

vector<string> Text::frases_x_fins_y(int x, int y) {
	vector<string> frases;
	string frase = "";
	int n = linies.size();
	int m;
	bool found = false;
	int i = 0;
	int j = 0;
	int ix, jx, iy, jy;
	int c = 0;
	while (not found and i < n) {
		m = linies[i].size();
		while (not found and j < m) {
		    if (linies[i][j] == '.') {
		    	if (c == x) {
		    	    found = true;
		    	    ix = i;
		    	    jx = j;
		        }
		    	c++;
		    }
		    j++;
	    }
	    i++;
	}
	while (not found and i < n) {
		m = linies[i].size();
		while (not found and j < m) {
			frase += linies[i][j];
		    if (linies[i][j] == '.') {
		    	frases.push_back(frase);
		    	frase = "";
		    	if (c == y) {
		    	    found = true;
		    	    iy = i;
		    	    jy = j;
		        }
		    	c++;
		    }
		    j++;
	    }
	    i++;
	}
	return frases;
}
