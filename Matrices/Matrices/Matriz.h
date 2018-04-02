#pragma once
#include<stdio.h>
#include<array>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"nodo.h"
#include<string.h>
using namespace std;
#ifndef MATRIZ_H
#define MATRIZ_H


class matriz {
public:
	void menu();
	int tamaño2();
	int tamaño(nodo *);
	int getRow();
	int getCol();
	void setRow(int);
	void setCol(int);
	void LeerMatriz();
	void setLista(nodo *);
	nodo *SumarLista(nodo*,nodo*);
	nodo *RestaLista(nodo*, nodo*);
	void Matriz(int);
	int LeerMatrizPuntero();
	nodo* getLista();
	void Determinante();
	void setMatriz();
	void InsertarAlInicio(int dato);
	void multiplicacion(int[][10],int[][10]);
	int** create2DArray();
	int** multmat(int **A, int **B);
	matriz();
	void ImprimirLista(nodo*);
	void InsertarFinal(nodo*&, int);
	void ImprimirMatrizMain();
	void ImprimirMatrizMul(int **);
private:
	nodo *t;
	nodo *h;
	int cols;
	int rows;
	nodo *Lista;
	int mainMatriz[10][10];

	//int arrayA[10][10] = { { 0 } };


};



#endif // !MATRIZ_H

