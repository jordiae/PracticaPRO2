#include "Cjt_autors.hh"

void Cjt_autors::seleccionar_text() {
    vector <string> paraules;
    string paraula;
    while (cin >> paraula && paraula[paraula.size() - 1] != '}'){
        paraules.push_back(paraula);
    }
    paraula.erase(paraula.size() - 1, 1);
    paraules.push_back(paraula);

    bool found = false;   //Whether the text has been found or not.
    map<string, Text>::iterator iterator1;
    map<string, map<string, Text> >::iterator iterator2;

    for(iterator2 = Mautors.begin(); iterator2 != Mautors.end(); iterator2++){
        vector<bool> paraulesFound(paraules.size());
        for (int i = 0; i < paraules.size(); i++){
            if (Text::conte_paraula((*iterator2).first, paraules[i]))
                paraulesFound[i] = true;
        }
        for(iterator1 = (*iterator2).second.begin(); iterator1 != (*iterator2).second.end(); iterator1++){
            vector<bool> temp = paraulesFound;
            for (int i = 0; i < paraules.size(); i++){
                if ( Text::conte_paraula((*iterator1).first, paraules[i]) or (*iterator1).second.existeix_paraula(paraules[i]) )
                    temp[i] = true;
            }
            bool temporal = true;
            for (int i = 0; i < temp.size(); i++){
                if(temp[i] == false)
                    found = false;
            }
            if (temporal and found){
                cout << "error" << endl;
                it2 = Mautors.end();
                iterator1 = (*iterator2).second.end();
                iterator2 = Mautors.end();
            }
            else if (temporal){
                found = true;
                it2 = iterator2;
                it1 = iterator1;
            }
        }
    }
}
