#include "Camisas.h"


Camisas::Camisas() {
	setManga(Corta);
	setCuello(Comun);
}

Camisas::~Camisas() {

}


void Camisas::setManga(tipomanga manga) {
	this->manga = manga;
}

string Camisas::getManga() {
	switch (this->manga) {
		case Corta:
			return "Corta";
		case Larga:
			return "Larga";
		default:
			return "Otra";
	}
}

void Camisas::setCuello(tipocuello cuello) {
	this->cuello = cuello;
}

string Camisas::getCuello() {
	switch (this->cuello) {
		case Mao:
			return "Mao";
		case Comun:
			return "Comun";
		default:
			return "Otra";
	}
}

