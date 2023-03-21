#pragma once
#include "Controller.h";
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

class View
{
private: 
	void realizarCotizacion();
	void camisaManga();
	void camisaCuello();
	void pantalonTipo();
	void calidadPrenda();
	void precioUnitario(int error);
	void cantidad(int error);
	void crearCotizacion();
	void imprimirCotizacionFinal(Cotizacion c);
	void imprimirCotizacion(vector<Cotizacion>::iterator c);
	void imprimirHistorial();
	void opciones();
	int tipoPrenda; // 1 - Camisas // 2 - Pantalon
	int tipocamisaManga; // 1 - Corta // 2 - Larga
	int tipoCuello; // 1 - Mao // 2 - Comun
	int tipoPantalon; // 1 - Comun // 2 - Chupin
	int tipoCalidad; // 1 - Standard // 2 - Premium
	double precio;
	int cantidadCotizar;
	int descuento;
	string tiendanombre, tiendadireccion;
	string vendedornombre, vendedorapellido;
	int vendedorcodigo;
	Controller* controller;
public:
	View();
	void mostrarMenu();
};

