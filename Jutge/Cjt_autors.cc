#include "Cjt_autors.hh"

Cjt_autors::Cjt_autors() {
	it2 = Mautors.end();
}
void Cjt_autors::afegir_cita() {
	int frase_inicial;
  	int frase_final;
  	vector<string> frasess;
    primera_linea >> frase_inicial >> frase_final;
    if( frase_inicial > frase_final or frase_inicial < 1 or frase_final < 1 or frase_inicial > (*it1).second.comptar_linies() or frase_final > (*it1).second.comptar_linies())
        cout << "error" << endl;
    else{
        frasess = (*it1).second.frases_x_fins_y(frase_inicial, frase_final);
        cites.afegir_cita(frase_inicial, frase_final, frasess, (*it2).first, (*it1).first);
    }
}

void Cjt_autors::afegir_text(){
	string nom_autor, titol_text, s;
	primera_linea.ignore(10, '"');
	getline(primera_linea, titol_text);
	titol_text.erase(titol_text.size() - 1, 1);
	cin.ignore(10, '"');
	getline(cin, nom_autor);
	nom_autor.erase(nom_autor.size() - 1, 1);
	if (Mautors[nom_autor].find(titol_text) != Mautors[nom_autor].end())
        cout << "error" << endl;
    else
        Mautors[nom_autor][titol_text].afegeix_contingut();
	}

void Cjt_autors::comanda(string comande){

    char useless;
    cout << comande << endl;
    primera_linea.str("");
    primera_linea.clear();
    primera_linea << comande;
    string paraula;
    primera_linea >> paraula;
    if ( paraula == "afegir"){
        primera_linea >> paraula;
        if (paraula == "text"){
            afegir_text();
        }
        else{
            if (hi_ha_seleccio())
                afegir_cita();
            else
                cout << "error" << endl;
        }
    }
    else if ( paraula == "triar"){
        primera_linea.ignore(10, '{');
        seleccionar_text();
    }
    else if ( paraula == "eliminar"){
        primera_linea >> paraula;
        if (paraula == "text"){
            if (hi_ha_seleccio())
                eliminar_text();
            else
                cout << "error" << endl;
        }
        else
            eliminar_cita();
    }
    else if ( paraula == "substitueix"){
        if (hi_ha_seleccio())
            substituir();
        else
            cout << "error" << endl;
    }
    else if ( paraula == "textos"){
        primera_linea >> useless;
        imprimeix_tots_textos_autor();
    }
    else if ( paraula == "tots"){
        primera_linea >> paraula;
        primera_linea >> useless;
        if (paraula == "textos")
            imprimeix_tots_textos();
        else
            imprimeix_tots_autors();
    }
    else if ( paraula == "info"){
        primera_linea >> paraula;
        if (paraula == "?"){
            if (hi_ha_seleccio())
                imprimeix_info();
            else
                cout << "error" << endl;
        }
        else
            imprimeix_info_cita();
    }
    else if ( paraula == "autor"){
        if (hi_ha_seleccio()){
            primera_linea >> useless;
            imprimeix_autor_text();
        }
        else
            cout << "error" << endl;
    }
    else if ( paraula == "contingut"){
        if (hi_ha_seleccio()){
            primera_linea >> useless;
            imprimeix_contingut_text();
        }
        else
            cout << "error" << endl;
    }
    else if ( paraula == "frases"){
        if (hi_ha_seleccio())
            frases();
        else
            cout << "error" << endl;
    }
    else if ( paraula == "nombre"){
        if (hi_ha_seleccio()){
            primera_linea.ignore(3, 'e');
            primera_linea >> paraula;
            if (paraula == "frases")
                imprimeix_nombre_frases();
            else
                imprimeix_nombre_paraules();
            cout << endl;
        }
        else
            cout << "error" << endl;
    }
    else if ( paraula == "taula"){
        if (hi_ha_seleccio()){
            primera_linea >> useless;
            primera_linea >> useless;
            primera_linea >> useless;
            imprimeix_taula_frequencies();
        }
        else
            cout << "error" << endl;
    }
    else if ( paraula == "cites"){
        primera_linea >> paraula;
        if (paraula == "?")
            imprimeix_cites_text();
        else
            imprimeix_cites_autor();
    }
    else if ( paraula == "totes"){
        primera_linea >> useless;
        primera_linea >> useless;
        imprimeix_totes_cites();
    }

}
void Cjt_autors::eliminar_cita() {
	string referencia;
	primera_linea.ignore(10, '"');
	primera_linea >> referencia;
	referencia.erase(referencia.size() - 1, 1);
	cites.eliminar_cita(referencia);
}

