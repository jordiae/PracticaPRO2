#include "Cjt_autors.hh"

void Cjt_autors::imprimeix_tots_autors() {
	map<string, map<string, Text> >::iterator it;
	for (it = Mautors.begin(); it != Mautors.end(); it++) {
        if((*it).second.size() != 0){
            cout << it -> first << " " << (*it).second.size();
            map<string, Text>::iterator itt;
            int nombre_paraules = 0;
            int nombre_frases = 0;
            for (itt = (*it).second.begin(); itt != (*it).second.end(); itt++) {
                nombre_paraules += (*itt).second.comptar_paraules();
                nombre_frases += (*itt).second.comptar_linies();
            }
            cout << " " << nombre_frases << " " << nombre_paraules << endl;
        }
	}
}
