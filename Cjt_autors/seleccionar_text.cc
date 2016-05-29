#include "Cjt_autors.hh"


void Cjt_autors::seleccionar_text() {
    vector <string> paraules;
    string paraula;
    while (primera_linea >> paraula && paraula[paraula.size() - 1] != '}'){
        paraules.push_back(paraula);
    }
    paraula.erase(paraula.size() - 1, 1);
    paraules.push_back(paraula);
    int n = paraules.size() - 1;
    for (int i = 0; i < n; i++)
        paraules[i] = paraules[i+1];

    paraules.pop_back();
    for (int i = 0; i < paraules[0].size(); i++)
        paraules[0][i] = paraules[0][i+1];
    paraules[0].pop_back();

    
    map<string, Text>::iterator iterator1, iterator1_aux;
    map<string, map<string, Text> >::iterator iterator2, iterator2_aux;


    vector<bool> paraules_trobades(paraules.size());
    for (int i = 0; i < paraules_trobades.size(); i++)
        paraules_trobades[i] = false;
    int c_trobats = 0;

    for (iterator2 = Mautors.begin(); iterator2 != Mautors.end(); iterator2++) {

        Text text;
        for (iterator1 = (*iterator2).second.begin(); iterator1 != (*iterator2).second.end(); iterator1++) {
            for (int i = 0; i < paraules.size(); i++) {
                if (text.conte_paraula((*iterator2).first,paraules[i]))
                    paraules_trobades[i] = true;
                if ((*iterator1).second.existeix_paraula(paraules[i]))
                    paraules_trobades[i] = true;
                if (text.conte_paraula((*iterator1).first,paraules[i]))
                    paraules_trobades[i] = true;
            }
            bool compleix = true;
            int i = 0;
            while (compleix and i < paraules_trobades.size()) {
                if (not paraules_trobades[i])
                    compleix = false;
                i++;
            }
            if (compleix) {
                c_trobats++;
                iterator2_aux = iterator2;
                iterator1_aux = iterator1;
            }
        }
    }
    if (c_trobats == 1) {
        it2 = iterator2_aux;
        it1 = iterator1_aux;
    }
    else {
        it2 = Mautors.end();
        cout << "error" << endl;
    }



}

/* Les paraules poden apar`eixer
tant en el t´ıtol, com en l’autor, com en el contingut. Si hi ha m´es d’un text
que les contingui o no n’hi ha cap, es considera que no es compleixen els
requeriments de la comanda i, en en aquest cas, s’ha de produir un missatge
d’error tal com s’indica en la secci´o 2.5; en aquest cas, ja no hi haur`a cap
text triat encara que n’hi hagu´es un abans.*/