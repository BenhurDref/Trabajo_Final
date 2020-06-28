#pragma once
using namespace System::Drawing;
class BalaJugador {
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indicex;
	int indicey;
	char _direccion;
	char _ultimatecla;
public:
	BalaJugador();
	~BalaJugador();
	BalaJugador(int _x, int _y, char __direccion);
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp);
	void set_x(int _x);
	void set_y(int _y);
	int get_x();
	int get_y();
	int get_ancho();
	int get_alto();
	char get_direccion();
	void set_direccion(char __direccion);
	void set_ultimatecla(char __ultimatecla);
	char retorna_ultimatecla();
};

BalaJugador::BalaJugador() {

}

BalaJugador::~BalaJugador() {

}
BalaJugador::BalaJugador(int _x, int _y, char __direccion) {
	this->x = _x;
	this->y = _y;
	this->_direccion = __direccion;
	if (_direccion == 'W') { dx = 0; dy = -15; }
	if (_direccion == 'S') { dx = 0; dy = 15; }
	if (_direccion == 'D') { dx = 15; dy = 0; }
	if (_direccion == 'A') { dx = -15; dy = 0; }
	ancho = 1000;
	alto = 1000;
	indicex = 0;
	indicey = 0;
}

void BalaJugador::Dibujar(BufferedGraphics^ buffer, Bitmap^ img) {
	
	ancho = img->Width / 2;
	alto = img->Height / 3;

	indicex = (indicex + 1) % 2;

	/*ancho = img->Width / 2;
		alto = img->Height / 3;

		Rectangle corte = Rectangle(IDx * ancho, IDy * alto, ancho, alto);

		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		IDx = (IDx + 1) % 2;
	*/

	Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.2, alto*0.2);
	buffer->Graphics->DrawImage(img, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
}

void BalaJugador::Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	switch (_direccion) {
	case 'W':
		indicey = 0;
		indicex = 0;
		y = y + dy;
		_ultimatecla = 'W';
		break;
	case 'S':
		indicey = 0;
		indicex = 0;
		y = y + dy;
		_ultimatecla = 'S';
		break;
	case 'D':
		indicey = 0;
		indicex = 0;
		x = x + dx;
		_ultimatecla = 'D';
		break;
	case 'A':
		indicey = 0;
		indicex = 0;
		x = x + dx;
		_ultimatecla = 'A';
		break;
	}
}

int BalaJugador::get_x() {
	return x;
}

int BalaJugador::get_y() {
	return y;
}

int BalaJugador::get_ancho() {
	return ancho;
}

int BalaJugador::get_alto() {
	return alto;
}
void BalaJugador::set_x(int _x) {
	this->x = _x;
}
void BalaJugador::set_y(int _y) {
	this->y = _y;
}
char BalaJugador::get_direccion() {
	return _direccion;
}
void BalaJugador::set_direccion(char __direccion) {
	this->_direccion = __direccion;
}
void BalaJugador::set_ultimatecla(char __ultimatecla) {
	this->_ultimatecla = __ultimatecla;
}
char BalaJugador::retorna_ultimatecla() {
	return _ultimatecla;
}