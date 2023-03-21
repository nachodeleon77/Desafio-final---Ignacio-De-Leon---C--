#ifndef COTIZACION_HPP
#define COTIZACION_HPP

#include <string>
#include<iostream>
#include <time.h>
#include "Prenda.h"
#pragma once
#pragma warning(disable : 4996)

using namespace std;

class Cotizacion
{
private:
	int NumeroIdentificacion;
	time_t FechaCotizacion;
	string CodigoVendedor;
	string Prenda;
	int Cantidad;
	double Resultado;
	double Precio;
	int Descuento;
public:
	Cotizacion(int setNumeroIdentificacion);
	~Cotizacion();
	void setNumeroIdentificacion(int NumeroIdentificacion);
	void setFechaCotizacion();
	void setCodigoVendedor(string CodigoVendedor);
	void setPrenda(string prenda);
	void setCantidad(int Cantidad);
	void setResultado(double Resultado);
	void setPrecio(double precio);
	int getNumeroIdentificacion();
	string getFechaCotizacion();
	string getCodigoVendedor();
	int getCantidad();
	double getPrecio();
	string getPrenda();
	double getResultado();
	void imprimir();
	void setDescuento(int Descuento);
	int getDescuento();
};

#endif
