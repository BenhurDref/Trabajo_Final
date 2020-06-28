#pragma once
#include "CPersonajesPlus_C.h"
class PresidenteC :public PersonajesPlus_C {
public:
	PresidenteC();
	PresidenteC(int _x, int _y, char __direccion, int _tipo);
	~PresidenteC();
};
PresidenteC::PresidenteC() {
}
PresidenteC::PresidenteC(int _x, int _y, char __direccion, int _tipo) :PersonajesPlus_C(_x, _y, __direccion, _tipo) {
}
PresidenteC::~PresidenteC() {
}