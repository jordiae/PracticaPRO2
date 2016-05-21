#include "Text.hh"

bool Text::conte_paraula(string text, string paraula){
    stringstream ss;
    ss << text;
    string word;
    while (ss >> word){
        char last = word[word.size() - 1];
        if (! ( (last >= 'a' and last <= 'z') or (last >= 'A' and last <= 'Z') )) //Checks if last char is not a letter
            word.erase(word.size() - 1, 1);
        if (paraula == word)
            return true;
    }
    return false;
}
