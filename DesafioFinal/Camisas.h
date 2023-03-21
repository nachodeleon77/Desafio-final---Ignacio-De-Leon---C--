#pragma once
#include "Prenda.h"
#include "Enums.h"

class Camisas : public Prenda
{
private:

	tipomanga manga;
	tipocuello cuello;
public:
	Camisas();
	~Camisas();
	void setManga(tipomanga manga);
	string getManga();
	void setCuello(tipocuello cuello);
	string getCuello();
};

