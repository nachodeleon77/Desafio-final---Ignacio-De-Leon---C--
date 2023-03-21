#include "View.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define esc 27

View::View() {
	controller = new Controller();
	mostrarMenu();
}

void View::mostrarMenu() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - MENU PRINCIPAL\n";
	cout << "-----------------------------------------------------\n";
	cout << controller->getTiendaName() << " | " << controller->getTiendaDireccion() << "\n";
	cout << "-----------------------------------------------------\n";
	cout << controller->getVendedorNombre() << " " << controller->getVendedorApellido() << " | Codigo del Vendedor: " << controller->getVendedorCodigo() << "\n";
	cout << "-----------------------------------------------------\n";
	cout << "\n";
	cout << "1) Historial de Cotizaciones\n";
	cout << "2) Realizar Cotizacion\n";
	cout << "3) Opciones\n";
	cout << "4) Salir\n";
	cout << "\n";
	cout << "SELECCIONE UNA OPCION DEL MENU: ";
	char ch = _getch();
	cout << ch;
	switch (ch) {
		case '1':
			imprimirHistorial();
			break;
		case '2':
			realizarCotizacion();
			break;
		case '3':
			opciones();
			break;
		case '4':
			exit(0);
			break;
		default:
			mostrarMenu();
	}
}

void View::realizarCotizacion() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "-----------------------------------------------------\n";
	cout << "Paso 1 - ¿Que tipo de producto deseas cotizar? \n";
	cout << "--------------------------------------------------------\n";
	cout << "\n";
	cout << "1) Camisa\n";
	cout << "2) Pantalon\n";
	cout << "--------------------------\n";
	cout << "esc) Volver\n";
	cout << "\n";
	cout << "SELECCIONE UNA OPCION DEL MENU: ";
	char ch = _getch();
	cout << ch;
	switch (ch) {
	case '1':
		tipoPrenda = 1;
		camisaManga();
		break;
	case '2':
		tipoPrenda = 2;
		pantalonTipo();
		break;
	case esc:
		mostrarMenu();
		break;
	default:
		realizarCotizacion();
	}
}

void View::camisaManga() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Paso 2a - La camisa a cotizar. ¿Que tipo de manga tiene? \n";
	cout << "--------------------------------------------------------\n";
	cout << "\n";
	cout << "1) Corta\n";
	cout << "2) Larga\n";
	cout << "--------------------------\n";
	cout << "esc) Volver al paso anterior\n";
	cout << "\n";
	cout << "SELECCIONE UNA OPCION DEL MENU: ";
	char ch = _getch();
	cout << ch;
	switch (ch) {
	case '1':
		tipocamisaManga = 1;
		camisaCuello();
		break;
	case '2':
		tipocamisaManga = 2;
		camisaCuello();
		break;
	case esc:
		realizarCotizacion();
		break;
	default:
		camisaManga();
	}
}

void View::camisaCuello() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Paso 2b - La camisa a cotizar. ¿Que tipo de cuello tiene? \n";
	cout << "--------------------------------------------------------\n";
	cout << "\n";
	cout << "1) Mao\n";
	cout << "2) Comun\n";
	cout << "--------------------------\n";
	cout << "esc) Volver al paso anterior\n";
	cout << "\n";
	cout << "SELECCIONE UNA OPCION DEL MENU: ";
	char ch = _getch();
	cout << ch;
	switch (ch) {
	case '1':
		tipoCuello = 1;
		calidadPrenda();
		break;
	case '2':
		tipoCuello = 2;
		calidadPrenda();
		break;
	case esc:
		camisaManga();
		break;
	default:
		camisaCuello();
	}
}

void View::pantalonTipo() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Paso 2 - El pantalon a cotizar. ¿Que tipo es? \n";
	cout << "--------------------------------------------------------\n";
	cout << "\n";
	cout << "1) Comun\n";
	cout << "2) Chupin\n";
	cout << "--------------------------\n";
	cout << "esc) Volver al paso anterior\n";
	cout << "\n";
	cout << "SELECCIONE UNA OPCION DEL MENU: ";
	char ch = _getch();
	cout << ch;
	switch (ch) {
	case '1':
		tipoPantalon = 1;
		calidadPrenda();
		break;
	case '2':
		tipoPantalon = 2;
		calidadPrenda();
		break;
	case esc:
		realizarCotizacion();
		break;
	default:
		pantalonTipo();
	}
}

