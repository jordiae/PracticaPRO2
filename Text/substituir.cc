#include "Text.hh"

void Text::substituir(string paraula_a_substituir, string paraula_que_substitueix) {
    int n = linies.size();
	for (int i = 0; i < n; i++)
		linies[i].replace(linies[i].find(paraula_a_substituir), paraula_a_substituir.size(), paraula_que_substitueix);
	int n = frequencies.size();
    int i = 0; 
    bool found = false;
    while (not found and i < n) {
        if (frequencies[i].paraula == paraula_que_substitueix
    	    found = false;
        else 
    	    i++;
    }
    if (found)
        frequencies[i].freq++;
    else {
        frequencia f;
        f.paraula = paraula_que_substitueix;
        f.freq = 1;
        frequencies.push_back(f);
    }
    for (int i = 0; i < n; i++) {
    	if (frequencies[i].paraula == paraula_a_substituir and frequencies[i].freq > 1)
    		frequencies[i].freq--;
    	if (frequencies[i].paraula == paraula_a_substituir and frequencies[i].freq <= 1) {
    		for (int j = i; j < n-1; j++)
    			frequencies[j] == frequencies[j+1];
    		frequencies.pop_back();
    	}

    }
    ordenar_frequencies(frequencies);
}