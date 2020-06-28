#pragma once
#include"CBalaEnemigo.h"
#include<iostream>

class ArregloBalaEnemigo {
private:
	BalaEnemigo** arreglobalaenemigo;
	int *N;
public:
	ArregloBalaEnemigo();
	~ArregloBalaEnemigo();
	void Agregar_BalaEnemigo(BalaEnemigo* dato);
	BalaEnemigo* Get_BalaEnemigo(int indice);
	void Eliminar_BalaEnemigo(int indice);
	int Get_N();
};
ArregloBalaEnemigo::ArregloBalaEnemigo() {
	arreglobalaenemigo = NULL;
	N = new int;
	*N = 0;
}
ArregloBalaEnemigo::~ArregloBalaEnemigo() {
	for (int i = 0; i < *N; i++) {
		delete arreglobalaenemigo[i];
	}
	delete N;
}
void ArregloBalaEnemigo::Agregar_BalaEnemigo(BalaEnemigo* dato) {
	BalaEnemigo** arregloauxiliar;
	arregloauxiliar = new BalaEnemigo*[*N + 1];

	for (int i = 0; i < *N; i++) {
		arregloauxiliar[i] = arreglobalaenemigo[i];
	}
	arregloauxiliar[*N] = dato;
	*N = *N + 1;
	arreglobalaenemigo = arregloauxiliar;
}
BalaEnemigo* ArregloBalaEnemigo::Get_BalaEnemigo(int indice) {
	return arreglobalaenemigo[indice];
}
void ArregloBalaEnemigo::Eliminar_BalaEnemigo(int indice) {
	BalaEnemigo** arregloauxiliar;
	arregloauxiliar = new BalaEnemigo*[*N - 1];
	for (int i = 0; i < indice; i++) {
		arregloauxiliar[i] = arreglobalaenemigo[i];
	}
	for (int i = indice + 1; i < *N; i++) {
		arregloauxiliar[i - 1] = arreglobalaenemigo[i];
	}
	*N = *N - 1;
	arreglobalaenemigo = arregloauxiliar;
}
int ArregloBalaEnemigo::Get_N() {
	return *N;
}