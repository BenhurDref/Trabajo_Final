#pragma once
#include"CEnemigoBeta.h"
#include<iostream>

class ArregloEnemigoBeta {
private:
	EnemigoBeta** arregloenemigobeta;
	int *N;
public:
	ArregloEnemigoBeta();
	~ArregloEnemigoBeta();
	void Agregar_Enemigo(EnemigoBeta* dato);
	EnemigoBeta* Get_EnemigoBeta(int indice);
	void Eliminar_Enemigo(int indice);
	int Get_N();
};
ArregloEnemigoBeta::ArregloEnemigoBeta() {
	arregloenemigobeta = NULL;
	N = new int;
	*N = 0;
}
ArregloEnemigoBeta::~ArregloEnemigoBeta() {
	for (int i = 0; i < *N; i++) {
		delete arregloenemigobeta[i];
	}
	delete N;
}
void ArregloEnemigoBeta::Agregar_Enemigo(EnemigoBeta* dato) {
	EnemigoBeta** arregloauxiliar;
	arregloauxiliar = new EnemigoBeta*[*N + 1];

	for (int i = 0; i < *N; i++) {
		arregloauxiliar[i] = arregloenemigobeta[i];
	}
	arregloauxiliar[*N] = dato;
	*N = *N + 1;
	arregloenemigobeta = arregloauxiliar;
}
EnemigoBeta* ArregloEnemigoBeta::Get_EnemigoBeta(int indice) {
	return arregloenemigobeta[indice];
}
void ArregloEnemigoBeta::Eliminar_Enemigo(int indice) {
	EnemigoBeta** arregloauxiliar;
	arregloauxiliar = new EnemigoBeta*[*N - 1];
	for (int i = 0; i < indice; i++) {
		arregloauxiliar[i] = arregloenemigobeta[i];
	}
	for (int i = indice + 1; i < *N; i++) {
		arregloauxiliar[i - 1] = arregloenemigobeta[i];
	}
	*N = *N - 1;
	arregloenemigobeta = arregloauxiliar;
}
int ArregloEnemigoBeta::Get_N() {
	return *N;
}