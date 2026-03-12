#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

/*
Założenia projektu:
- pole 0 - martwa komórka
- pole 1 - żywa komórka

Znalazłem takie zasady ale możesz dodać jakieś inne tylko napisz tutaj:
- Przeludnienie: Jeśli żywa komórka ma więcej niż 3 sąsiadów – umiera.
- Samotność: Jeśli żywa komórka ma mniej niż 2 sąsiadów – umiera.
- Przetrwanie: Jeśli żywa komórka ma 2 lub 3 sąsiadów – żyje dalej.
- Narodziny: Jeśli martwa komórka ma dokładnie 3 żywych sąsiadów – staje się żywa.
*/

void generateBoard(vector<vector<int>>& mainArr, vector<vector<int>>tempArr, int x, int y);
void printBoard(vector<vector<int>>& board);
void startBoard(vector<vector<int>>& mainArr, int n);
void updateBoard(vector<vector<int>>& mainArr, vector<vector<int>>& tempArr);

int main() {
	// główny wektor który jest wyznacznikiem aktualnej tury
	vector<vector<int>> mainBoard = {};
	//pomocniczy wektor aby móc na nim obliczać następne miejsce - jezeli nie bedziesz jej uzywal to usun ja
	vector<vector<int>> tempBoard = {};
	generateBoard(mainBoard, tempBoard, 10, 10);
	srand(time(NULL));								//dla rand() w startBoard()
	//startBoard(mainBoard, 5);						//działa, ale mało ciekawe
	/*
	mainBoard[5][4] = 1;							//oscylator - robi brrr				
	mainBoard[5][5] = 1;
	mainBoard[5][6] = 1;
	*/
	mainBoard[1][2] = 1;							//glider - robi siuu :DDD
	mainBoard[2][3] = 1;
	mainBoard[3][1] = 1;
	mainBoard[3][2] = 1;
	mainBoard[3][3] = 1;
	// todo: Napisz funckje która generuje losowe miejsca pierwszych komórek (zrób tak zeby funkcja przyjmowała parametr ile ma być tych poczatkowych komórek).
	// PS: zastanawiam się czy może nie byłoby dobrym rozwiązanie aby jak wybierze miesjce jakieś to żeby odrazu wygenerowało tam z 3/4 komórki aby gra sie nie kończyła tak szybko
	// AD PS: Zrobilem klastry - n ~ liczba klastrów

	string inputValue = "";
	while (inputValue != "finish") {

		//todo: napisz tutaj logikę komórek według podanej wyżej logiki ich rodzenia i umierania (tak jak napisałem tam, możesz zrobić swoją tylko napisz jak ma działać)
		// yessir
		updateBoard(mainBoard, tempBoard);
		printBoard(mainBoard);
		cout << "\nWpisz dowolny ciag znakow aby grac dalej albo wpisz \"finish\" aby skonczyc gre";
		cin >> inputValue;
	}
	
	return 0;
}

void generateBoard(vector<vector<int>>& mainBoard, vector<vector<int>>tempBoard, int x, int y){
	for (int i = 0; i < x; i++) {
		mainBoard.push_back({});
		tempBoard.push_back({});
		for (int j = 0; j < y; j++) {
			mainBoard[i].push_back(0);
			tempBoard[i].push_back(0);
		}
	}
}

void printBoard(vector<vector<int>>& board){
	cout << "\n";
	for (int i = 0; i < board.size(); i++) {
		cout << "\n";
		for (int j = 0; j < board[i].size(); j++) {

				cout << " ";
			
			cout << board[i][j];
		}
	}
	cout << "\n";
}

void startBoard(vector<vector<int>>& mainArr, int n) {
	int x_max = mainArr.size();
	int y_max = mainArr[0].size();
	if (n <= x_max * y_max && n >= 0) {
		for (int i = 0; i < n; i++) {
			int x_pos = rand() % x_max;
			int y_pos = rand() % y_max;

			if (mainArr[x_pos][y_pos])
				i--;
			else {
				int cluster_size = rand() % 4;
				int x_half = x_max / 2;
				int y_half = y_max / 2;
				mainArr[x_pos][y_pos] = 1;
				for (int j = 0; j < cluster_size; j++) {
					if (x_pos < x_half && y_pos < y_half)
						mainArr[x_pos + j][y_pos + j] = 1; // I cwiartka planszy
					else if (x_pos >= x_half && y_pos < y_half)
						mainArr[x_pos - j][y_pos + j] = 1; // II cwiartka planszy
					else if (x_pos < x_half && y_pos >= y_half)
						mainArr[x_pos + j][y_pos - j] = 1; // III
					else if (x_pos >= x_half && y_pos >= y_half)
						mainArr[x_pos - j][y_pos - j] = 1; // IV
				}
			}
		}
	}
	else{
		cout << "Blad: zla ilosc startowych komorek" << endl;
	}
}

void updateBoard(vector<vector<int>>& mainArr, vector<vector<int>>& tempArr) {
	tempArr = mainArr;
	int x_max = mainArr.size();
	int y_max = mainArr[0].size();

	for (int i = 0; i < x_max; i++) {
		for (int j = 0; j < y_max; j++) {
			int n_alive = 0;
			for (int x = -1; x < 2; x++) {
				for (int y = -1; y < 2; y++) {
					if (i + x >= 0 && j + y >= 0 && i + x < x_max && j + y < y_max) {
						if (mainArr[i + x][j + y] && (x != 0 || y != 0))
							n_alive++;
					}
				}
			}
			if (n_alive > 3)
				tempArr[i][j] = 0;
			else if (n_alive < 2)
				tempArr[i][j] = 0;
			else if (mainArr[i][j] == 1 && n_alive == 2 || n_alive == 3)
				tempArr[i][j] = 1;
			else if (mainArr[i][j] == 0 && n_alive == 3)
				tempArr[i][j] = 1;
		}
	}
	mainArr = tempArr;
}