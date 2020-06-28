#pragma once
using namespace System::Drawing;
class Jugador {
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
	Jugador();
	~Jugador();
	Jugador(int _x, int _y);
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Dibujar_Invisible(BufferedGraphics^ buffer, Bitmap^ bmp);
	void Mover_Invisble(BufferedGraphics^ buffer, Bitmap^ bmp);
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

Jugador::Jugador() {

}

Jugador::~Jugador() {

}
Jugador::Jugador(int _x, int _y) {
	this->x = _x;
	this->y = _y;
	dx = 0;
	dy = 0;
	_direccion = ' ';
	_ultimatecla = ' ';
	ancho = 59;
	alto = 63;
	indicex = 0;
	indicey = 2;
}

void Jugador::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.9, alto*0.9);
	buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
}

void Jugador::Mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	switch (_direccion)	{
	case 'W':
		indicey = 0;
		if (indicex >= 0 && indicex < 2)indicex++;
		else indicex = 0;
		if (y >= 0) {
			dy = 10;
			y = y - dy;
		}
		_ultimatecla = 'W';
		break;
	case 'S':
		indicey = 2;
		if (indicex >= 0 && indicex < 2)indicex++;
		else indicex = 0;
		if (y + alto*1.1 <= buffer->Graphics->VisibleClipBounds.Height) {
			dy = 10;
			y = y + dy;
		}
		_ultimatecla = 'S';
		break;
	case 'D':
		indicey = 3;
		if (indicex >= 0 && indicex < 2)indicex++;
		else indicex = 0;
		if (x + ancho * 1 * 1 <= buffer->Graphics->VisibleClipBounds.Width) {
			dx = 10;
			x = x + dx;
		}
		_ultimatecla = 'D';
		break;
	case 'A':
		indicey = 1;
		if (indicex >= 0 && indicex < 2)indicex++;
		else indicex = 0;
		if (x >= 0) {
			dx = 10;
			x = x - dx;
		}
		_ultimatecla = 'A';
		break;
	case ' ':
		dx = 0; dy = 0;
		switch (_ultimatecla) {
		case 'W':
			indicex = 1; indicey = 3;
			break;
		case 'S':
			indicex = 1; indicey = 0;
			break;
		case 'A':
			indicex = 1; indicey = 1;
			break;
		case 'D':
			indicex = 1; indicey = 2;
			break;
		}
		break;
	}
}

void Jugador::Dibujar_Invisible(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	Rectangle aumentopersonaje = Rectangle(x, y, ancho*1.1, alto*1.1);
	buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
}
void Jugador::Mover_Invisble(BufferedGraphics^ buffer, Bitmap^ bmp) {
	switch (_direccion) {
	case 'W':
		indicey = 3;
		indicex = 0;
		if (y >= 0) {
			dy = 10;
			y = y - dy;
		}
		_ultimatecla = 'W';
		break;
	case 'S':
		indicey = 0;
		indicex = 0;
		if (y + alto*1.1 <= buffer->Graphics->VisibleClipBounds.Height) {
			dy = 10;
			y = y + dy;
		}
		_ultimatecla = 'S';
		break;
	case 'D':
		indicey = 2;
		indicex = 0;
		if (x + ancho * 1 * 1 <= buffer->Graphics->VisibleClipBounds.Width) {
			dx = 10;
			x = x + dx;
		}
		_ultimatecla = 'D';
		break;
	case 'A':
		indicey = 1;
		indicex = 0;
		if (x >= 0) {
			dx = 10;
			x = x - dx;
		}
		_ultimatecla = 'A';
		break;
	case ' ':
		dx = 0; dy = 0;
		switch (_ultimatecla) {
		case 'W':
			indicex = 0; indicey = 0;
			break;
		case 'S':
			indicex = 0; indicey = 0;
			break;
		case 'A':
			indicex = 0; indicey = 0;
			break;
		case 'D':
			indicex = 0; indicey = 0;
			break;
		}
		break;
	}
}


int Jugador::get_x() {
	return x;
}

int Jugador::get_y() {
	return y;
}

int Jugador::get_ancho() {
	return ancho;
}

int Jugador::get_alto() {
	return alto;
}
void Jugador::set_x(int _x) {
	this->x = _x;
}
void Jugador::set_y(int _y) {
	this->y = _y;
}
char Jugador::get_direccion() {
	return _direccion;
}
void Jugador::set_direccion(char __direccion) {
	this->_direccion = __direccion;
}
void Jugador::set_ultimatecla(char __ultimatecla) {
	this->_ultimatecla = __ultimatecla;
}
char Jugador::retorna_ultimatecla() {
	return _ultimatecla;
}