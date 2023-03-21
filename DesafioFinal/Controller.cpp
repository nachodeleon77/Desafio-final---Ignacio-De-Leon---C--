#include "Controller.h"

Controller::Controller() {
	tienda = new Tienda("<Nombre de la tienda>", "<Direccion de la tienda>");
	vendedor = new Vendedor("<Nombre>", "<Apellido>", "<Codigo del Vendedor>");
	loadOptionsFromFile();
	loadHistorialFromFile();
}

Controller::~Controller() {
	
}

void Controller::setTiendaName(string nombre) {
	tienda->setNombre(nombre);
}

string Controller::getTiendaName() {
	return tienda->getNombre();
}

void Controller::setTiendaDireccion(string direccion) {
	tienda->setDireccion(direccion);
}

string Controller::getTiendaDireccion() {
	return tienda->getDireccion();
}

void Controller::setVendedorNombre(string nombre) {
	vendedor->setNombre(nombre);
}

string Controller::getVendedorNombre() {
	return vendedor->getNombre();
}

void Controller::setVendedorApellido(string apellido) {
	vendedor->setApellido(apellido);
}

string Controller::getVendedorApellido() {
	return vendedor->getApellido();
}

void Controller::setVendedorCodigo(string codigo) {
	vendedor->setCodigoVendedor(codigo);
}

string Controller::getVendedorCodigo() {
	return vendedor->getCodigoVendedor();
}

vector<Cotizacion> Controller::getVendedorHistorialCotizaciones() {
	return vendedor->getHistorialCotizaciones();
}

void Controller::saveOptions() {
	ofstream MyFile("options.txt");
	MyFile << this->getTiendaName() << "\n";
	MyFile << this->getTiendaDireccion() << "\n";
	MyFile << this->getVendedorNombre() << "\n";
	MyFile << this->getVendedorApellido() << "\n";
	MyFile << this->getVendedorCodigo() << "\n";
	MyFile.close();
}

void Controller::loadOptionsFromFile() {
	string myText;
	ifstream MyReadFile("options.txt");
	int line = 0;
	while (getline(MyReadFile, myText)) {
		if (line == 0) {
			this->setTiendaName(myText);
		} else if (line == 1) {
			this->setTiendaDireccion(myText);
		} else if (line == 2) {
			this->setVendedorNombre(myText);
		} else if (line == 3) {
			this->setVendedorApellido(myText);
		} else if (line == 4) {
			this->setVendedorCodigo(myText);
		}
		line++;
		//cout << myText;
	}
	MyReadFile.close();
}

void Controller::addVendedorHistorialCotizaciones(Cotizacion c) {
	vendedor->addHistorialCotizaciones(c);
}

int Controller::getProximoNumeroIdentificadorCotizacion() {
	return vendedor->getProximoCodigoCotizacion();
}

int Controller::getTiendaStockCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad) {
	return tienda->getStockCamisas(manga, cuello, calidad);
}
int Controller::getTiendaStockPantalones(tipo tipopantalon, tipocalidad calidad) {
	return tienda->getStockPantalones(tipopantalon, calidad);
}

int Controller::getTiendaStockDescuentoCamisas(tipomanga manga, tipocuello cuello, tipocalidad calidad) {
	return tienda->getDescuentoCamisas(manga,cuello,calidad);
}
int Controller::getTiendaStockDescuentoPantalones(tipo tipopantalon, tipocalidad calidad) {
	return tienda->getDescuentoPantalones(tipopantalon,calidad);
}

void Controller::saveCotizacionOnFile(Cotizacion c) {
	ofstream MyFile;
	MyFile.open("historial.txt", std::ios::app);
	MyFile << c.getNumeroIdentificacion() << "ƒ";
	MyFile << c.getFechaCotizacionRaw() << "ƒ";
	MyFile << c.getCodigoVendedor() << "ƒ";
	MyFile << c.getPrenda() << "ƒ";
	MyFile << c.getPrecio() << "ƒ";
	MyFile << c.getCantidad() << "ƒ";
	MyFile << c.getDescuento() << "ƒ";
	MyFile << c.getResultado() << "\n";
	MyFile.close();
}

void Controller::loadHistorialFromFile() {
	string myText;
	ifstream MyReadFile("historial.txt");
	Cotizacion c(0);
	vector<std::string> val;
	while (getline(MyReadFile, myText)) {
		val = explode(myText, 'ƒ');
		c.setNumeroIdentificacion(stoi(val[0]));
		c.setFechaCotizacion((time_t)std::stoi(val[1]));
		c.setCodigoVendedor(val[2]);
		c.setPrenda(val[3]);
		c.setPrecio(stod(val[4]));
		c.setCantidad(stoi(val[5]));
		c.setDescuento(stoi(val[6]));
		c.setResultado(stod(val[7]));
		vendedor->addHistorialCotizaciones(c);
	}
	MyReadFile.close();
}

std::vector<std::string> explode(std::string const& s, char delim)
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}

	return result;
}