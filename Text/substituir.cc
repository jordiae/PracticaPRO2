#include "Text.hh"

void Text::substituir(string paraula_a_substituir, string paraula_que_substitueix) {
    int p1_pos = -1;
    int p2_pos = -1;
    for (int i = 0; i < frequencies.size() and (p1_pos == -1 or p2_pos == -1); i++){
        if (frequencies[i].paraula == paraula_a_substituir)
            p1_pos = i;
        if (frequencies[i].paraula == paraula_que_substitueix)
            p2_pos = i;
    }

    if (p1_pos != -1 and p1_pos != p2_pos){
        int n = linies.size();
        for (int i = 0; i < n; i++) {
            int pos = linies[i].find(paraula_a_substituir);
            while (pos != -1){
                linies[i].replace(pos, paraula_a_substituir.length(), paraula_que_substitueix);
                pos = linies[i].find(paraula_a_substituir);
            }
        }
        if (p2_pos != -1){
            frequencies[p2_pos].freq += frequencies[p1_pos].freq;
            frequencies[p1_pos].freq = 0;
        }
        else{
            frequencies[p1_pos].paraula = paraula_que_substitueix;
        }
        ordenar_frequencies(frequencies);
    }

}
