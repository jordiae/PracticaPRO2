#include "Text.hh"

void Text::ordenar_frequencies(vector<frequencia>& freqs) {
    sort(freqs.begin(), freqs.end(), comp);
}