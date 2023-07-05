#include <iostream>
#include <algorithm>

using namespace std;

#define ROW 'r'
#define COLUMN 'c'

class InitializeMatrix {
    private:
        vector<int> ignore_vector;
        int ignore_count;

    protected:
        int number_matrix[5][5];
        InitializeMatrix();
};

class HorseMatrix : public InitializeMatrix {
    public:
        struct MatrixPosition {
            int y;
            int x;
        };
    private:

        int number_of_races = 0;

        struct Horse {
            int value;
            MatrixPosition location;
        };

    public:
        Horse horse_matrix[5][5];

        HorseMatrix();

        void RaceLine(int line, char option);
        void CheckWinners(MatrixPosition locations[3]);

        MatrixPosition* RaceHorses(MatrixPosition locations[5]);


        int GetRacesAmount();

};
