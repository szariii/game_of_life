
#include <iostream>
#include <string>
#include <ctime>
#include "Point.h"
#include "Game.h"
#include "BoundaryStrategy.h"
#include "TorusBoundary.h"
#include "HardBoundary.h"
#include "ReflectiveBoundary.h"

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



int main() {
	vector<Point> startingPoints = { {1,2}, {2,3}, {3,1}, {3,2}, {3,3} };
	auto boundaryStrategy1 = std::make_shared<HardBoundary>();
	auto boundaryStrategy2 = std::make_shared<TorusBoundary>();
	auto boundaryStrategy3 = std::make_shared<ReflectiveBoundary>();
	std::shared_ptr<Rule> rule = std::make_shared<Rule>(boundaryStrategy3);
	Game game = Game(20, 20, startingPoints, rule);
	game.printBoard();
	string inputValue = "";
	while (inputValue != "finish") {
		game.nextRound();
		game.printBoard();
		cout << "\nWpisz dowolny ciag znakow aby grac dalej albo wpisz \"finish\" aby skonczyc gre";
		cin >> inputValue;
	}
	
	return 0;
}
