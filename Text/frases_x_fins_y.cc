#include "Text.hh"

vector<string> Text::frases_x_fins_y(int x, int y) {
	vector<string> frases;
	for (int i = x-1; i <= y-1; i++)
		frases.push_back(linies[i]);
	return frases;
}
