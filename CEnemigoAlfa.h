#pragma once
#include"CEnemigo.h"
class EnemigoAlfa : public Enemigo {
public:
	EnemigoAlfa(int _x, int _y, char __direccion, int tipo);
	~EnemigoAlfa();
};
EnemigoAlfa::EnemigoAlfa(int _x, int _y, char __direccion, int tipo) :Enemigo(_x, _y, __direccion, tipo) {

}

EnemigoAlfa::~EnemigoAlfa() {

}