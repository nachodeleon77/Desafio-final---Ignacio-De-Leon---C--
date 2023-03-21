#pragma once
#ifndef PRENDA_HPP
#define PRENDA_HPP

#include <string>
#include <iostream>
#include "Enums.h"

using namespace std;


class Prenda
{
private:
	tipocalidad calidad;
	double preciounitario;
	int cantidadenstock;
public:
	Prenda();
	~Prenda();
	virtual void setcalidad(tipocalidad c);
	string getcalidad();
	void setPrecio(double precio);
	double getPrecio();
};

#endif

