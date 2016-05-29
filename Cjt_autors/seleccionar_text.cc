#include "Cjt_autors.hh"


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
                seleccio = true;
                it1 = iterator1;
                it2 = iterator2;
                iterator1++;
            }else if (temp and found){
                cout << "error" << endl;
                error = true;
                seleccio = false;
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
        seleccio = false;
    }


}

