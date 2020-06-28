#pragma once
using namespace System::Drawing;
class PersonajesPlus_C {
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
	PersonajesPlus_C();
	~PersonajesPlus_C();
	PersonajesPlus_C(int _x, int _y, char __direccion, int _tipo);
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, int _tipo);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmp, int _tipo);
	void set_direccion(char __direccion);
	int get_x();
	int get_y();
	int get_ancho();
	int get_alto();
	char get_direccion();
	void change_dx();
	void change_dy();
	void set_dx(int _dx);
	void set_dy(int _dy);
};

PersonajesPlus_C::PersonajesPlus_C(){
}
PersonajesPlus_C::~PersonajesPlus_C(){
}
PersonajesPlus_C::PersonajesPlus_C(int _x, int _y, char __direccion, int _tipo){
	if (_tipo == 1) {
		x = _x;
		y = _y;
		_direccion = __direccion;
		ancho = 32;
		alto = 48;
	}
	if (_tipo == 2) {
		x = _x;
		y = _y;
		_direccion = __direccion;
		ancho = 32;
		alto = 48;
	}
}
void PersonajesPlus_C:: Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, int _tipo){
	if (_tipo == 1) {
		Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
		Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
	}
	if (_tipo == 2) {
		Rectangle porcionausar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
		Rectangle aumentopersonaje = Rectangle(x, y, ancho*0.7, alto*0.7);
		buffer->Graphics->DrawImage(bmp, aumentopersonaje, porcionausar, GraphicsUnit::Pixel);
	}
}
void PersonajesPlus_C:: Mover(BufferedGraphics^ buffer, Bitmap^ bmp, int _tipo){
	if (_tipo == 1) {
		switch (_direccion){
		case'W':
			indicey = 3;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		case'S':
			indicey = 0;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		case'D':
			indicey = 2;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		case'A':
			indicey = 1;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		}
		x = x + dx;
		y = y + dy;
	}
	if (_tipo == 2) {
		switch (_direccion) {
		case'W':
			indicey = 3;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		case'S':
			indicey = 0;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		case'D':
			indicey = 2;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		case'A':
			indicey = 1;
			if (indicex >= 0 && indicex < 2)indicex++;
			else indicex = 0;
			break;
		}
		x = x + dx;
		y = y + dy;
	}
}
void PersonajesPlus_C:: set_direccion(char __direccion){
	this->_direccion = __direccion;
}
int PersonajesPlus_C::get_x(){
	return x;
}
int PersonajesPlus_C::get_y(){
	return y;
}
int PersonajesPlus_C::get_ancho(){
	return ancho;
}
int PersonajesPlus_C::get_alto(){
	return alto;
}
char PersonajesPlus_C::get_direccion(){
	return _direccion;
}
void PersonajesPlus_C::change_dx(){
	dx = dx*-1;
}
void PersonajesPlus_C::change_dy(){
	dy = dy*-1;
}
void PersonajesPlus_C::set_dx(int _dx){
	dx = _dx;
}
void PersonajesPlus_C::set_dy(int _dy) {
	dy = _dy;
}