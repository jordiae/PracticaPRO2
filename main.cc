#include "Cjt_autors.hh"

using namespace std;

void error() {
  cout << "error" << endl;
}

int main() {
  Cjt_autors cjt_autors;
  string comanda;
  while (comanda != "sortir" and cin >> comanda ) {
    if ( comanda == "afegir"){
      cin >> comanda;
      if (comanda == "text")
        cjt_autors.afegir_text();
      else
        cjt_autors.afegir_cita();
      }
    else if ( comanda == "triar"){
      cin;
      cjt_autors.seleccionar_text();
      }
    else if ( comanda == "eliminar"){
      cin >> comanda;
      if (comanda == "text")
        cjt_autors.eliminar_text();
      else
        cjt_autors.eliminar_cita();
      }
    else if ( comanda == "substitueix"){
      cjt_autors.substituir();
    }
    else if ( comanda == "textos"){
      cin;
      cjt_autors.imprimeix_tots_textos_autor();
    }
    else if ( comanda == "tots"){
      cin >> comanda;
      cin;
      if (comanda == "textos")
        cjt_autors.imprimeix_tots_textos();
      else
        cjt_autors.imprimeix_tots_autors();
      }
    else if ( comanda == "info"){
      cin >> comanda;
      if (comanda == "?")
        cjt_autors.imprimeix_info();
      else
        cjt_autors.imprimeix_info_cita();
      }
    else if ( comanda == "autor"){
      cin;
      cjt_autors.imprimeix_autor_text();
    }
    else if ( comanda == "contingut"){
      cin;
      cjt_autors.imprimeix_contingut_text();
    }
    else if ( comanda == "frases"){
      cjt_autors.frases();
    }
    else if ( comanda == "nombre"){
      cin;
      cin >> comanda;
      cin;
      if (comanda == "frases")
        cjt_autors.imprimeix_nombre_frases();
      else
        cjt_autors.imprimeix_nombre_paraules();
      }
    else if ( comanda == "taula"){
      cin;
      cin;
      cin;
      cjt_autors.imprimeix_taula_frequencies();
    }
    else if ( comanda == "cites"){
      cin >> comanda;
      if (comanda == "?")
        cjt_autors.imprimeix_cites_text();
      else
        cjt_autors.imprimeix_cites_autor();
    }
    else if ( comanda == "totes"){
      cin;
      cin;
      cjt_autors.imprimeix_totes_cites();
    }
  }
}
