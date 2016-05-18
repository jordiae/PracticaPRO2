#include "Text.hh"

int Text::comptar_linies() {
	int n = 0;
	for (list<string>::const_iterator i = linies.begin(); i != linies.end(); i++)
		n++;
	return n;
}