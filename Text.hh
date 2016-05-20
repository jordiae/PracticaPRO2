#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <set>
#include "Arbre.hh"

using namespace std;

class Text {

private:

  // Tipus de mòdul: dades
  // Descripció del tipus: representa un text
  // Es poden consultar i modificar les línies del text donat el número d'aquestes

  vector<string> linies;

  /*
    Invariant de la representació:
    - línies és el conjunt de totes les línies del text
  */

public:

  // Constructores

  Text();
  /* Pre: cert */
  /* Post: el resultat és un text buit */

  // Destructora

  ~Text();

  // Modificadores

  void substituir(string paraula_a_substituir, string paraula_que_substitueix);
  /* Pre: s'ha seleccionat un text */
  /* Post: S'ha substituït la paraula a substituir per la paraula que substitueix */

  // Consultores

  vector<string> frases_x_fins_y(int x, int y);
  /* Pre: Cert */
  /* Post: Es retorna un vector que conté les frases x a y */

  int comptar_linies();
  /* Pre: cert */
  /* Post: retorna el nombre de línies del paràmetre implícit */

  bool existeixen_paraules(vector<string> paraules);
  /* Pre: s'ha seleccionat un text */
  /* Post: Es retorna si les paraules es troben al text */

  bool avalua_frase_expressio(Arbre<string> a, string frase);
  /* Pre: a és el parseig de l'expressió donada en forma d'arbre*/
  /* Post: retorna si la frase frase compleix l'expressió o no */

  // Lectura i escriptura

  void afegeix_contingut();
  /* Pre: s'ha llegit el títol del text i el seu autor, el contingut es troba al canal d'entrada estàndard */
  /* Post: s'ha afegit el contingut llegit al p.i. */

  void imprimeix_linies(int primera_linia, int ultima_linia);
  /* Pre: 0 <= primera_linia <= ultima_linia <= nombre de linies del paràmetre implícit */
  /* Post: s'han imprès les línies corresponets a la sortida estàndard */

  void llegir();
  /* Pre: hi ha un text al canal d'entrada estàndard */
  /* Post: el paràmetre implícit és igual al text llegit */

  void escriure();
  /* Pre: cert */
  /* Post: s'ha escrit el text pel canal estàndard de sortida */

  void imprimeix_nombre_frases();
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard el nombre total d'elements del paràmetre implícit */

  void imprimeix_nombre_paraules();
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard el nombre total d'elements de frases */

  void imprimeix_taula_frequencies();
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard les paraules de frases i la seva freqüènca */

  void imprimeix_frases_paraules(list<string> &paraules);
  /* Pre: cert */
  /* Post: s'ha imprès pel canal de sortida estàndard els elements de frases que contenen la seqüència paraules */

};
