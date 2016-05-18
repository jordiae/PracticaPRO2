#include "Text.hh"

void Text::afegeix_contingut() {
    string word;
    int i = 0;
    linies.push_back("");
    while(cin >> word && word[word.size()-1] != '*'){
        linies[i] += " " + word;
        char last_char = word[word.size()-1];
        if (last_char == '.' || last_char == '?' || last_char == '!'){
            linies.push_back("");
            i++;
        }
    }
}
