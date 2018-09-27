//Hola
#include "stdafx.h"
#include "Matriz.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;
string nombre_op;


vector<Matriz>objetos;

void crear_objeto(string a, int b, int c, vector<int> d) {
	Matriz m(a, b, c, d);
	objetos.push_back(m), "\n";
}

Matriz::Matriz(string a, int b, int c, vector<int> d) {
	nombre_matriz = a;
	filas = b;
	columnas = c;
	matriz = d;
}


int convert(string s)
{
	stringstream geek(s);
	int x = 0;
	geek >> x;
	return x;
}


void imprimir(vector<Matriz> m) {
	for (int i = 0; i < m.size(); i++) {
		Matriz nume = m[i];
		cout << m[i].nombre_matriz << endl;
		imprimir_objetos(nume);
	}
}
void imprimir_objetos(Matriz m) {
	for (int i = 0; i < 1; i++) {
		for (int ii = 0; ii < m.matriz.size(); ii++)
		{
			cout << m.matriz[ii];
		}
		cout << endl;
	}
}

vector<string> split2(vector<string>a)
{
	vector<string> palabras_coma;
	for (auto x : a) {
		istringstream iss(x);
		string token;
		while (getline(iss, token, ','))
		{
			palabras_coma.push_back(token);
		}
	}
	return palabras_coma;
}

vector<string> split(string a)
{
	vector<string> palabras_espacio;
	istringstream iss(a);
	string token;
	while (getline(iss, token, ' '))
	{
		palabras_espacio.push_back(token);
	}
	return split2(palabras_espacio);
}


string extraer_numeros(string frase) {
	int i = 0;
	string t;
	int con0 = 0, con1 = 0, con2 = 0, con3 = 0, con4 = 0, con5 = 0, con6 = 0, con7 = 0, con8 = 0, con9 = 0,conn=0,co=0;
	for (i; i < frase.size(); i++) {
		switch (frase[i]) {
		case '0':t = t + '0'; con0++; break;
		case '1':t = t + '1'; con1++; break;
		case '2':t = t + '2'; con2++; break;
		case '3':t = t + '3'; con3++; break;
		case '4':t = t + '4'; con4++; break;
		case '5':t = t + '5'; con5++; break;
		case '6':t = t + '6'; con6++; break;
		case '7':t = t + '7'; con7++; break;
		case '8':t = t + '8'; con8++; break;
		case '9':t = t + '9'; con9++; break;

		default:
			t = t + ' '; break;
		}
	}
	return t;
}


vector<int>mat_enteros;
vector<string>mat_strings;
void in()
{
	string numero_letras;
	int cont=1,filas=0,const columnas=0;
	while (numero_letras != ".")
	{
		cout << "Fila " << cont << ": ";
		getline(cin, numero_letras);

		if (numero_letras != "."){
			extraer_numeros(numero_letras);
			mat_strings = split(numero_letras);
			for (int j = 0; j < mat_strings.size(); j++) {
				int a = convert(mat_strings[j]);
				mat_enteros.push_back(a);
			}
			cont++;
			filas++;
		}
		else {
			break;
		}
	}
	columnas = mat_strings.size();
	cout <<"filas: " << filas<<endl;
	cout << "columnas: " << columnas << endl;
	crear_objeto(nombre_op, filas, columnas, mat_enteros);
}



int main()
{


	vector<string>opciones;
	string op;
	while (op != "fin") {
		cout << "cmd->";
		getline(cin, op);
		Matriz m1("A", 2, 2, { 1,1,2,4 });
		opciones = split(op);
		if (opciones[0] == "fin")
			break;
		if (opciones[0] == "lee" || opciones[0] == "leer") {
			nombre_op = opciones[1];
			in();
			imprimir(objetos);
			cout << endl;
		}
		system("pause");
	}
	
	//();
	//Matriz a("a", 2, 2, { 1,2,3,4 });
	//objetos.push_back(a);
	//crear_objeto("a", 2, 2, { 1,2,3,4 });
	//crear_objeto("b", 2, 2, { 5,6,7,8 });
	//imprimir(objetos);
	system("pause");
	return 0;
}
