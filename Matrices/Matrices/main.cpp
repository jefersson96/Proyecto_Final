#include<stdio.h>
#include"Matriz.h"
#include<array>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


using namespace std;
int main() {
	
		matriz primera;
		matriz segunda;
		nodo *lista1 = new nodo;
		nodo *lista2 = new nodo;
		matriz det;
		int op = 0;
		int opcion = 0;

		do {
			system("cls");

			cout << "\n\n ======================= M E N U ========================== \n\n";

			cout << "1.- CARGAR MATRICES\n";
			cout << "2.- INFORMACION\n";
			cout << "3.- SALIR\n";
			cin >> opcion;
			switch (opcion)
			{
			case 1:


				primera.LeerMatriz();
				segunda.LeerMatriz();
				lista1 = primera.getLista();
				lista2 = segunda.getLista();

				do
				{
					cout << "\n";
					cout << "1 - Sumar matrices\n";
					cout << "2 - RESTAR MATRICES\n";
					cout << "3 - MULTIPLICAR MATRICES\n";
					cout << "4 - CALCULAR DETERMINANTE\n";
					cout << "5 - SALIR\n";
					cout << "Ingrece una opcion: ";
					cin >> op;
					switch (op)
					{
					case 1:
						system("cls");
						cout << "======= Sumando Lista =========\n\n";

						primera.ImprimirLista(primera.SumarLista(lista1, lista2));

						break;
					case 2:
						system("cls");
						cout << "======= Sumando Lista =========\n\n";

						primera.ImprimirLista(primera.RestaLista(lista1, lista2));
						break;
					case 3:
						system("cls");
						cout << "======= Multiplicando Matriz =========\n\n";
						


						primera.ImprimirMatrizMul(primera.multmat(primera.create2DArray(), segunda.create2DArray()));

						
						break;
					case 4:

						system("cls");
						cout << "======= Calculando Determinante =========\n\n";


						det.LeerMatriz();
						
						det.Determinante();
						break;
					case 5:
						cout << "Hasta pronto.... :)" << endl;
						exit(0);
						break;
					}


				} while (1);








				break;

			case 2:
				system("cls");
				cout << "\n\n------------------I N F O R M A C I O N -------------------\n\n";


				cout << "Desarrollador :                                     Jefersson Sierra\n" << endl;
				cout << "Centro de Estudio :                                 UNITEC SPS\n" << endl;
				cout << "Clase :                                             Programacion III\n" << endl;
				cout << "Proyecto :                                          Operaciones con matrices usando archivos\n" << endl;





				break;

			case 3:

				exit(0);




				break;
			}




			cout << "\n\n             Precione enter para regresar..." << endl;
			_getch();


		} while (1);


























	//matriz z,i; 
	//z.menu();
	/*matriz j;

	matriz m;
	m.LeerMatriz();
	j.LeerMatriz();
	nodo *List=m.getLista();
	nodo *List2 = j.getLista();
	cout << "\n\n-----------------------------Matriz numero 1 -------------------------\n\n";
	m.ImprimirLista(List);
	cout << "\n\n-----------------------------Matriz numero 2 -------------------------\n\n";
	j.ImprimirLista(List2);
	
	cout << "\n\n-------------------------- Matriz suma ---------------------------------\n\n";
	m.ImprimirLista(m.SumarLista(List, List2));
	cout << "\n\n----------------------------Matriz resta ----------------------------------\n\n";
	m.ImprimirLista(m.RestaLista(List, List2));

	cout << "-------------------------------------" << endl;
	m.InsertarAlInicio(2);
	m.InsertarAlInicio(3);
	cout << "----------------------------------det"<<endl;
	m.Determinante();
	
	*/
	//z.LeerMatriz();
	//nodo *List3 = z.getLista();
	
	//z.LeerMatriz();
	//i.LeerMatriz();
	//cout << "------matriz main 1"<<endl;
	//z.ImprimirMatrizMain();
	//cout << "------matriz main 2" << endl;
	//i.ImprimirMatrizMain();
	//i.multmat(z.create2DArray(),i.create2DArray());
	//cout << "-------------------Multiplicacion-------------------"<<endl;
	//i.ImprimirMatrizMul(i.multmat(z.create2DArray(),i.create2DArray()));
	
	/*for (int h = 0; h < z.getRow(); h++)
	{
		for (int w = 0; w < z.getCol(); w++)
		{
			printf("%i ", i.multmat(z.create2DArray(), i.create2DArray())[h][w]);
		}
		printf("\n");
	}*/
	
	
	
	
	//cout << "Primera Matriz Determinante" << endl;
	//z.Determinante();
	//cout << z.getRow();
	system("pause");
}