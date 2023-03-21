#pragma once
#include "Tienda.h"
#include "Vendedor.h"
#include <fstream>

class Controller
{
private:
	Tienda* tienda;
	Vendedor* vendedor;
public:
	Controller();
	~Controller();
	void setTiendaName(string nombre);
	string getTiendaName();
	void setTiendaDireccion(string direccion);
	string getTiendaDireccion();
	int getTiendaStockCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad);
	int getTiendaStockPantalones(tipo tipopantalon, tipocalidad calidad);
	int getTiendaStockDescuentoCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad);
	int getTiendaStockDescuentoPantalones(tipo tipopantalon, tipocalidad calidad);
	void setVendedorNombre(string nombre);
	string getVendedorNombre();
	void setVendedorApellido(string apellido);
	string getVendedorApellido();
	void setVendedorCodigo(string codigo);
	string getVendedorCodigo();
	vector<Cotizacion> getVendedorHistorialCotizaciones();
	void addVendedorHistorialCotizaciones(Cotizacion c);
	int getProximoNumeroIdentificadorCotizacion();
	void saveOptions();
	void loadOptionsFromFile();

};

