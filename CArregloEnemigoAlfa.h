#pragma once
#include"CEnemigoAlfa.h"
#include<iostream>
class ArregloEnemigoAlfa {
private:
	EnemigoAlfa** arregloenemigoalfa;
	int *N;
public:
	ArregloEnemigoAlfa();
	~ArregloEnemigoAlfa();
	void Agregar_Enemigo(EnemigoAlfa* dato);
	EnemigoAlfa* Get_EnemigoAlfa(int indice);
	void Eliminar_Enemigo(int indice);
	int Get_N();
};
ArregloEnemigoAlfa::ArregloEnemigoAlfa() {
	arregloenemigoalfa = NULL;
	N = new int;
	*N = 0;
}
ArregloEnemigoAlfa::~ArregloEnemigoAlfa() {
	for (int i = 0; i < *N; i++) {
		delete arregloenemigoalfa[i];
	}
	delete N;
}
void ArregloEnemigoAlfa::Agregar_Enemigo(EnemigoAlfa* dato) {
	EnemigoAlfa** arregloauxiliar;
	arregloauxiliar = new EnemigoAlfa*[*N + 1];

	for (int i = 0; i < *N; i++) {
		arregloauxiliar[i] = arregloenemigoalfa[i];
	}
	arregloauxiliar[*N] = dato;
	*N = *N + 1;
	arregloenemigoalfa = arregloauxiliar;
}
EnemigoAlfa* ArregloEnemigoAlfa::Get_EnemigoAlfa(int indice) {
	return arregloenemigoalfa[indice];
}
void ArregloEnemigoAlfa::Eliminar_Enemigo(int indice) {
	EnemigoAlfa** arregloauxiliar;
	arregloauxiliar = new EnemigoAlfa*[*N - 1];
	for (int i = 0; i < indice; i++) {
		arregloauxiliar[i] = arregloenemigoalfa[i];
	}
	for (int i = indice + 1; i < *N; i++) {
		arregloauxiliar[i - 1] = arregloenemigoalfa[i];
	}
	*N = *N - 1;
	arregloenemigoalfa = arregloauxiliar;
}
int ArregloEnemigoAlfa::Get_N() {
	return *N;
}