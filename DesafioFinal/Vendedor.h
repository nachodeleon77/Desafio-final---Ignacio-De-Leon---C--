#pragma once

#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <string>
#include<iostream>
#include <vector>
#include "Cotizacion.h"
#include "Tienda.h"


using namespace std;


class Vendedor
{
private:
	string Nombre;
	string Apellido;
	string CodigoVendedor;
	vector<Cotizacion> HistorialCotizaciones;
	int UltimoCodigoCotizacion = 1;
public:
	Vendedor(string Nombre, string Apellido, string CodigoVendedor);
	~Vendedor();
	void setNombre(string nombre);
	string getNombre();
	void setApellido(string apellido);
	string getApellido();
	void setCodigoVendedor(string codigo_vendedor);
	string getCodigoVendedor();
	vector<Cotizacion> getHistorialCotizaciones();
	void imprimirInfo();
	void addHistorialCotizaciones(Cotizacion cotizacion);
	int getProximoCodigoCotizacion();
	void imprimirCotizaciones();
};

#endif