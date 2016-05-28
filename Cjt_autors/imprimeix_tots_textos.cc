#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_textos() {
    for (map<string, map<string, Text> >::iterator i = Mautors.begin(); i != Mautors.end(); i++)
    	for (map<string, Text>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++){
            cout << (*i).first << " \"" << (*j).first << "\"" << endl;
    	}
}
