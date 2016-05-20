#include "Text.hh"

bool Text::avalua_frase_expressio(Arbre<string> a, string frase) {
	string arrel = a.arrel(); 
	Arbre<string> e, d;
	a.fills(e,d);
	if (a.es_buit()) {
		int n = linies.size();
		int i = 0;
		bool existeix = false;
		while (not existeix and i < n) {
			if (linies[i] == frase)
				existeix = true;
			++i;
		}
		return existeix;
	}
	else {
		bool be = imprimeix_frases_expressio(e);
		if ((not be and arrel = "&") or (arrel == "|" and be))
		    return be;
		bool bd = imprimeix_frases_expressio(d);
		else if (arrel == "|" and bd)
			return true;
		else 
			return false;
	}
}