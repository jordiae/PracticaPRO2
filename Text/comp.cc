#include "Text.hh"

bool Text::comp(const frequencia& a, const frequencia& b) {
	if (a.freq != b.freq)
		return a.freq > b.freq;
    else if (a.paraula.size() != b.paraula.size())
            return a.paraula.size() < b.paraula.size();
    else
        return a.paraula < b.paraula;
}
