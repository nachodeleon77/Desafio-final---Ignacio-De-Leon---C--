#include "Vendedor.h"

Vendedor::Vendedor(string nombre, string apellido, string codigo_vendedor) {
	this->Nombre = nombre;
	this->Apellido = apellido;
	this->CodigoVendedor = codigo_vendedor;
};

Vendedor::~Vendedor() {

}

void Vendedor::setNombre(string nombre) {
	this->Nombre = nombre;
};

string Vendedor::getNombre() {
	return this->Nombre;
}

void Vendedor::setApellido(string apellido) {
	this->Apellido = apellido;
};

string Vendedor::getApellido() {
	return this->Apellido;
}

void Vendedor::setCodigoVendedor(string codigo_vendedor) {
	this->CodigoVendedor = codigo_vendedor;
};

string Vendedor::getCodigoVendedor() {
	return this->CodigoVendedor;
}

void Vendedor::imprimirInfo() {
	cout << this->getNombre() << " " << this->getApellido() << " " << this->getCodigoVendedor();
}

void Vendedor::addHistorialCotizaciones(Cotizacion cotizacion) {
	this->HistorialCotizaciones.push_back(cotizacion);
}



void Vendedor::imprimirCotizaciones() {
	// declare iterator
	vector<Cotizacion>::iterator iter;

	// use iterator with for loop
	for (iter = this->HistorialCotizaciones.begin(); iter != this->HistorialCotizaciones.end(); ++iter) {
		cout << iter->getNumeroIdentificacion() << " "  << iter->getFechaCotizacion() ;
	}
}

vector<Cotizacion> Vendedor::getHistorialCotizaciones() {
	return this->HistorialCotizaciones;
}

int Vendedor::getProximoCodigoCotizacion() {
	if (HistorialCotizaciones.size() == 0) {
		return 10001;
	} else {
		Cotizacion c = HistorialCotizaciones.back();
		return 1 + c.getNumeroIdentificacion();
	}
}
