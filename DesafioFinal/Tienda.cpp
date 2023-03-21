#include "Tienda.h"

Tienda::Tienda(string nombre, string Direccion) {
	setNombre(nombre);
	setDireccion(Direccion);
	initializeStock();
}

Tienda::~Tienda() {
	
}

void Tienda::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

string Tienda::getNombre() {
	return this->Nombre;
}

void Tienda::setDireccion(string Direccion) {
	this->Direccion = Direccion;
}

string Tienda::getDireccion() {
	return this->Direccion;
}

void Tienda::addPantalon(Pantalon p) {
	this->ListadoPantalones.push_back(p);
}

void Tienda::addCamisa(Camisas c) {
	this->ListadoCamisas.push_back(c);
}

void Tienda::mostrarPrendas() {

}

void Tienda::initializeStock() {
	// Camisas
	this->stockcamisa[E_Camisa][Corta][Mao][Standard] = 100;
	this->stockcamisa[E_Camisa][Corta][Mao][Premium] = 100;
	this->stockcamisa[E_Camisa][Corta][Comun][Standard] = 150;
	this->stockcamisa[E_Camisa][Corta][Comun][Premium] = 150;
	this->stockcamisa[E_Camisa][Larga][Mao][Standard] = 75;
	this->stockcamisa[E_Camisa][Larga][Mao][Premium] = 75;
	this->stockcamisa[E_Camisa][Larga][Comun][Standard] = 175;
	this->stockcamisa[E_Camisa][Larga][Comun][Premium] = 175;

	// Pantalones
	this->stockpantalon[E_Pantalon][Chupines][Standard] = 750;
	this->stockpantalon[E_Pantalon][Chupines][Premium] = 750;
	this->stockpantalon[E_Pantalon][Comunes][Standard] = 250;
	this->stockpantalon[E_Pantalon][Comunes][Premium] = 250;
}

int Tienda::getStockCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad) {
	return this->stockcamisa[E_Camisa][manga][cuello][calidad];
}

int Tienda::getStockPantalones(tipo tipopantalon, tipocalidad calidad) {
	return this->stockpantalon[E_Pantalon][tipopantalon][calidad];
}

int Tienda::getDescuentoCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad) {
	int descuento = 0;
	if (manga == Corta) {
		descuento = descuento + 10;
	}
	if (cuello == Mao) {
		descuento = descuento - 3;
	}
	if (calidad == Premium) {
		descuento = descuento - 30;
	}
	return descuento;
}
	
int Tienda::getDescuentoPantalones(tipo tipopantalon, tipocalidad calidad) {
	int descuento = 0;
	if (tipopantalon == Chupines) {
		descuento = descuento + 12;
	}
	if (tipopantalon == Premium) {
		descuento = descuento - 30;
	}
	return descuento;
}