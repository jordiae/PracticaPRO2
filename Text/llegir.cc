#include "Text.hh"

void Text::llegir() {
	string linia;
	while (getline(cin,linia))
		linies.push_back(linia);
}