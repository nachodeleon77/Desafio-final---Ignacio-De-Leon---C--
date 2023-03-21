#pragma once

#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <string>
#include<iostream>
#include <vector>
#include "Pantalon.h"
#include "Camisas.h"

using namespace std;

class Tienda
{
private:
	string Nombre;
	string Direccion;
	vector<Pantalon> ListadoPantalones;
	vector<Camisas> ListadoCamisas;
	int stockcamisa[2][2][2][2];
	int stockpantalon[2][2][2];
public:
	Tienda(string nombre, string Direccion);
	~Tienda();
	void setNombre(string Nombre);
	void setDireccion(string Direccion);
	string getNombre();
	string getDireccion();
	void addPantalon(Pantalon p);
	void addCamisa(Camisas c);
	void mostrarPrendas();
	void initializeStock();
	int getStockCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad);
	int getStockPantalones(tipo tipopantalon, tipocalidad calidad);
	int getDescuentoCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad);
	int getDescuentoPantalones(tipo tipopantalon, tipocalidad calidad);
};

#endif
