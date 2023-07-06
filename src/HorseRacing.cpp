#include "HorseMatrix.h"

#ifdef WIN32
#include <windows.h>
#endif

//Problem is from: https://www.geeksforgeeks.org/puzzle-9-find-the-fastest-3-horses/

/* 

Essentially, I've built a class called HorseMatrix, it creates a random matrix which contains a horse structure.
The horse structure contains it's location (MatrixPosition), and it's race value.

Because the coder has no access to the race value the procedure to resolve the problem is the same, and when a race is done
it's essentially a sort of a row or column from the matrix, there's also a RaceHorses functions to race specific horses together.

The values are printed ONLY for the clarity of the user, you'll see that all of the values are private.
*/

int main() {

    #ifdef WIN32
    ::srand( GetTickCount() );
    #else
    srand((unsigned) time(NULL));
    #endif

    HorseMatrix horses;
    HorseMatrix::MatrixPosition initial_races[5][5];

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            initial_races[y][x] = {y,x};
        }
        horses.RaceHorses(initial_races[y]);
    }

    std::cout << "Position after " << horses.GetRacesAmount() << " races: " << std::endl;
    horses.PrintMatrix();

    HorseMatrix::MatrixPosition semifinals[5];

    for (int y = 0; y < 5; y++) {
        semifinals[y] = {y,4};
    }

    std::cout << "Semifinals: " << std::endl;
    horses.RaceHorses(semifinals);
    horses.PrintMatrix();

    HorseMatrix::MatrixPosition finals[5] = {{0,2},{0,3},{1,3},{1,4},{2,4}};
    
    std::cout << "Finals: " << std::endl;
    auto a = horses.FinalRace(finals);

    HorseMatrix::MatrixPosition winners[3] = {{0,4},a.get()[0],a.get()[1]};
    horses.CheckWinners(winners);

    std::cout << std::endl << "Amounts of races done: " << horses.GetRacesAmount() << std::endl;

    std::cin.get();

    return 0;

}