void Cjt_autors::eliminar_text() {
    (*it2).second.erase(it1);
    it2 = Mautors.end();
}
void Cjt_autors::frases() {
	char pchar = primera_linea.str()[7];
    primera_linea.ignore(1, ' ');
    if (pchar >= '0' and pchar <= '9'){
        int x, y;
        primera_linea >> x >> y;
        if( x > y or x < 1 or y < 1 or x > (*it1).second.comptar_linies() or y > (*it1).second.comptar_linies())
            cout << "error" << endl;
        else{
            vector<string> fraseses = (*it1).second.frases_x_fins_y(x, y);
            for (int i = 0; i < (y - x + 1); i++)
                cout << x + i << " " << fraseses[i] << endl;
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
	else {
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

bool Cjt_autors::hi_ha_seleccio() {
	if (it2 == Mautors.end())
        return false;
    else
        return true;
}
void Cjt_autors::imprimeix_autor_text() {
    cout << it2 -> first << endl;
}

void Cjt_autors::imprimeix_cites_autor() {
	string autor, word;
	primera_linea.ignore(10, '"');
	getline(primera_linea, autor);
	autor.erase(autor.size()-3, 3);
	cites.imprimir_cites_autor(autor);
}

void Cjt_autors::imprimeix_cites_text() {
	cites.imprimir_cites_text((*it1).first);
}
void Cjt_autors::imprimeix_contingut_text() {
	(*it1).second.escriure();
}
void Cjt_autors::imprimeix_info() {
    cout << (*it2).first << " \"" << (*it1).first << "\" ";
    (*it1).second.imprimeix_nombre_frases();
    cout << " ";
    (*it1).second.imprimeix_nombre_paraules();
    cout << endl << "Cites Associades:" << endl;
    cites.imprimir_cites_associades((*it1).first);
}
void Cjt_autors::imprimeix_info_cita() {
	string referencia;
	primera_linea.ignore(10, '"');
	primera_linea >> referencia;
	referencia.erase(referencia.size() - 1, 1);
	cites.imprimir_cita(referencia);
}
void Cjt_autors::imprimeix_nombre_frases() {
    (*it1).second.imprimeix_nombre_frases();
}
void Cjt_autors::imprimeix_nombre_paraules() {
	(*it1).second.imprimeix_nombre_paraules();
}
void Cjt_autors::imprimeix_taula_frequencies() {
	(*it1).second.imprimeix_taula_frequencies();
}
void Cjt_autors::imprimeix_totes_cites() {
	cites.imprimir_totes_cites();
}
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
void Cjt_autors::imprimeix_tots_textos() {
    for (map<string, map<string, Text> >::iterator i = Mautors.begin(); i != Mautors.end(); i++)
    	for (map<string, Text>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++){
            cout << (*i).first << " \"" << (*j).first << "\"" << endl;
    	}
}
void Cjt_autors::imprimeix_tots_textos_autor() {
	string autor;
	primera_linea.ignore(10, '"');
	getline(primera_linea, autor);
	autor.erase(autor.size()-3, 3);
	map<string, Text>::iterator it;
	for (it = Mautors[autor].begin(); it != Mautors[autor].end(); it++)
		cout << "\"" << it -> first << "\"" << endl;
}
void Cjt_autors::seleccionar_text() {
    vector <string> paraules;
    string paraula;
    while (primera_linea >> paraula && paraula[paraula.size() - 1] != '}'){
        paraules.push_back(paraula);
    }
    paraula.erase(paraula.size() - 1, 1);
    paraules.push_back(paraula);


    map<string, Text>::iterator iterator1;
    map<string, map<string, Text> >::iterator iterator2;
    vector<bool> paraules_trobades(paraules.size());
    bool found = false;
    bool error = false;

    iterator2 = Mautors.begin();
    while (iterator2 != Mautors.end()){
        for (int i = 0; i < paraules.size(); i++){
            paraules_trobades[i] = Text::conte_paraula((*iterator2).first, paraules[i]);
        }

        vector<bool> aux(paraules_trobades.size());
        iterator1 = ((*iterator2).second.begin());
        bool temp = false;
        while(iterator1 != (*iterator2).second.end()){
            for (int i = 0; i < paraules.size(); i++){
                aux[i] = paraules_trobades[i] || (Text::conte_paraula((*iterator1).first, paraules[i]) or (*iterator1).second.existeix_paraula(paraules[i]));
            }
            temp = true;
            for (int i = 0; i < aux.size() and temp; i++){
                if (not aux[i])
                    temp = false;
            }
            if (temp and not found){
                found = true;
                it1 = iterator1;
                it2 = iterator2;
                iterator1++;
            }else if (temp and found){
                cout << "error" << endl;
                error = true;
                it2 = Mautors.end();
                iterator1 = (*iterator2).second.end();
            }else
                iterator1++;
        }

        if (error)
            iterator2 = Mautors.end();
        else
            iterator2++;
    }
    if (not found){
        cout << "error" << endl;
        it2 = Mautors.end();
    }


}

void Cjt_autors::substituir() {
	string paraula_a_substituir, paraula_que_substitueix;
	primera_linea.ignore(10, '"');
	primera_linea >> paraula_a_substituir;
	paraula_a_substituir.erase(paraula_a_substituir.size() - 1, 1);
	primera_linea.ignore(10, '"');
	primera_linea >> paraula_que_substitueix;
	paraula_que_substitueix.erase(paraula_que_substitueix.size() - 1, 1);
	(*it1).second.substituir(paraula_a_substituir,paraula_que_substitueix);
}

Cjt_autors::~Cjt_autors() {

}
