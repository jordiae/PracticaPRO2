/** @file Cites.hh
    @brief Especificació de la clase Cites
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

/** @class Cites
    @brief Gestionador de cites
*/

class Cites {

private:

  /**@brief Tipus de mòdul: dades
  * Descripció del tipus: representa gestionador de cites
  * Es poden consultar i i modificar els seus elements (de tipus Text)
  * donat el títol del text
  */

struct cita {
    string autor;
    string titol_text;
    int frase_inicial;
    int frase_final;
    vector<string> frases;
  };


  map<string, cita> cites;
  map<string, int> referencies;

  /**@brief Invariant de la representació:
	*	- cites és un diccionari que conté la referència completa (inicials de l'autor + índex)
	*	  de cada cita i la pròpia cita. Les referències no es poden repetir i l'índex començarà a 1
	*	- referencies és un diccionari que utilitza les inicials del autor de la cita referenciada amb
	*	  un comptador com a objecte que compta el nombre de vegades que han aparegut aquestes inicials
	*	  des de l'inici del programa
  */

public:

  // Constructores

  Cites();
  /**@brief Constructora de la classe
  * \pre Cert
  * \post El resultat és un gestionador de cites
  */

  // Destructora

  ~Cites();

  // Modificadores

  void afegir_cita(int frase_inicial, int frase_final, vector<string> frases, string nom_autor, string titol_text);
  /**@brief Mètode per afegir una cita
  * \pre Cert
  * \post S'ha afegit una cita amb les dades passades pels paràmetres al paràmetre implícit
  */

  void eliminar_cita(string referencia);
  /**@brief Mètode per eliminar una cita
  * \pre Referencia és la referència vàlida d'una cita existent
  * \post S'ha eliminat la cita amb referència referencia
  */

  // Consultores

  static string inicials_autor(string autor);
  /**@brief Mètode per consultar les inicials d'un autor
  * \pre autor = nom de l'autor
  * \post Es retornen les inicials de l'autor
  */

  // Lectura i escriptura

  void imprimir_cita(string referencia);
  /**@brief Mètode per imprimir una cita
  * \pre referencia és la referència vàlida d'una cita existent
  * \post S'ha imprès la cita amb referència referencia al canal estàndard de sortida
  */

  void imprimir_cites_autor(string nom_autor);
  /**@brief Mètode per imprimir les cites d'un autor
  * \pre Cert
  * \post s'han imprès totes les cites de l'autor amb nom nom_autor, si existeix
  */

  void imprimir_cites_text(string titol_text);
  /**@brief Mètode per imprimir les cites d'un text
  * \pre titol_text és el títol d'un text
  * \post S'han imprès totes les cites del text amb títol titol_text
  */

  void imprimir_cites_associades(string titol_text);
  /**@brief Mètode per imprimir cites associades
  * \pre Cert
  * \post S'han imprès totes les cites del text amb títol titol_text sense el nom de l'autor o el titol del text al final
  */

  void imprimir_totes_cites();
  /**@brief Mètode per imprimir totes les cites
  * \pre Cert
  * \post s'han imprès totes les cites pel canal estàndard de sortida
  */

};