#include "Cotizacion.h"

Cotizacion::Cotizacion(int num) {
	this->NumeroIdentificacion = num;
	this->FechaCotizacion = time(0);
}

Cotizacion::~Cotizacion() {
	//cout << "Destructor Cotizacion";
}

void Cotizacion::setNumeroIdentificacion(int NumeroIdentificacion) {
	this->NumeroIdentificacion = NumeroIdentificacion;
}

int Cotizacion::getNumeroIdentificacion() {
	return this->NumeroIdentificacion;
}

void Cotizacion::setFechaCotizacion(time_t fecha) {
	this->FechaCotizacion = fecha;
}

string Cotizacion::getFechaCotizacion() {
    char buffer[80];
    std::strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", localtime(&this->FechaCotizacion));
    std::string result(buffer);
	return result;
}

time_t Cotizacion::getFechaCotizacionRaw() {
	return this->FechaCotizacion;
}

void Cotizacion::setCodigoVendedor(string CodigoVendedor) {
	this->CodigoVendedor = CodigoVendedor;
}

string Cotizacion::getCodigoVendedor() {
	return this->CodigoVendedor;
}

void Cotizacion::setCantidad(int Cantidad) {
	this->Cantidad = Cantidad;
}

int Cotizacion::getCantidad() {
	return this->Cantidad;
}

void Cotizacion::setPrecio(double Precio) {
	this->Precio = Precio;
}

double Cotizacion::getPrecio() {
	return this->Precio;
}

void Cotizacion::setPrenda(string prenda) {
	this->Prenda = prenda;
}

string Cotizacion::getPrenda() {
	return this->Prenda;
}

void Cotizacion::setResultado(double Resultado) {
	this->Resultado = Resultado;
}

double Cotizacion::getResultado() {
	return this->Resultado;
}

void Cotizacion::imprimir() {
	cout << this->NumeroIdentificacion << " " << this->getFechaCotizacion();
}

void Cotizacion::setDescuento(int Descuento) {
	this->Descuento = Descuento;
}
int Cotizacion::getDescuento() {
	return this->Descuento;
}