#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_textos() {
    for (map<string, map<string, Text> >::iterator i = Mautors.begin(); i != Mautors.end(); i++)
    	for (map<string, Text>::iterator j = (*i).second.begin(); j != (*i).second.begin().end(); j++)
    		cout << (*j).first << endl;
}