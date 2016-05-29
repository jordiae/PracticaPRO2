#include "Cites.hh"

string Cites::inicials_autor(string autor){
    stringstream ss;
    ss << autor;
    string word;
    string inicials;
    while(ss >> word)
        inicials += word[0];
    return inicials;
}
