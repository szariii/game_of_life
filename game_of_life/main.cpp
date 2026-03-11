#include <iostream>
#include <vector>

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


int main() {
	// główny wektor który jest wyznacznikiem aktualnej tury
	vector<vector<int>> mainBoard = {};
	//pomocniczy wektor aby móc na nim obliczać następne miejsce - jezeli nie bedziesz jej uzywal to usun ja
	vector<vector<int>> tempBoard = {};
	generateBoard(mainBoard, tempBoard, 10, 10);

	// todo: Napisz funckje która generuje losowe miejsca pierwszych komórek (zrób tak zeby funkcja przyjmowała parametr ile ma być tych poczatkowych komórek).
	// PS: zastanawiam się czy może nie byłoby dobrym rozwiązanie aby jak wybierze miesjce jakieś to żeby odrazu wygenerowało tam z 3/4 komórki aby gra sie nie kończyła tak szybko

	string inputValue = "";
	while (inputValue != "finish") {

		//todo: napisz tutaj logikę komórek według podanej wyżej logiki ich rodzenia i umierania (tak jak napisałem tam, możesz zrobić swoją tylko napisz jak ma działać)


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