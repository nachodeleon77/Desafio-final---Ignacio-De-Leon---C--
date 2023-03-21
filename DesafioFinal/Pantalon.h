#pragma once
#include "Prenda.h"
#include "Enums.h"

class Pantalon: public Prenda
{
	tipo tipopant;
public:
	Pantalon();
	~Pantalon();
	void setTipo(tipo t);
	string getTipo();
};

