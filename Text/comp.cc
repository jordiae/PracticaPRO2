#include "Text.hh"

Text::comp(const frequencia& a, const frequencia& b)) {
	if (a.freq > b.freq)
		return a > b;
    else if (b.freq > a.freq)
        return b > a;
    else {
        if (a.paraula.size() < b.paraula.size())
            return a;
        else if (a.paraula.size() > b.paraula.size())
            return b;
        else {
            if (a.paraula >= b.paraula)
                return a;
            else
                return b;
          }
      }
}