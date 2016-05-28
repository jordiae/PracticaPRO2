#include "Text.hh"

void Text::afegeix_contingut() {
    string word;
    int i = 0;
    while(cin >> word && word[0] != '*'){
        num_paraules++;
        if (linies.size() == 0)
            linies.push_back("");
        if (linies[i].size() != 0)
            linies[i] += " " + word;
        else
            linies[i] += word;
        char last_char = word[word.size()-1];
        if (last_char == '.' || last_char == '?' || last_char == '!'){
            linies.push_back("");
            i++;
        }
        int n = frequencies.size();
        int j = 0;
        bool found = false;
        while (not found and j < n) {
            if (frequencies[j].paraula == word)
                found = true;
            else
                j++;
        }
        if (found)
            frequencies[j].freq++;
        else {
            frequencia f;
            f.paraula = word;
            f.freq = 1;
            frequencies.push_back(f);
        }
    }
    if (linies.size() != 0 && linies[linies.size()-1].size() == 0)
        linies.pop_back();
    ordenar_frequencies(frequencies);
}
