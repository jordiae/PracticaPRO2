#include "Cjt_autors.hh"

void Cjt_autors::comanda(string comanda){

    char useless;
    cout << comanda << endl;
    primera_linea.str("");
    primera_linea.clear();
    primera_linea << comanda;
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
