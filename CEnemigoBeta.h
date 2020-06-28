#pragma once
#include"CEnemigo.h"
class EnemigoBeta : public Enemigo {
public:
	EnemigoBeta(int _x, int _y, char __direccion, int tipo);
	~EnemigoBeta();
};
EnemigoBeta::EnemigoBeta(int _x, int _y, char __direccion, int tipo) :Enemigo(_x, _y, __direccion, tipo) {

}

EnemigoBeta::~EnemigoBeta() {

}