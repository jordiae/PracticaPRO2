#include "Cjt_autors.hh"

Arbre<string> Cjt_autors::parse(Arbre<string> a, string expressio) {
	if (expressio.size() == 0)
		return a;
	else {
		string arrel = a.arrel();
		if (expressio[i] == '(') {
			a.plantar(arrel, )
		}
        else if (expressio[i] == '{')
        else if (expressio[i] == ')')
        else if (expressio[i] == '}')
        else {
        	string paraula = "";
        	for (int i = 0; expressio[i] != '}')
        		paraula += expressio[i];
        	Arbre<string> b;

        }
	}
}



(({mel mato} | {fruita} & {restaurant}))

vvvvvvvvvvvvvvvvvvvvvvvvvvvvv
if (expressio[i] == '(')
else if (expressio[i] == '{')
else if (expressio[i] == ')')
else if (expressio[i] == '}')
else


int n = expressio.size();
for (int i = 0; i < n; i++) {
	if (expressio[i] == '(') {
		int j = i;
		while(expressio[j] != ')')
			j++;
		string expressio2;
		for (int k = i; k <= j; k++)
			expressio2.push_back(expressio[k]);
		parse(a,expressio2)
	}
    paraula += expressio[i];
}