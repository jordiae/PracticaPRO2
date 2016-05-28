#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class Text {

private:

  // Tipus de mòdul: dades
  // Descripció del tipus: representa un text
  // Es poden consultar i modificar les línies del text donat el número d'aquestes

  vector<string> linies;
  int num_paraules;

  struct frequencia {
      string paraula;
      int freq;
  };

  vector<frequencia> frequencies;
  /*
    Invariant de la representació:
    - línies és el conjunt de totes les línies del text
  */

  static bool comp(const frequencia& a, const frequencia& b);

  static void ordenar_frequencies(vector<frequencia>& freqs);


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

  static bool conte_paraula(string text, string paraula);
  /* Pre: Cert */
  /* Post: Retorna si el string text conté el string paraula */

  vector<string> frases_x_fins_y(int x, int y);
  /* Pre: Cert */
  /* Post: Es retorna un vector que conté les frases x a y */

  int comptar_linies();
  /* Pre: cert */
  /* Post: retorna el nombre de línies del paràmetre implícit */

  bool existeix_paraula(string paraula);
  /* Pre: s'ha seleccionat un text */
  /* Post: Es retorna si la paraula es troba al text */

  bool avalua_frase_expressio(string expressio, string frase);
  /* Pre: expressio és una expressió booleana de paraules vàlida */
  /* Post: retorna si la frase frase compleix l'expressió o no */

  // Lectura i escriptura

  void afegeix_contingut();
  /* Pre: s'ha llegit el títol del text i el seu autor, el contingut es troba al canal d'entrada estàndard */
  /* Post: s'ha afegit el contingut llegit al p.i. */

  void imprimeix_linies(int primera_linia, int ultima_linia);
  /* Pre: 0 <= primera_linia <= ultima_linia <= nombre de linies del paràmetre implícit */
  /* Post: s'han imprès les línies corresponets a la sortida estàndard */

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
