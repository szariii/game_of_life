
#include "BoundaryStrategy.h"
#include "Game.h"
#include "HardBoundary.h"
#include "Point.h"
#include "ReflectiveBoundary.h"
#include "TorusBoundary.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/*
Założenia projektu:
- pole 0 - martwa komórka
- pole 1 - żywa komórka

Znalazłem takie zasady ale możesz dodać jakieś inne tylko napisz tutaj:
- Przeludnienie: Jeśli żywa komórka ma więcej niż 3 sąsiadów – umiera.
- Samotność: Jeśli żywa komórka ma mniej niż 2 sąsiadów – umiera.
- Przetrwanie: Jeśli żywa komórka ma 2 lub 3 sąsiadów – żyje dalej.
- Narodziny: Jeśli martwa komórka ma dokładnie 3 żywych sąsiadów – staje się
żywa.
*/

int main()
{
    vector<Point> startingPoints = {{1, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};
    auto choice = 0;
    std::shared_ptr<BoundaryStrategy> boundaryStrategy = nullptr;
    std::shared_ptr<Rule> rule = nullptr;

    while (choice < 1 || choice > 3)
    {
        cout << "Wybierz jak ma dzialac program przy granicach planszy: " << endl;
        cout << "1: HardBoundary" << endl;
        cout << "2: Torus" << endl;
        cout << "3: Reflective" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            boundaryStrategy = std::make_shared<HardBoundary>();
            break;
        case 2:
            boundaryStrategy = std::make_shared<TorusBoundary>();
            break;
        case 3:
            boundaryStrategy = std::make_shared<ReflectiveBoundary>();
            break;
        default:
            cout << "Podano nieprawidlowa cyfre!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }

    rule = std::make_shared<Rule>(boundaryStrategy);
    Game game = Game(20, 20, startingPoints, rule);
    game.printBoard();
    string inputValue = "";
    while (inputValue != "finish")
    {
        game.nextRound();
        game.printBoard();
        cout << "\nWpisz dowolny ciag znakow aby grac dalej albo wpisz \"finish\" "
                "aby skonczyc gre";
        cin >> inputValue;
    }

    return 0;
}
