#include "HorseMatrix.h"

//Problem is from: https://www.geeksforgeeks.org/puzzle-9-find-the-fastest-3-horses/

/* 

Essentially, I've built a class called HorseMatrix, it creates a random matrix which contains a horse structure.
The horse structure contains it's location (MatrixPosition), and it's race value.

Because the coder has no access to the race value the procedure to resolve the problem is the same, and when a race is done
it's essentially a sort of a row or column from the matrix, there's also a RaceHorses functions to race specific horses together.

The values are printed ONLY for the clarity of the user, you'll see that all of the values are private.
*/

using namespace std;

int main() {
    srand((unsigned) time(NULL));

    HorseMatrix horses;

    for (int i = 0; i < 5; i++) {
        horses.RaceLine(i,ROW);
    }

    cout << endl;

    cout << "Position after " << horses.GetRacesAmount() + 1 << " races: " << endl;

    horses.RaceLine(4,COLUMN);

    HorseMatrix::MatrixPosition finals[5] = {{0,2},{0,3},{1,3},{1,4},{2,4}};
    HorseMatrix::MatrixPosition* pos = horses.RaceHorses(finals);
    HorseMatrix::MatrixPosition winners[3] = {{0,4},pos[0],pos[1]};

    horses.CheckWinners(winners);

    cout << endl << "Amounts of races done: " << horses.GetRacesAmount() << endl;

}