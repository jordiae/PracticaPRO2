#include "Text.hh"

void Text::imprimeix_frases_paraules(vector<string> &paraules){
	int n = linies.size();
	stringstream ss;
	for (int i = 0; i < n; i++) {
		int m = paraules.size();
		ss.str("");
		ss.clear();
		ss << linies[i];
        string word;
        int aux = 0;
        while (ss >> word and aux != m){
            char last = word[word.size() - 1];
            if (! ( (last >= 'a' and last <= 'z') or (last >= 'A' and last <= 'Z') or (last >= '0' and last <= '9') )) //Checks if last char is not a letter or a number
                word.erase(word.size() - 1, 1);
            if (paraules[aux] == word)
                aux++;
            else
                aux = 0;
        }
		if (aux == m)
            cout << i+1 << " " << linies[i] << endl;

	}
}
