#include "Text.hh"

void Text::afegeix_contingut() {
    string word;
    int i = 0;
    while(cin >> word && word[0] != '*'){
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
    }
    if (linies.size() != 0 && linies[linies.size()-1].size() == 0)
        linies.pop_back();
}
