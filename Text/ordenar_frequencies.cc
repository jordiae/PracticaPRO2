#include "Text.hh"

Text::ordenar_frequencies(vector<frequencia>& freqs) {
    sort(freqs.begin(), freqs.end(), comp);
}