void View::calidadPrenda() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Paso 3 - Seleccione la calidad de la prenda \n";
	cout << "--------------------------------------------------------\n";
	cout << "\n";
	cout << "1) Standard\n";
	cout << "2) Premium\n";
	cout << "--------------------------\n";
	cout << "esc) Volver al paso anterior\n";
	cout << "\n";
	cout << "SELECCIONE UNA OPCION DEL MENU: ";
	char ch = _getch();
	cout << ch;
	switch (ch) {
	case '1':
		tipoCalidad = 1;
		precioUnitario();
		break;
	case '2':
		tipoCalidad = 2;
		precioUnitario();
		break;
	case esc:
		if (tipoPrenda == 1) {
			camisaCuello();
		} else if (tipoPrenda == 2) {
			pantalonTipo();
		}
		break;
	default:
		calidadPrenda();
	}
}

void View::precioUnitario() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Paso 4 - Ingrese el precio unitario de la prenda \n";
	cout << "--------------------------------------------------------\n";
	cout << "\n";
	cout << "PRECIO UNITARIO: ";
	cin >> precio;
	cantidad(0);
}

void View::cantidad(int error) {
	tipomanga e_tipomanga; // { Corta, Larga };
	tipocuello e_tipocuello; // { Mao, Comun };
	tipo e_tipo; // { Comunes, Chupines };
	tipocalidad e_tipocalidad; // { Standard, Premium };
	tipoprenda e_tipoprenda; // { E_Camisa, E_Pantalon };
	int stock;

	if (tipoCalidad == 1) {
		e_tipocalidad = Standard;
	}
	else if (tipoCalidad == 2) {
		e_tipocalidad = Premium;
	}

	if (tipoPrenda == 1) {
		if (tipocamisaManga == 1) {
			e_tipomanga = Corta;
		}
		else if (tipocamisaManga == 2) {
			e_tipomanga = Larga;
		}

		if (tipoCuello == 1) {
			e_tipocuello = Mao;
		}
		else if (tipoCuello == 2) {
			e_tipocuello = Comun;
		}
		stock = controller->getTiendaStockCamisas(e_tipomanga, e_tipocuello, e_tipocalidad);
		descuento = controller->getTiendaStockDescuentoCamisas(e_tipomanga, e_tipocuello, e_tipocalidad);
	} else if (tipoPrenda == 2) {
		if (tipoPantalon == 1) {
			e_tipo = Comunes;
		}
		else if (tipoPantalon == 2) {
			e_tipo = Chupines;
		}
		stock = controller->getTiendaStockPantalones(e_tipo, e_tipocalidad);
		descuento = controller->getTiendaStockDescuentoPantalones(e_tipo, e_tipocalidad);
	}

	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Paso 5 - Ingrese cantidad de unidades a cotizar \n";
	cout << "--------------------------------------------------------\n";
	cout << "Existencia en Stock: " << stock  << "\n";
	cout << "--------------------------------------------------------\n";
	if (error == 1) {
		cout << "LA CANTIDAD SELECCIONADA EXCEDE EL STOCK DISPONIBLE \n";
		cout << "--------------------------------------------------------\n";
	}
	cout << "\n";
	cout << "CANTIDAD a COTIZAR: ";
	cin >> cantidadCotizar;
	if (cantidadCotizar <= stock) {
		crearCotizacion();
	} else {
		cantidad(1);
	}	
}

void View::imprimirCotizacionFinal(Cotizacion cotizacion) {
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Numero de Identificador: " << cotizacion.getNumeroIdentificacion() << "\n";
	cout << "Fecha y Hora de la cotizacion: " << cotizacion.getFechaCotizacion() << "\n";
	cout << "Codigo del Vendedor: " << cotizacion.getCodigoVendedor() << "\n";
	cout << "Prenda Cotizada: " << cotizacion.getPrenda() << "\n";
	cout << "Precio Unitario: " << "$" << cotizacion.getPrecio() << "\n";
	cout << "Cantidad de Unidades Cotizadas: " << cotizacion.getCantidad() << "\n";
	cout << "Descuento: " << descuento << "%\n";
	cout << "Precio Final: " << "$" << cotizacion.getResultado() << "\n";
	cout << "--------------------------------------------------------\n";
	cout << "Presione cualquier tecla para volver al menu principal";
	_getch();
	mostrarMenu();
}

