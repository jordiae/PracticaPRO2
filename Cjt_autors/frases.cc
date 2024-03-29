#include "Cjt_autors.hh"

void Cjt_autors::frases() {
	char pchar = primera_linea.str()[7];
    primera_linea.ignore(1, ' ');
    if (pchar >= '0' and pchar <= '9'){
        string auxx, auxy;
        bool valid = true;
        primera_linea >> auxx >> auxy;
        for (int i = 0; i < auxx.size(); i++){
            if (not (auxx[i] >= '0' and auxx[i] <= '9'))
                valid = false;
        }
        for (int i = 0; i < auxy.size(); i++){
            if (not (auxy[i] >= '0' and auxy[i] <= '9'))
                valid = false;
        }
        if (valid){
            int x, y;
            stringstream ss;
            ss << auxx;
            ss >> x;
            ss.str("");
            ss.clear();
            ss << auxy;
            ss >> y;

            if( x > y or x < 1 or y < 1 or x > (*it1).second.comptar_linies() or y > (*it1).second.comptar_linies())
                cout << "error" << endl;
            else{
                vector<string> frases = (*it1).second.frases_x_fins_y(x, y);
                for (int i = 0; i < (y - x + 1); i++)
                    cout << x + i << " " << frases[i] << endl;
            }
        }

	}
	else if (pchar == '(') {
		string expressio;
		getline(primera_linea,expressio);
		expressio.erase(expressio.size() - 2, 2);
		vector<string> frases_a_avaluar = (*it1).second.frases_x_fins_y(1, (*it1).second.comptar_linies());
		int n = frases_a_avaluar.size();
		for (int i = 0; i < n; i++){
            if ((*it1).second.avalua_frase_expressio(expressio, frases_a_avaluar[i]))
				(*it1).second.imprimeix_linies(i+1, i+1);
		}
	}
	else if (pchar == '"'){
		vector<string> paraules;
		string paraula;
		primera_linea.ignore(2, '"');
		while (primera_linea >> paraula && paraula[paraula.size()-1] != '"'){
			paraules.push_back(paraula);
		}
		paraula.pop_back();
        paraules.push_back(paraula);
        (*it1).second.imprimeix_frases_paraules(paraules);
	}
}
