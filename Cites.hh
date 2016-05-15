#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Cites {

private:

  // Tipus de mòdul: dades
  // Descripció del tipus: representa gestionador de cites
  // Es poden consultar i i modificar els seus elements (de tipus Text)
  // donat el títol del text

struct cita {
    string autor;
    string titol_text;
    int frase_inicial;
    int frase_final;
    vector<string> frases;
  };


  map<string, cita> cites;
  map<string, int> referencies;

  /*
    Invariant de la representació:
		- cites és un diccionari que conté la referència completa (inicials de l'autor + índex)
		  de cada cita i la pròpia cita. Les referències no es poden repetir i l'índex començarà a 1
		- referencies és un diccionari que utilitza les inicials del autor de la cita referenciada amb
		  un comptador com a objecte que compta el nombre de vegades que han aparegut aquestes inicials
		  des de l'inici del programa
  */

public:

  // Constructores

  Cites();
  /* Pre: cert */
  /* Post: el resultat és un gestionador de cites  */

  // Destructora

  ~Cites();

  // Modificadores

  void afegir_cita(int frase_inicial, int frase_final, vector<string> frases, string nom_autor, string titol_text); 
  /* Pre: cert */
  /* Post: s'ha afegit una cita amb les dades passades pels paràmetres al paràmetre implícit */

  void eliminar_cita(string referencia);
  /* Pre: referencia és la referència vàlida d'una cita existent */
  /* Post: s'ha eliminat la cita amb referència referencia */

  // Consultoress

  // Lectura i escriptura

  void imprimir_cita(string referencia);
  /* Pre: referencia és la referència vàlida d'una cita existent */
  /* Post: s'ha imprès la cita amb referència referencia al canal estàndard de sortida */

  void imprimir_cites_autor(string nom_autor);
  /* Pre: cert */
  /* Post: s'han imprès totes les cites de l'autor amb nom nom_autor */

  void imprimir_cites_text(string titol_text);
  /* Pre: cert */
  /* Post: s'han imprès totes les cites del text amb títol titol_text */

  void imprimir_totes_cites();
  /* Pre: cert */
  /* Post: s'han imprès totes les cites pel canal estàndard de sortida */

};
