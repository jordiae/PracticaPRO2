#include "Text.hh"
#include "Cites.hh"

using namespace std;

class Cjt_autors {

private:

  // Tipus de mòdul: dades
  // Descripció del tipus: representa un conjunt ordenat alfabeticament d'autors en un diccionari
  // Es poden consultar i modificar els seus elements (de tipus diccionari)
  // donat un nom d'autor
  // Aquests elements representen un conjunt ordenat de textos d'un autor en un diccionari
  // Es poden consultar i modificar els seus elements (de tipus Text)
  // donat el títol del text
  // A més, conté un diccionari al qual guarda cites, utilitzant una referència única a cada
  // cita com a clau

  map<string, map<string, Text> > Mautors;
  map<string, Text>::iterator it1;
  map<string, map<string, Text> >::iterator it2;
  Cites cites;
  bool seleccio;

  /*
    Invariant de la representacio:
		- Mautors es un diccionari que utilitza el nom de l'autor com a clau i un diccionari
		  associat a cadascuna d'elles. Aquest conté els textos de cada autor amb el titol del
		  text com a clau i un objecte Text associat a cadascun d'aquests
        - it1 és un iterator per a l'ultim text seleccionat
		- it2 és un iterator per a l'autor de l'ultim text seleccionat
		- cites és un diccionari on es guarden cites, utilitzant una referència única
		  a cada cita com a clau
  */

public:

  stringstream primera_linea;

  void comanda(string comanda);

  // Constructores

  Cjt_autors();
  /* Pre: cert */
  /* Post: el resultat es un conjunt d'autors amb els seus textos, buit */

  // Destructora

  ~Cjt_autors();

  // Modificadores


  void eliminar_text();
  /* Pre: s'ha seleccionat un text */
  /* Post: el text seleccionat s'ha eliminat del conjunt */

  void eliminar_cita();
  /* Pre: al canal d'entrada estàndard hi ha una referència a una cita */
  /* Post: s'ha eliminat la cita amb la referència indicada */

  void substituir();
  /* Pre: s'ha seleccionat un text, al canal d'entrada estàndard hi ha la paraula a */
  /* substituir i la paraula que substitueix */
  /* Post: S'ha substituit la paraula a substituir per la paraula que substitueix */

  void seleccionar_text();
  /* Pre: al canal d'entrada estàndard hi ha una llista de paraules que ha de contenir el text seleccionat */
  /* Post: S'ha seleccionat el text */


  // Consultores

  bool hi_ha_seleccio();

  // Lectura i escriptura

  void frases();
  /* Pre: s'ha llegit "frases" de l'input, hi han parametres al canal d'entrada estàndard */
  /* Post: s'ha executat la comanda corresponent segons els paràmetres llegits */

  void afegir_cita();
  /* Pre: s'ha llegit "afegir cita" de l'input */
  /* Post: s'ha afegit la cita al diccionari de cites */

  void afegir_text();
  /* Pre: s'ha llegit "afegir text" de l'input */
  /* Post: s'ha afegit el text amb el seu autor al conjunt d'autors */

  void imprimeix_tots_textos();
  /* Pre: Cert */
  /* Post: s'ha imprès tots els autors per ordre alfabètic i els titols */
  /*       dels seus textos per ordre alfabètic */

  void imprimeix_tots_autors();
  /* Pre: Cert */
  /* Post: s'ha imprès tots els autors per ordre alfabètic */

  void imprimeix_tots_textos_autor();
  /* Pre: al canal d'entrada estàndard hi ha el nom d'un autor */
  /* Post: s'han imprès els titols de tots els textos de l'autor, per ordre alfabetic */

  void imprimeix_info();
  /* Pre: s'ha seleccionat un text */
  /* Post: s'ha imprès, del text seleccionat, autor, títol, nombre de frases, nombre de paraules */
  /*        i cites associades */

  void imprimeix_info_cita();
  /* Pre: al canal d'entrada estàndard hi ha una referència a una cita */
  /* Post: s'ha imprès la informació de la cita referenciada */

  void imprimeix_autor_text();
  /* Pre: s'ha seleccionat un text */
  /* Post: s'ha imprès l'autor del text seleccionat */

  void imprimeix_contingut_text();
  /* Pre: s'ha seleccionat un text */
  /* Post: s'ha imprès el contingut del text seleccionat */

  void imprimeix_nombre_frases();
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard el nombre total d'elements del paràmetre implícit */

  void imprimeix_nombre_paraules();
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard el nombre total d'elements de frases */

  void imprimeix_taula_frequencies();
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard les paraules de frases i la seva freqüènca */

  void imprimeix_totes_cites();
  /* Pre: cert */
  /* Post: s'han imprès totes les cites pel canal estàndard de sortida */

  void imprimeix_cites_autor();
  /* Pre: al canal d'entrada estàndard hi ha un nom d'autor */
  /* Post: s'han imprès totes les cites de l'autor amb nom nom_autor */

  void imprimeix_cites_text();
  /* Pre: s'ha seleccionat un text */
  /* Post: s'han imprès totes les cites del text amb títol titol_text */

};
