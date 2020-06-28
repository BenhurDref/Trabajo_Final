#pragma once
#include"CBalaJugador.h"
#include<iostream>

class ArregloBalaJugador {
private:
	BalaJugador** arreglobalajugador;
	int* N;
public:
	ArregloBalaJugador();
	~ArregloBalaJugador();
	void Agregar_Bala(BalaJugador* dato);
	void Eliminar_Bala(int indice);
	BalaJugador* Obtener_Bala(int indice);
	int Get_N();
};

ArregloBalaJugador::ArregloBalaJugador() {
	arreglobalajugador = NULL;
	N = new int;
	*N = 0;
}
ArregloBalaJugador::~ArregloBalaJugador() {
	for (int i = 0; i < *N; i++) {
		delete arreglobalajugador[i];
	}
	delete N;
}
void ArregloBalaJugador::Agregar_Bala(BalaJugador* dato) {
	BalaJugador** arregloauxiliar;
	arregloauxiliar = new BalaJugador*[*N + 1];
	for (int i = 0; i < *N; i++) {
		arregloauxiliar[i] = arreglobalajugador[i];
	}
	arregloauxiliar[*N] = dato;
	*N = *N + 1;
	arreglobalajugador = arregloauxiliar;
}
void ArregloBalaJugador::Eliminar_Bala(int indice) {
	BalaJugador** arregloauxiliar;
	arregloauxiliar = new BalaJugador*[*N - 1];
	for (int i = 0; i < indice; i++) {
		arregloauxiliar[i] = arreglobalajugador[i];
	}
	for (int i = indice + 1; i < *N; i++) {
		arregloauxiliar[i - 1] = arreglobalajugador[i];
	}
	*N = *N - 1;
	arreglobalajugador = arregloauxiliar;
}
BalaJugador* ArregloBalaJugador::Obtener_Bala(int indice) {
	return arreglobalajugador[indice];
}
int ArregloBalaJugador::Get_N() {
	return *N;
}