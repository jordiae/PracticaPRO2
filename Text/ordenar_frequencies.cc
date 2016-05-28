#include "Text.hh"

void Text::ordenar_frequencies(vector<frequencia>& freqs) {
    sort(freqs.begin(), freqs.end(), comp);
    while (freqs[freqs.size() - 1].freq == 0)
        freqs.pop_back();
}