void View::imprimirHistorial() {
	system("CLS");
	cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES\n";
	cout << "-----------------------------------------------------\n";
	cout << controller->getTiendaName() << " | " << controller->getTiendaDireccion() << "\n";
	cout << "-----------------------------------------------------\n";
	cout << controller->getVendedorNombre() << " " << controller->getVendedorApellido() << " | Codigo del Vendedor: " << controller->getVendedorCodigo() << "\n";
	vector<Cotizacion> historialcotizaciones = controller->getVendedorHistorialCotizaciones();
	vector<Cotizacion>::iterator iter;

	if (historialcotizaciones.size() > 0) {
		for (iter = historialcotizaciones.begin(); iter != historialcotizaciones.end(); ++iter) {
			imprimirCotizacion(iter);
		}
		cout << "--------------------------------------------------------\n";
		cout << "Presione cualquier tecla para volver al menu principal";
		_getch();
		mostrarMenu();
	} else {
		cout << "-----------------------------------------------------\n";
		cout << "\n";
		cout << "No hay cotizaciones aun\n";
		cout << "\n";
		cout << "--------------------------------------------------------\n";
		cout << "Presione cualquier tecla para volver al menu principal";
		_getch();
		mostrarMenu();
	}
	
}

void View::imprimirCotizacion(vector<Cotizacion>::iterator c) {

	cout << "--------------------------------------------------------\n";
	cout << "Numero de Identificador: " << c->getNumeroIdentificacion() << "\n";
	cout << "Fecha y Hora de la cotizacion: " << c->getFechaCotizacion() << "\n";
	cout << "Codigo del Vendedor: " << c->getCodigoVendedor() << "\n";
	cout << "Prenda Cotizada: " << c->getPrenda() << "\n";
	cout << "Precio Unitario: " << "$" << c->getPrecio() << "\n";
	cout << "Cantidad de Unidades Cotizadas: " << c->getCantidad() << "\n";
	cout << "Descuento: " << c->getDescuento() << "%\n";
	cout << "Precio Final: " << "$" << c->getResultado() << "\n";
}

void View::crearCotizacion() {
	string codigovendedor = controller->getVendedorCodigo();
	string nombreprenda = "";

	if (tipoPrenda == 1) {
		nombreprenda = "Camisa";
		if (tipocamisaManga == 1) {
			nombreprenda += " Manga Corta";
		}
		else if (tipocamisaManga == 2) {
			nombreprenda += " Manga Larga";
		}
		if (tipoCuello == 1) {
			nombreprenda += " (Cuello Mao)";
		}
		else if (tipoCuello == 2) {
			nombreprenda += " (Cuello Comun)";
		}

	}
	else if (tipoPrenda == 2) {
		nombreprenda = "Pantalon";
		if (tipoPantalon == 1) {
			nombreprenda += " Comun";
		}
		else if (tipoPantalon == 2) {
			nombreprenda += " Chupin";
		}
	}

	if (tipoCalidad == 1) {
		nombreprenda += " - Standard";
	}
	else if (tipoCalidad == 2) {
		nombreprenda += " - Premium";
	}
	Cotizacion c(0);
	c.setNumeroIdentificacion(controller->getProximoNumeroIdentificadorCotizacion());
	c.setFechaCotizacion(time(0));
	c.setCodigoVendedor(controller->getVendedorCodigo());
	c.setPrecio(precio);
	c.setPrenda(nombreprenda);
	c.setCantidad(cantidadCotizar);
	c.setDescuento(descuento);
	c.setResultado((precio * cantidadCotizar) * (100-descuento)/100);
	controller->addVendedorHistorialCotizaciones(c);
	controller->saveCotizacionOnFile(c);
	imprimirCotizacionFinal(c);
}

void View::opciones() {
	system("CLS");
	string tienda_nombre, tienda_direccion, vendedor_nombre, vendedor_apellido, vendedor_codigo;
	int ;

	cout << "COTIZADOR EXPRESS - COTIZAR\n";
	cout << "--------------------------------------------------------\n";
	cout << "Ingrese el nombre de la TIENDA: ";
	getline(std::cin, tienda_nombre);
	controller->setTiendaName(tienda_nombre);

	cout << "Ingrese el direccion de la TIENDA: ";
	getline(std::cin, tienda_direccion);
	controller->setTiendaDireccion(tienda_direccion);

	cout << "Ingrese el nombre del VENDEDOR: ";
	getline(std::cin, vendedor_nombre);
	controller->setVendedorNombre(vendedor_nombre);

	cout << "Ingrese el apellido del VENDEDOR: ";
	getline(std::cin, vendedor_apellido);
	controller->setVendedorApellido(vendedor_apellido);

	cout << "Ingrese el codigo del VENDEDOR: ";
	getline(std::cin, vendedor_codigo);
	controller->setVendedorCodigo(vendedor_codigo);

	controller->saveOptions();
	mostrarMenu();
}

