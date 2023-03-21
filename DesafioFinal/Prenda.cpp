#include "Prenda.h"

Prenda::Prenda() {
	setcalidad(Premium);
	setPrecio(0);
}

Prenda::~Prenda() {
	//cout << "Prenda";
}

string Prenda::getcalidad() {
	switch (this->calidad) {
		case Standard:
			return "Standard";
		case Premium:
			return "Premium";
		default:
			return "Otra";
	}
}

void Prenda::setcalidad(tipocalidad c) {
	this->calidad = c;
}

void Prenda::setPrecio(double precio) {
	this->preciounitario = precio;
}

double Prenda::getPrecio() {
	return this->preciounitario;
}
