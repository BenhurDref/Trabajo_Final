#pragma once
using namespace System::Drawing;
class Enemigo {
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
public:
	Enemigo(int _x, int _y, char __direccion, int tipo);
	~Enemigo();

	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo);

	void DibujarInvisible(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo);
	void MoverInvisible(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo);

	void set_direccion(char __direccion);
	int get_x();
	int get_y();
	int get_ancho();
	int get_alto();
	char get_direccion();
	void change_dx();
	void change_dy();
};
Enemigo::Enemigo(int _x, int _y, char __direccion, int tipo) {
	if (tipo == 1) {
		x = _x;
		y = _y;
		ancho = 64;
		alto = 64;
		_direccion = __direccion;
		if (_direccion == 'W') { indicex = 0; indicey = 0; dx = 10; dy = -10; }
		if (_direccion == 'S') { indicex = 0; indicey = 2; dx = 10; dy = 10; }
		if (_direccion == 'A') { indicex = 0; indicey = 1; dx = -10; dy = 10; }
		if (_direccion == 'D') { indicex = 0; indicey = 3; dx = 10; dy = 10; }
	}
	if (tipo == 2) {
		x = _x;
		y = _y;
		dx = 10;
		dy = 10;
		ancho = 64;
		alto = 64;
		_direccion = __direccion;
		if (_direccion == 'W') { indicex = 0; indicey = 0; dx = 10; dy = -10; }
		if (_direccion == 'S') { indicex = 0; indicey = 2; dx = 10; dy = 10; }
		if (_direccion == 'A') { indicex = 0; indicey = 1; dx = -10; dy = 10; }
		if (_direccion == 'D') { indicex = 0; indicey = 3; dx = 10; dy = 10; }
	}
}
Enemigo::~Enemigo() {
}

void Enemigo::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo) {
	if (tipo == 1) {
		Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
		Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
	}
	if (tipo == 2) {
		Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
		Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
	}
}

void Enemigo::Mover(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo) {
	//Movimiento para los enemigos Alfa
	if (tipo == 1) {
		switch (_direccion) {
		case 'W':
			indicey = 0;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			break;
		case 'S':
			indicey = 2;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			break;
		case 'A':
			indicey = 1;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			break;
		case 'D':
			indicey = 3;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			break;
		}
		x = x + dx;
		y = y + dy;
	}
	//Movimiento para los enemigos Beta
	if (tipo == 2) {
		switch (_direccion) {
		case 'W':
			indicey = 0;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			y = y + dy;
			break;
		case 'S':
			indicey = 2;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			y = y + dy;
			break;
		case 'A':
			indicey = 1;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			x = x + dx;
			break;
		case 'D':
			indicey = 3;
			if (indicex >= 0 && indicex < 9)indicex++;
			else indicex = 0;
			x = x + dx;
			break;
		}
	}
}

int Enemigo::get_x() {
	return x;
}

int Enemigo::get_y() {
	return y;
}

int Enemigo::get_ancho() {
	return ancho;
}

int Enemigo::get_alto() {
	return alto;
}
void Enemigo::set_direccion(char __direccion) {
	this->_direccion = __direccion;
}
char Enemigo::get_direccion() {
	return _direccion;
}
void Enemigo::change_dx() {
	dx = dx*-1;
}
void Enemigo::change_dy() {
	dy = dy*-1;
}

void Enemigo::DibujarInvisible(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo) {
	if (tipo == 1) {
		Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
		Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
	}
}
void Enemigo::MoverInvisible(BufferedGraphics^ buffer, Bitmap^ bmp, int tipo) {
	if (tipo == 1) {
		switch (_direccion) {
		case 'W':
			indicey = 0;
			indicex = 0;
			break;
		case 'S':
			indicey = 0;
			indicex = 0;
			break;
		case 'A':
			indicey = 0;
			indicex = 0;
			break;
		case 'D':
			indicey = 0;
			indicex = 0;
			break;
		}
		x = x + dx;
		y = y + dy;
	}
}