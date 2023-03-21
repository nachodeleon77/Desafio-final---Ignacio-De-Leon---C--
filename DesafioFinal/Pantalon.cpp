#include "Pantalon.h"


Pantalon::Pantalon() {
	setTipo(Chupines);
}

Pantalon::~Pantalon() {

}

void Pantalon::setTipo(tipo t) {
	this->tipopant = t;
}

string Pantalon::getTipo() {
	switch (this->tipopant) {
		case Comunes:
			return "Comunes";
		case Chupines:
			return "Chupines";
		default:
			return "Otro";
	}
}

