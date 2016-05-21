#include "Cjt_autors.hh"

void Cjt_autors::seleccionar_text() {
    vector <string> paraules;
    string paraula;
    while (cin >> paraula && paraula[paraula.size() - 1] != '}'){
        paraules.push_back(paraula);
    }
    paraula.erase(paraula.size() - 1, 1);
    paraules.push_back(paraula);

    map<string, Text>::iterator iterator1;
    map<string, map<string, Text> >::iterator iterator2;

    for(iterator2 = Mautors.begin(); iterator2 != Mautors.end(); iterator2){
        vector <string> temp1 = paraules;
        vector <string> temp2;
        for (int i = 0; i < temp1.size(); i++){
            if (! Text.conte_paraula((*iterator2).first, temp1[i]))
                temp2.push_back(temp1[i]);
        }
        for(iterator1 = (*iterator2).second.begin(); iterator1 != (*iterator2).second.end(); iterator1++;){
            bool b = false;

        }
    }
}
