#include "Cites.hh"

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

  void afegir_cita(int frase_inicial, int frase_final, vector<string> frases);
  /* Pre: cert */
  /* Post: s'ha afegit una cita al paràmetre implícit */

  Cites::afegir_cita(int frase_inicial, int frase_final, vector<string> frases, nom_autor, titol_text) {
  	cita c;
  	c.autor = nom_autor;
  	c.titol_text = titol_text;
  	c.frase_inicial = frase_inicial;
  	c.frase_final = frase_final;
  	c.frases = frases;

    string referencia; // falten inicials

  	cites.insert(make_pair(referencia,c));
  }