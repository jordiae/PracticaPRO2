#include "Cjt_autors.hh"

void Cjt_autors::eliminar_cita() {
	string referencia;
	primera_linea.ignore(10, '"');
	primera_linea >> referencia;
	referencia.erase(referencia.size() - 1, 1);
	cites.eliminar_cita(referencia);
}
