#include "HorseMatrix.h"

#ifdef WIN32
#include <windows.h>
#endif

//Problem is from: https://www.geeksforgeeks.org/puzzle-9-find-the-fastest-3-horses/

/* 

HorseMatrix, creates a random matrix which contains a horse structure.
The horse structure contains it's location (MatrixPosition), and it's race value.

Because the coder has no access to the race value the procedure to resolve the problem is the same, and when a race is done
it's essentially a sort of a row or column from the matrix.

The values are printed ONLY for the clarity of the user, you'll see that all of the values are private in the class.
*/

int main() {
    //Definitions for randomiziation based on time and OS.
    #ifdef WIN32
    ::srand( GetTickCount() );
    #else
    srand((unsigned) time(NULL));
    #endif


    HorseMatrix horses;

    //The first 5 races are of the rows in a for loop.
    HorseMatrix::MatrixPosition initial_races[5][5];
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            //First we get the positions of each horse.
            initial_races[y][x] = {y,x};
        }
        //And then before chaging row we race them.
        horses.RaceHorses(initial_races[y]);
    }


    std::cout << "Position after " << horses.GetRacesAmount() << " races: " << std::endl;
    horses.PrintMatrix();

    //Gets the semifinal participants of the race (last column) to order the rest accordingly.
    HorseMatrix::MatrixPosition semifinals[5];
    for (int y = 0; y < 5; y++) {
        semifinals[y] = {y,4};
    }


    std::cout << "Semifinals: " << std::endl;
    horses.RaceHorses(semifinals);
    horses.PrintMatrix();

    //Final participants, {0,4} isn't raced because they will always be 1
    HorseMatrix::MatrixPosition finals[5] = {{0,2},{0,3},{1,3},{1,4},{2,4}};

    //Don't print matrix since it didn't change in this case.
    std::cout << "Finals: " << std::endl;
    std::unique_ptr<HorseMatrix::MatrixPosition[]> finals_result = horses.RaceHorses(finals);

    //Send in the winners.
    HorseMatrix::MatrixPosition winners[3] = {{0,4},finals_result.get()[0],finals_result.get()[1]};
    horses.CheckWinners(winners);

    std::cout << std::endl << "Amounts of races done: " << horses.GetRacesAmount() << std::endl;

    //Maintain user input so the terminal doesn't close immediately.
    std::cin.get();

    return 0;

}