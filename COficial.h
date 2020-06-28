#pragma once
#include "CPersonajesPlus_C.h"
class Oficial :public PersonajesPlus_C{
public:
	Oficial();
	Oficial(int _x, int _y, char __direccion, int _tipo);
	~Oficial();
};
Oficial::Oficial(){
}
Oficial::Oficial(int _x, int _y, char __direccion, int _tipo):PersonajesPlus_C(_x,_y,__direccion,_tipo){
}
Oficial::~Oficial(){
}