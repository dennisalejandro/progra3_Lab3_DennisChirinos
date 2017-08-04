#include <iostream>
#include <string>
using namespace std;
int** CrearMatriz();
int** CrearMatriz2();
void PrintMatriz(int**);
void Shot(int);
int CheckBoatCountP1(int**);
int CheckBoatCountP2(int**);
void PrintMatrizRec(int**, int, int);

int main() {
	int** MatrizP1; 
	int** MatrizP2;

	MatrizP1 = CrearMatriz();
	MatrizP2 = CrearMatriz2();

	bool TerminoJuego = true;
	
	int ShotsP1;
	ShotsP1 = 5;
	int ShotsP2;
	ShotsP2 = 5;
	
	int NumBoatsP1;
	int NumBoatsP2;
	while (TerminoJuego) {
		cout << "Jugador 1" << "\n";
		cout << "ingrese coordenada (x, y)" << "\n";
		int x;
		int y;
		int random;
		cin >> x;
		cin >> y;
		if ((x >=8)||(y>=8)||(x<0)||(y<0)) {
			cout << "Salio del mar, se le asigno (0,0) a su misil" << "\n";
			y = 0;
			x = 0;
		}

		if (MatrizP2[y][x] == 1) {
			random = rand() % 7 + 1;
			Shot(random);
			MatrizP2[y][x] = -1;
			NumBoatsP2 = CheckBoatCountP2 (MatrizP2);
			ShotsP2--;
			cout << "Al jugador 2 le quedan " << ShotsP2 << " por tomar" << "\n";
			cout << "y le quedan " << NumBoatsP2 << " Barcos" << "\n";
		}
		PrintMatrizRec(MatrizP2, 0, 0);
		cout << "\n";
		
		cout << "Jugador 2" << "\n";
		cout << "ingrese coordenada (x, y)" << "\n";
		cin >> x;
		cin >> y;
		if ((x >=8)||(y>=8)||(x<0)||(y<0)) {
			cout << "Salio del mar, se le asigno (0,0) a su misil" << "\n";
			y = 0;
			x = 0;
		}
		if (MatrizP1[y][x] == 2) {
			random = rand() % 7 + 1;
			Shot(random);
			MatrizP1[y][x] = -1;
			NumBoatsP1 = CheckBoatCountP1 (MatrizP1);
			ShotsP1--;
			cout << "Al jugador 2 le quedan " << ShotsP1 << " por tomar" << "\n";
			cout << "y le quedan " << NumBoatsP1 << " Barcos" << "\n";
		}
		PrintMatrizRec(MatrizP1, 0, 0);
		cout << "\n";
		if (ShotsP1 <= 0) {
			TerminoJuego = false;
			cout << "Gano El Jugador 2";
		} else if (ShotsP2 <= 0) {
			TerminoJuego = false;
			cout << "Gano El Jugador 1";
		} else {
		
		}
	}
	cout << "\n";
	delete[] MatrizP1;
	delete[] MatrizP2;
	return 0;
}

int** CrearMatriz() {
int const y = 8;
int const x = 8;

int** matriz = new int*[y];
	for(int i=0;i<x;i++){
		matriz[i] = new int[y];
	}
	matriz[1][1] = 1;
	matriz[1][2] = 1;
	matriz[1][3] = 1;

	matriz[3][4] = 1;
	matriz[4][4] = 1;
	matriz[5][4] = 1;

	matriz[7][1] = 1;
	matriz[7][2] = 1;
	matriz[7][3] = 1;

	matriz[2][7] = 1;
	matriz[3][7] = 1;
	matriz[4][7] = 1;
return matriz;
}
int** CrearMatriz2() {
	int const y = 8;
	int const x = 8;

	int** matriz2 = new int*[y];
        for(int i=0;i<x;i++){
		matriz2[i] = new int[y];
	}
	matriz2[0][1] = 2;
	matriz2[0][2] = 2;
	matriz2[0][3] = 2;

	matriz2[5][1] = 2;
	matriz2[6][1] = 2;
	matriz2[7][1] = 2;
	       	
	matriz2[3][5] = 2;
	matriz2[3][6] = 2;
	matriz2[3][7] = 2;

	matriz2[4][4] = 2;
	matriz2[5][4] = 2;
	matriz2[6][4] = 2;
	return matriz2;
}
void PrintMatriz(int** Tabla) {
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			cout << Tabla[i][j];
		}
		cout << "\n";
	}
}
void PrintMatrizRec(int** Tabla, int x, int y) {
	if (Tabla[y][x] == 0) {
		cout << "^^";
	} else if (Tabla[y][x] == -1) {
		cout << "XX";
	} else {
		cout << "^^";
	}
	if ((x+1)<8) {
		PrintMatrizRec(Tabla, x+1, y);
	} else if ((y+1)<8) {
		cout<<"\n";
		PrintMatrizRec(Tabla, 0, y+1);
	}
}
void Shot(int Num) {
	if (Num == 1) {
		cout << "Tomese un Cheap Tequila" << "\n";
	} else if (Num == 2) {
		cout << "Traguese un Jell-O" << "\n";
	} else if (Num == 3) {
		cout << "Los japoneses le regalan un Kamikaze" << "\n";
	} else if (Num == 4) {
		cout << "No se le olvide su MindEraser" << "\n";
	} else if (Num == 5) {
		cout << "Tomese unos Bombs" << "\n";
	} else if (Num == 6) {
		cout << "Traguese unas Fireballs" << "\n";
	} else if (Num == 7) {
		cout << "Echese un whiskey" << "\n";
	}
}

int CheckBoatCountP1(int** Tabla) {
	int Boats = 4;
	if (Tabla[1][1] == -1) {
		if (Tabla[1][2] == -1) {
			if (Tabla[1][3] == -1) {
				Boats--;
			}
		}
	}

	if (Tabla[3][1] == -1) {
		if (Tabla[4][2] == -1) {
			if (Tabla[5][3] == -1) {
				Boats--;
			}
		}
	}
	
	if (Tabla[7][1] == -1) {
		if (Tabla[7][2] == -1) {
			if (Tabla[7][3] == -1) {
				Boats--;
			}
		}
	}

	if (Tabla[2][7] == -1) {
		if (Tabla[3][7] == -1) {
			if (Tabla[4][7] == -1) {
				Boats--;
			}
		}
	}
	return Boats;
}

int CheckBoatCountP2(int** Tabla) {
	int Boats = 4;
	if (Tabla[0][1] == -1) {
		if (Tabla[0][2] == -1) {
			if (Tabla[0][3] == -1) {
				Boats--;
			}
		}
	}

	if (Tabla[5][1] == -1) {
		if (Tabla[6][1] == -1) {
			if (Tabla[7][1] == -1) {
				Boats--;
			}
		}
	}

	if (Tabla[3][5] == -1) {
		if (Tabla[3][6] == -1) {
			if (Tabla[3][7] == -1) {
				Boats--;
			}
		}
	}

	if (Tabla[4][4] == -1) {
		if (Tabla[4][5] == -1) {
			if (Tabla[4][6] == -1) {
				Boats--;
			}
		}
	}
	
	return Boats;
}
