/** @file Cjt_autors.hh
    @brief Especificació de la clase Cjt_autors
*/

#include "Text.hh"
#include "Cites.hh"

using namespace std;

/** @class Cjt_autors
    @brief Conjunt d'autors amb textos i cites
*/

class Cjt_autors {

private:

  /**@brief Tipus de mòdul: dades
  * Descripció del tipus: representa un conjunt ordenat alfabeticament d'autors en un diccionari
  * Es poden consultar i modificar els seus elements (de tipus diccionari)
  * donat un nom d'autor
  * Aquests elements representen un conjunt ordenat de textos d'un autor en un diccionari
  * Es poden consultar i modificar els seus elements (de tipus Text)
  * donat el títol del text
  * A més, conté un diccionari al qual guarda cites, utilitzant una referència única a cada
  * cita com a clau
  */

  map<string, map<string, Text> > Mautors;
  map<string, Text>::iterator it1;
  map<string, map<string, Text> >::iterator it2;
  Cites cites;
  bool seleccio;



  
  /** @brief Invariant de la representacio:
  *  - Mautors es un diccionari que utilitza el nom de l'autor com a clau i un diccionari
  *    associat a cadascuna d'elles. Aquest conté els textos de cada autor amb el titol del
  *    text com a clau i un objecte Text associat a cadascun d'aquests
  *  - it1 és un iterator per a l'ultim text seleccionat
  *  - it2 és un iterator per a l'autor de l'ultim text seleccionat
  *  - cites és un diccionari on es guarden cites, utilitzant una referència única
  *    a cada cita com a clau
  *  - seleccio indica si hi ha un text seleccionat o no
  */

public:

  stringstream primera_linea;

  void comanda(string comanda);
  /**@brief Mètode per gestionar les comandes del programa
  * \pre comanda = Comanda
  * \post Tracta la comanda Comanda
  */ 

  // Constructores

  Cjt_autors();
  /**@brief Constructora de la classe
  * \pre Cert
  * \post El resultat es un conjunt d'autors amb els seus textos, buit
  */

  // Destructora

  ~Cjt_autors();

  // Modificadores

  void eliminar_text();
  /**@brief Mètode per eliminar un text
  * \pre S'ha seleccionat un text
  * \post El text seleccionat s'ha eliminat del conjunt
  */

  void eliminar_cita();
  /**@brief Mètode per eliminar una cita
  * \pre Al canal d'entrada estàndard hi ha una referència a una cita
  * \post S'ha eliminat la cita amb la referència indicada
  */

  void substituir();
  /**@brief Mètode per substituir paraules en un text
  * \pre S'ha seleccionat un text, al canal d'entrada estàndard hi ha la paraula a
  * substituir i la paraula que substitueix
  * \post S'ha substituit la paraula a substituir per la paraula que substitueix
  */

  void seleccionar_text();
  /**@brief Mètode per seleccionar un text
  * \pre Al canal d'entrada estàndard hi ha una llista de paraules que ha de contenir el text seleccionat
  * \post S'ha seleccionat el text, és a dir, seleccio s'ha posat a true
  */

  // Consultores

  bool hi_ha_seleccio();
  /**@brief Mètode per saber si hi ha un text seleccionat
  * \pre Cert
  * \post Si s'ha seleccionat un text retorna cert, fals altrament
  */

  // Lectura i escriptura

  void frases();
  /**@brief Mètode per tractar les comandes que comencen amb "frases"
  * \pre S'ha llegit "frases" de l'input, hi han parametres al canal d'entrada estàndard
  * \post S'ha executat la comanda corresponent segons els paràmetres llegits
  */

  void afegir_cita();
  /**@brief Mètode per afegir una cita
  * \pre S'ha llegit "afegir cita" del canal estàndard d'entrada
  * \post S'ha afegit la cita al diccionari de cites
  */

  void afegir_text();
  /**@brief Mètode per afegir un text
  * \pre S'ha llegit "afegir text" del canal estàndard d'entrada
  * \post S'ha afegit el text amb el seu autor al conjunt d'autors
  */

  void imprimeix_tots_textos();
  /**@brief Mètode per imprimir tots els textos
  * \pre Cert
  * \post S'ha imprès tots els autors per ordre alfabètic i els títols
  *       dels seus textos per ordre alfabètic
  */

  void imprimeix_tots_autors();
  /**@brief Mètode per imprimir tots els autors
  * \pre Cert
  * \post S'ha imprès tots els autors per ordre alfabètic
  */

  void imprimeix_tots_textos_autor();
  /**@brief Mètode per imprimir tots els textos d'un autor
  * \pre Al canal d'entrada estàndard hi ha el nom d'un autor
  * \post S'han imprès els titols de tots els textos de l'autor, per ordre alfabetic
  */

  void imprimeix_info();
  /**@brief Mètode per imprimir informació d'un text
  * \pre S'ha seleccionat un text
  * \post s'ha imprès, del text seleccionat, autor, títol, nombre de frases, nombre de paraules
  *        i cites associades
  */

  void imprimeix_info_cita();
  /**@brief Mètode per imprimir informació d'una cita
   * \pre Al canal d'entrada estàndard hi ha una referència a una cita
   * \post s'ha imprès la informació de la cita referenciada
   */

  void imprimeix_autor_text();
  /**@brief Mètode per imprimir l'autor d'un text
  * \pre S'ha seleccionat un text
  * \post s'ha imprès l'autor del text seleccionat
  */

  void imprimeix_contingut_text();
  /**@brief Mètode per imprimir el contingut d'un text
  * \pre S'ha seleccionat un text
  * \post S'ha imprès el contingut del text seleccionat
  */

  void imprimeix_nombre_frases();
  /**@brief Mètode per imprimir el nombre de frases
  * \pre Cert
  * \post S'ha imprès pel canal de sortida estàndard el nombre total d'elements del paràmetre implícit
  */

  void imprimeix_nombre_paraules();
  /**@brief Mètode per imprimir el nombre de paraules
  * \pre Cert
  * \post s'ha imprès pel canal de sortida estàndard el nombre total d'elements de frases
  */

  void imprimeix_taula_frequencies();
  /**@brief Mètode per imprimir la taula de freqûències
  * \pre cert
  * \post s'ha imprès pel canal de sortida estàndard les paraules de frases i la seva freqüènca
  */

  void imprimeix_totes_cites();
  /**@brief Mètode per imprimir totes les cites
  * \pre Cert
  * \post S'han imprès totes les cites pel canal estàndard de sortida
  */

  void imprimeix_cites_autor();
  /**@brief Mètode per imprimir totes les cites d'un autor
  * \pre Al canal d'entrada estàndard hi ha un nom d'autor
  * \post S'han imprès totes les cites de l'autor amb el nom llegit
  */

  void imprimeix_cites_text();
  /**@brief Mètode per imprimir totes les cites del text seleccionat
  * \pre s'ha seleccionat un text
  * \post s'han imprès totes les cites del text seleccionat pel canal de sortida estàndard
  */

};