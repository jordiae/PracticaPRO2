#include "Cjt_autors.hh"

Cjt_autors::Cjt_autors() {
    seleccio = false;
}

void Cjt_autors::afegir_cita() {
    vector<string> frasess;
    string auxx, auxy;
    bool valid = true;
    primera_linea >> auxx >> auxy;
    for (int i = 0; i < auxx.size(); i++)
        if (not (auxx[i] >= '0' and auxx[i] <= '9'))
            valid = false;
    for (int i = 0; i < auxy.size(); i++)
        if (not (auxy[i] >= '0' and auxy[i] <= '9'))
            valid = false;
    if (valid) {
        int x, y;
        stringstream ss;
        ss << auxx;
        ss >> x;
        ss.str("");
        ss.clear();
        ss << auxy;
        ss >> y;
        if (x > y or x < 1 or y < 1 or x > (*it1).second.comptar_linies() or y > (*it1).second.comptar_linies())
            cout << "error" << endl;
        else {
            frasess = (*it1).second.frases_x_fins_y(x, y);
            cites.afegir_cita(x, y, frasess, (*it2).first, (*it1).first);
         }
    }
}

void Cjt_autors::afegir_text() {
    string nom_autor, titol_text, s;
    char c;
    primera_linea >> c;
    getline(primera_linea, titol_text);
    titol_text.pop_back();
    cin >> s >> c;
    getline(cin, nom_autor);
    nom_autor.pop_back();
    if (Mautors[nom_autor].find(titol_text) != Mautors[nom_autor].end()){
        cout << "error" << endl;
        string word;
        while (cin >> word && word[0] != '*'){}
    }
    else
        Mautors[nom_autor][titol_text].afegeix_contingut();
}

void Cjt_autors::comanda(string comande) {
    char useless;
    cout << comande << endl;
    primera_linea.str("");
    primera_linea.clear();
    primera_linea << comande;
    string paraula;
    primera_linea >> paraula;
    if (paraula == "afegir") {
        primera_linea >> paraula;
        if (paraula == "text")
            afegir_text();
        else {
            if (hi_ha_seleccio())
                afegir_cita();
            else
                cout << "error" << endl;
        }
    }
    else if (paraula == "triar") {
        primera_linea >> paraula >> useless;
        seleccionar_text();
    }
    else if (paraula == "eliminar") {
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
    else if (paraula == "substitueix") {
        if (hi_ha_seleccio())
            substituir();
        else
            cout << "error" << endl;
    }
    else if (paraula == "textos") {
        primera_linea >> useless;
        imprimeix_tots_textos_autor();
    }
    else if (paraula == "tots") {
        primera_linea >> paraula;
        primera_linea >> useless;
        if (paraula == "textos")
            imprimeix_tots_textos();
        else
            imprimeix_tots_autors();
    }
    else if (paraula == "info") {
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
    else if (paraula == "autor") {
        if (hi_ha_seleccio()) {
            primera_linea >> useless;
            imprimeix_autor_text();
        }
        else
            cout << "error" << endl;
    }
    else if (paraula == "contingut") {
        if (hi_ha_seleccio()){
            primera_linea >> useless;
            imprimeix_contingut_text();
        }
        else
            cout << "error" << endl;
    }
    else if (paraula == "frases") {
        if (hi_ha_seleccio())
            frases();
        else
            cout << "error" << endl;
    }
    else if (paraula == "nombre") {
        if (hi_ha_seleccio()) {
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
    else if (paraula == "taula") {
        if (hi_ha_seleccio()) {
            primera_linea >> useless;
            primera_linea >> useless;
            primera_linea >> useless;
            imprimeix_taula_frequencies();
        }
        else
            cout << "error" << endl;
    }
    else if (paraula == "cites") {
        primera_linea >> paraula;
        if (paraula == "?"){
            if (hi_ha_seleccio())
                imprimeix_cites_text();
            else
                cout << "error" << endl;
        }
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
    seleccio = false;
}

void Cjt_autors::frases() {
    char pchar = primera_linea.str()[7];
    primera_linea.ignore(1, ' ');
    if (pchar == '"'){
        vector<string> paraules;
        string paraula;
        primera_linea.ignore(2, '"');
        while (primera_linea >> paraula && paraula[paraula.size()-1] != '"') {
            paraules.push_back(paraula);
        }
        if (paraula != "\"") {
            paraula.pop_back();
            paraules.push_back(paraula);
        }
        (*it1).second.imprimeix_frases_paraules(paraules);
    }
    else if (pchar == '(' or pchar == '{') {
        string expressio;
        getline(primera_linea,expressio);
        expressio.erase(expressio.size() - 2, 2);
        vector<string> frases_a_avaluar = (*it1).second.frases_x_fins_y(1, (*it1).second.comptar_linies());
        int n = frases_a_avaluar.size();
        for (int i = 0; i < n; i++)
            if ((*it1).second.avalua_frase_expressio(expressio, frases_a_avaluar[i]))
                (*it1).second.imprimeix_linies(i+1, i+1);
    }
    else {
        int x, y;
        primera_linea >> x >> y;
        if (x > y or x < 1 or y < 1 or x > (*it1).second.comptar_linies() or y > (*it1).second.comptar_linies())
            cout << "error" << endl;
        else {
            vector<string> fraces = (*it1).second.frases_x_fins_y(x, y);
            for (int i = 0; i < (y - x + 1); i++)
                cout << x + i << " " << fraces[i] << endl;
        }
    }
}

bool Cjt_autors::hi_ha_seleccio() {
    return seleccio;
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
        if ((*it).second.size() != 0) {
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
        for (map<string, Text>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++)
            cout << (*i).first << " \"" << (*j).first << "\"" << endl;
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
    while (primera_linea >> paraula && paraula[paraula.size() - 1] != '}')
        paraules.push_back(paraula);
    paraula.pop_back();
    if (paraula.size() != 0)
        paraules.push_back(paraula);
    map<string, Text>::iterator iterator1;
    map<string, map<string, Text> >::iterator iterator2;
    vector<bool> paraules_trobades(paraules.size());
    bool found = false;
    bool error = false;
    iterator2 = Mautors.begin();
    while (iterator2 != Mautors.end()) {
        for (int i = 0; i < paraules.size(); i++)
            paraules_trobades[i] = Text::conte_paraula((*iterator2).first, paraules[i]);
        vector<bool> aux(paraules_trobades.size());
        iterator1 = ((*iterator2).second.begin());
        bool temp = false;
        while(iterator1 != (*iterator2).second.end()) {
            for (int i = 0; i < paraules.size(); i++)
                aux[i] = paraules_trobades[i] || (Text::conte_paraula((*iterator1).first, paraules[i]) or (*iterator1).second.existeix_paraula(paraules[i]));
            temp = true;
            for (int i = 0; i < aux.size() and temp; i++)
                if (not aux[i])
                    temp = false;
            if (temp and not found) {
                found = true;
                seleccio = true;
                it1 = iterator1;
                it2 = iterator2;
                iterator1++;
            }
            else if (temp and found) {
                cout << "error" << endl;
                error = true;
                seleccio = false;
                iterator1 = (*iterator2).second.end();
            }
            else
                iterator1++;
        }
        if (error)
            iterator2 = Mautors.end();
        else
            iterator2++;
    }
    if (not found) {
        cout << "error" << endl;
        seleccio = false;
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
    if (paraula_a_substituir != paraula_que_substitueix)
        (*it1).second.substituir(paraula_a_substituir,paraula_que_substitueix);
}

Cjt_autors::~Cjt_autors() {}