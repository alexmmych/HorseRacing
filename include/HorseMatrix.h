#include <iostream>
#include <algorithm>
#include <memory>

class HorseMatrix {
    public:

        struct MatrixPosition {
            int y;
            int x;
        };

    private:
    
        struct Horse {
            int value;
            MatrixPosition location;
        };

        int number_of_races = 0;
        
    public:

        Horse horse_matrix[5][5];

        static bool CompareHorses(Horse &horse1, Horse &horse2);

        HorseMatrix();
        
        void CheckWinners(MatrixPosition locations[3]);

        void RaceHorses(MatrixPosition locations[5]);
        std::unique_ptr<MatrixPosition[]> FinalRace(MatrixPosition locations[5]);

        int GetRacesAmount();
        void PrintMatrix();
};