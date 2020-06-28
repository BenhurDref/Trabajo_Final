#pragma once
using namespace System::Drawing;

class BalaEnemigo {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indicex;
	int indicey;
	char _direccion;
	bool activador;
public:
	BalaEnemigo();
	BalaEnemigo(int _x, int _y, char __direccion);
	~BalaEnemigo();
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp);
	void set_direccion(char __direccion);
	void set_x(int _x);
	void set_y(int _y);
	int Get_x();
	int Get_y();
	int Get_ancho();
	int Get_alto();
	char get_direccion();
	void set_activador(bool _activador);
	bool get_activador();
};

BalaEnemigo::BalaEnemigo() {

}

BalaEnemigo::BalaEnemigo(int _x, int _y, char __direccion) {
	x = _x;
	y = _y;
	dx = 0;
	dy = 0;
	ancho = 512;
	alto = 512;
	indicex = 0;
	indicey = 0;
	this->_direccion = __direccion;
}

BalaEnemigo::~BalaEnemigo() {

}

void BalaEnemigo::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.03, alto*0.03);
	buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
}

void BalaEnemigo::Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	switch (_direccion) {
	case 'W':
		indicey = 0;
		indicex = 0;
		dy = -15;
		y = y + dy;
		break;
	case 'S':
		indicey = 0;
		indicex = 0;
		dy = 15;
		y = y + dy;
		break;
	case 'D':
		indicey = 0;
		indicex = 0;
		dx = 15;
		x = x + dx;
		break;
	case 'A':
		indicey = 0;
		indicex = 0;
		dx = -15;
		x = x + dx;
		break;
	}
}

int BalaEnemigo::Get_x() {
	return x;
}

int BalaEnemigo::Get_y() {
	return y;
}

int BalaEnemigo::Get_ancho() {
	return ancho;
}

int BalaEnemigo::Get_alto() {
	return alto;
}

void BalaEnemigo::set_direccion(char __direccion) {
	this->_direccion = __direccion;
}

char BalaEnemigo::get_direccion() {
	return _direccion;
}
void BalaEnemigo::set_x(int _x) {
	this->x = _x;
}
void BalaEnemigo::set_y(int _y) {
	this->y = _y;
}
void BalaEnemigo::set_activador(bool _activador) {
	this->activador = _activador;
}
bool BalaEnemigo::get_activador() {
	return activador;
}