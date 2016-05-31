/** @file Text.hh
    @brief Especificació de la clase Text
*/

#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

/** @class Text
    @brief Text
*/


class Text {

private:

  /**@brief Tipus de mòdul: dades
  * Descripció del tipus: representa un text
  * Es poden consultar i modificar les línies del text donat el número d'aquestes
  */

  vector<string> linies;
  int num_paraules;

  struct frequencia {
      string paraula;
      int freq;
  };

  vector<frequencia> frequencies;
  /**@brief Invariant de la representació:
  *  - línies és el conjunt de totes les línies del text
  *  - num_paraules és el nombre de paraules del text
  *  - frequencies es un vector que emmagatzema cada paraula diferent i el nombre d'aparicions
  */


  static bool comp(const frequencia& a, const frequencia& b);
  /**@brief Mètode auxiliar per comparar dues freqüències, de manera que es retorni el valor de veritat
  * corresponent a la freq més gran i, en cas que siguin iguals, sigui més gran la paraula més petita. En cas
  * que continuï sense marcar-se la diferència, per ordre alfabètic
  * \pre a = A, b = B són structs frequencia vàlids
  * \post Es retorna el valor adequat per la comparació
  */

  static void ordenar_frequencies(vector<frequencia>& freqs);
  /**@brief Mètode ordenar un vector freqüencies, de manera decreixent per freqs i, en cas d'empat,
  * per paraula més petita i ordre alfabètic
  * \pre freqs = freqs
  * \post S'ha ordenat ordenar_frequencies
  */


public:

  // Constructores

  Text();
  /**@brief Constructora de la classe
  * \pre Cert
  * \post El resultat és un text buit
  */

  // Destructora

  ~Text();

  // Modificadores

  void substituir(string paraula_a_substituir, string paraula_que_substitueix);
  /**@brief Mètode per substituir una paraula per un altra
  * \pre S'ha seleccionat un text
  * \post S'ha substituït la paraula a substituir per la paraula que substitueix
  */

  // Consultores

  static bool conte_paraula(string text, string paraula);
  /**@brief Mètode per determinar si una string conté una paraula
  * \pre Cert
  * \post Retorna si el string text conté el string paraula
  */

  vector<string> frases_x_fins_y(int x, int y);
  /**@brief Mètode per consultar frases d'un text
  * \pre Cert
  * \post Es retorna un vector que conté les frases x a y
  */

  int comptar_linies();
  /**@brief Mètode per consultar el nombre de línies d'un text
  * \pre Cert
  * \post Retorna el nombre de línies del paràmetre implícit
  */

  int comptar_paraules();
  /**@brief Mètode per consultar el nombre de paraules d'un text
  * \pre Cert
  * \post Retorna el nombre de paraules del text
  */

  bool existeix_paraula(string paraula);
  /**@brief Mètode per consultar si el p.i. conté una paraula
  * \pre S'ha seleccionat un text
  * \post Es retorna si la paraula es troba al text
  */

  bool avalua_frase_expressio(string expressio, string frase);
  /**@brief Mètode per avaluar una expressió booleana de paraules
  * \pre expressio és una expressió booleana de paraules vàlida
  * \post Retorna si la frase frase compleix l'expressió o no
  */

  // Lectura i escriptura

  void afegeix_contingut();
  /**@brief Mètode per afegir contingut al text
  * \pre S'ha llegit el títol del text i el seu autor, el contingut es troba al canal d'entrada estàndard
  * \post S'ha afegit el contingut llegit al p.i.
  */

  void imprimeix_linies(int primera_linia, int ultima_linia);
  /**@brief Mètode per imprimir unes determinades línies del text
  * \pre 0 <= primera_linia <= ultima_linia <= nombre de linies del paràmetre implícit
  * \post S'ha imprès les línies corresponets a la sortida estàndard
  */

  void escriure();
  /**@brief Mètode per escriure el text
  * \pre Cert
  * \post S'ha escrit el text pel canal estàndard de sortida
  */

  void imprimeix_nombre_frases();
  /**@brief Mètode per imprimir el nombre de frases del text
  * \pre Cert
  * \post S'ha imprès pel canal de sortida estàndard el nombre total d'elements del paràmetre implícit
  */

  void imprimeix_nombre_paraules();
  /**@brief Mètode per imprimir el nombre de paraules del text
  * \pre Cert
  * \post S'ha imprès pel canal de sortida estàndard el nombre total d'elements de frases
  */

  void imprimeix_taula_frequencies();
  /**@brief Mètode per imprimir la taula de freqüències de les paraules del text
  * \pre Cert
  * \post S'ha imprès pel canal de sortida estàndard les paraules de frases i la seva freqüència
  */

  void imprimeix_frases_paraules(vector<string> &paraules);
  /**@brief Mètode per imprimir les frases que continguin unes determinades paraules
  * \pre Cert
  * \post s'ha imprès pel canal de sortida estàndard els elements de frases que contenen la seqüència paraules
  */

};