#include"Matriz.h"
#include <stdlib.h>
#include <conio.h>
matriz::matriz() {
	rows = 0;
	cols = 0;
	h = NULL;
	t = NULL;

}
int matriz::tamaño(nodo *Lista) {
	int contador = 0;
	nodo*aux;
	aux = Lista;
	while(aux!=NULL) {
	
		contador++;
		aux = aux->sig;
	}
	return contador;
}
int matriz::getCol() {

	return cols;
	

}
int matriz::getRow() {

	return rows;
}
nodo * matriz::RestaLista(nodo *Lista1, nodo *Lista2) {
	ofstream entrada;
	
	
	
	
	entrada.open("resta.txt", ios::app);

	
	nodo *ResRes = NULL;
	int contador=0;
	int dato;

	if (entrada.fail()) {
		cout << "Error";
	
	}else{

	while (Lista1 != NULL && Lista2 != NULL) {
		dato = Lista1->dato - Lista2->dato;
		entrada << dato << " " ;
		InsertarFinal(ResRes, dato);
		Lista1 = Lista1->abajo;
		Lista2 = Lista2->abajo;
		contador++;
		if (contador == getRow()) {

			entrada << "\n";
			contador = 0;
		}

	} 
	}
	entrada.close();
	return ResRes;

}
nodo * matriz::SumarLista(nodo *Lista1, nodo *Lista2) {
	ofstream entrada;
	entrada.open("suma.txt", ios::app);
	nodo *ResSuma=NULL;
	int dato;
	int contador = 0;
	
	if (entrada.fail()) {
		cout << "Error";

	}
	else {
		while (Lista1 != NULL && Lista2 != NULL) {
			dato = Lista1->dato + Lista2->dato;
			InsertarFinal(ResSuma, dato);
			entrada << dato << " ";
			contador++;
			Lista1 = Lista1->abajo;
			Lista2 = Lista2->abajo;
			if (contador == getRow()) {

				entrada << "\n";
				contador = 0;
			}
			
		}
	}
	entrada.close();
	return ResSuma;

}
void matriz::InsertarFinal(nodo *&Lista, int dato) {
	
	nodo *primero = new nodo();
	primero = Lista;
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->sig = NULL;
	
	nuevo_nodo->abajo = NULL;


	if (Lista==NULL) {

		Lista = nuevo_nodo;

	}
	else {

		Lista->sig = nuevo_nodo;
		nuevo_nodo->abajo = Lista;
		Lista = nuevo_nodo;
	
		

	}




}
void matriz::setCol(int a) {

	this->cols = a;

}
void matriz::setRow(int a) {

	this->rows = a;

}
void matriz::setLista(nodo *lista) {
	this->Lista = lista;

}
nodo *matriz::getLista() {


	return this->Lista;

}
/*void matriz::imprimir() {


	nodo *temp = primero;
	while (temp != 0) {
		std::cout << temp->getValor() << " ";

		temp = temp->getSig();

	}

	cout << endl;
}*/
void matriz::Matriz(int dato)
{
	int numeros[100][100], filas, columnas;


	
	filas = getRow();
	columnas = getCol();

	
		for (int i = 0; i < filas; i++) {

			for (int j = 0; j <columnas; j++) {


				if(this->mainMatriz[i][j]==0)
				

					this->mainMatriz[i][j] = dato;
				
				
				



				




			}
			
		}


		/*for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
			
			
				cout << numeros[i][j];
			}
		
		
		}*/
		
}

void matriz::ImprimirMatrizMul(int **Mat) {
	ofstream entrada;
	int contador = 0;
	entrada.open("multiplicacion.txt", ios::app);


	for (int i = 0; i < getRow(); i++) {

		for (int j = 0; j < getCol(); j++) {
			

			cout << Mat[i][j] << " ";
			entrada << Mat[i][j] << " ";
			contador++;

			

		}
		entrada << "\n";
		cout << "\n\n";
	}
	entrada.close();

}
void matriz::ImprimirMatrizMain() {


	for (int i = 0; i < getRow(); i++) {
	
		for (int j = 0; j < getCol(); j++) {
		
		
			cout << this->mainMatriz[i][j]<<" ";
		
		
		}
	
		cout << "\n\n";
	}


}
int matriz::LeerMatrizPuntero() 
{
	int contador = 0;
	for (int i = 0; i < getRow();i++) {
	
		for (int j = 0; j < getCol(); j++) {
		
			if (this->mainMatriz[i][j] != NULL) {
				contador++;
			}
		}
	
	}
	
	return contador;
}
void matriz::LeerMatriz() {
	nodo *Lista = NULL;
	
	string lineA;
	int colA = getCol();
	int rowA = getRow();
	int x;
	int arrayA[10][10] = { { 0 } };
	string filename;
	ifstream fileIN;
	cout << "Ingrece el nombre del archivo de la matriz que decea :";

	//cout << "\nplese enter the data file below and press enter" << endl;
	cin >> filename;

	fileIN.open(filename);


	if (fileIN.fail()) {
		cerr << "file you are trying to acces can not be open...";
		exit(1);
	}

	cout << "\n" << endl;

	while (fileIN.good()) {

		while (getline(fileIN, lineA))
		{
			istringstream streamA(lineA);
			colA = 0;
			while (streamA >> x) {

				arrayA[rowA][colA] = x;
				InsertarFinal(Lista, x);
				InsertarAlInicio(x);
				//Matriz(x);

				colA++;

			}
			rowA++;

		}

	}
	setLista(Lista);
	cout << "# Filas ----->" << rowA << endl;
	setRow(rowA);
	
	cout << "# Columnas---->" << colA << endl;
	setCol(colA);
	cout << " " << endl;
	for (int i = 0; i < rowA; i++) {

		for (int j = 0; j < colA; j++) {
			cout << left << setw(6) << arrayA[i][j] << " ";

			this->mainMatriz[i][j] = arrayA[i][j];

		}
		cout << endl;
	}

	

}

