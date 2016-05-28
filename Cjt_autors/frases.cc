#include "Cjt_autors.hh"

void Cjt_autors::frases() {
	char pchar = primera_linea.str()[7];
    primera_linea.ignore(1, ' ');
    if (pchar >= '0' and pchar <= '9'){
        int x, y;
        primera_linea >> x >> y;
        if( x > y or x < 1 or y < 1 or x > (*it1).second.comptar_linies() or y > (*it1).second.comptar_linies())
            cout << "error" << endl;
        else{
            vector<string> frases = (*it1).second.frases_x_fins_y(x, y);
            for (int i = 0; i < (y - x + 1); i++)
                cout << x + i << " " << frases[i] << endl;
        }
	}
	else if (pchar == '(') {
		string expressio;
		getline(primera_linea,expressio);
		expressio.erase(expressio.size() - 2, 2); // I was here
		vector<string> frases_a_avaluar = (*it1).second.frases_x_fins_y(1, (*it1).second.comptar_linies());
		int n = frases_a_avaluar.size();
		for (int i = 0; i < n; i++){
            if ((*it1).second.avalua_frase_expressio(expressio, frases_a_avaluar[i]))
				(*it1).second.imprimeix_linies(i+1, i+1);
		}
	}
	else {
		list<string> paraules;
		list<string>::iterator it = paraules.begin();
		string paraula;
		primera_linea.ignore(2, '"');
		primera_linea >> paraula;
		while (paraula[paraula.size()-1] != '"') {
			paraules.insert(it,paraula);
			++it;
			primera_linea >> paraula;
		}
		paraula.pop_back();
        paraules.insert(it,paraula);
		(*it1).second.imprimeix_frases_paraules(paraules);
	}
}
