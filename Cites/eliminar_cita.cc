#include "Cites.hh"

void Cites::eliminar_cita(string referencia) {
	string referencia_sense_numero;
	int n = referencia_sense_numero.size();
	while (referencia_sense_numero[n-1] >= '0' and referencia_sense_numero[n-1] <= '9') {
		referencia_sense_numero.pop_back();
		n--;
	}
	cites.erase(referencia);
	map<string, int>::iterator i = cites.();
	if (referencies[referencia_sense_numero] > 0)
		referencies[referencia_sense_numero]--;
	else
		referencies.erase(referencia_sense_numero);
}