void matriz::InsertarAlInicio(int dato) {

	nodo *tmp = new nodo;

	tmp->dato = dato;
	tmp->sig = NULL;
	tmp->abajo = NULL;

	if (h == NULL && t==NULL) {
	
		h= tmp;
		t = tmp;


	
	}
	else {
	
		tmp->sig = h;
		h->abajo = tmp;
		h = tmp;
	
	}


}
int matriz::tamaño2() {
	int contador=0;
	nodo *aux;
	aux = h;
	while (aux==NULL) {
	
		aux = aux->sig;
		contador++;
	}
	return contador;

}
void matriz::Determinante() {
	fstream entrada;
	entrada.open("determinante.txt",ios::app);


	int min = 0;
	int a = getRow();
	int b = getCol();
	int det1 = 0;
	int det2 = 0;
	if (a != b) {
		
		cout << "No se puede calcular el determinante" << endl;

	
	}
	else {






		if (a==1) {
			cout << "Determinante :" << mainMatriz[0][0];
			entrada << mainMatriz[0][0];
			entrada << "\n\n";
		}
		else if (a == 2) {
		
			det1 = mainMatriz[0][0] * mainMatriz[1][1] - mainMatriz[0][1] * mainMatriz[1][0];
			cout << "Determinante:" << det1 << endl;

			entrada << det1<<" ";
			entrada << "\n\n";
		}
		else if (a == 3) {
		
			det2 = det2+((mainMatriz[0][0] * mainMatriz[1][1] * mainMatriz[2][2]
				+ mainMatriz[0][1] * mainMatriz[1][2] * mainMatriz[2][0]
				+ mainMatriz[1][0] * mainMatriz[2][1] * mainMatriz[0][2])
				- (mainMatriz[0][2] * mainMatriz[1][1] * mainMatriz[2][0]
					+ mainMatriz[0][1] * mainMatriz[1][0] * mainMatriz[2][2] 
					+ mainMatriz[1][2] * mainMatriz[2][1] * mainMatriz[0][0]));
			
			cout << "Determinante :" << det2<<endl;
			entrada << det2 << " ";
			entrada << "\n\n";
		}
	



	






	
	}

	entrada.close();
}
void matriz::ImprimirLista(nodo*Lista) {
	int contador = 0;


	while (Lista!=NULL) {
		if (contador == getCol()) {
			cout << "\n\n";
			contador = 0;
		}


		cout << Lista->dato<<"  ";
		Lista = Lista->abajo;
		contador++;
	}


}
int** matriz::create2DArray()
{
	int height = getRow();
	int width = getCol();
	int** array2D = 0;
	array2D = new int*[height];

	for (int h = 0; h < height; h++)
	{
		array2D[h] = new int[width];

		for (int w = 0; w < width; w++)
		{
			// fill in some initial values
			// (filling in zeros would be more logic, but this is just for the example)
			array2D[h][w] = this->mainMatriz[h][w];
		}
	}

	return array2D;
}
int** matriz::multmat(int **A, int **B) {
	int **C;
	C = new int*[getRow()];
	for (int j = 0; j < getRow(); j++) {
	
		C[j] = new int[getCol()];
	
	}


	int i, j, k;

	for (i = 0; i<3; i++) {

		for (j = 0; j<3; j++) {

			C[i][j] = 0;

			for (k = 0; k<3; k++) {

				C[i][j] = C[i][j] + A[i][k] * B[k][j];

			}

		}

	}
	return C;
}
void matriz::menu()
{
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
			lista1=primera.getLista();
			lista2=segunda.getLista();

			do
			{
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
				
				ImprimirLista(SumarLista(lista1,lista2));

				break;
			case 2:
				system("cls");
				cout << "======= Sumando Lista =========\n\n";

				ImprimirLista(RestaLista(lista1, lista2));
				break;
			case 3:
				system("cls");
				cout << "======= Multiplicando Matriz =========\n\n";

				
			
				ImprimirMatrizMul(multmat(primera.create2DArray(), segunda.create2DArray()));


				break;
			case 4:
				
				system("cls");
				cout << "======= Calculando Determinante =========\n\n";

				
				det.LeerMatriz();
				cout << "Su determinante es :";
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








	}
