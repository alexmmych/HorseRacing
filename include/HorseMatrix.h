#include <iostream>
#include <algorithm>
#include <memory>

/*
    Note: The main idea behind this class is to hide the "values" of the horses,
    which is equivalent to their speed. This makes it impossible for the coder to cheat
    and makes them actually follow the problem as intended.
*/

class HorseMatrix {
    public:
    //Structure used for getting position of horses without accessing their value.
        struct MatrixPosition {
            int y;
            int x;
        };

    private:
    // Strucutre is contained in the private part so the coder can't acess the values.
        struct Horse {
            int value;
            MatrixPosition location;
        };

        int number_of_races = 0;
        
    public:

        /*  
            Note: The horse_matrix stores all of the horses and their speed values.
            This allows us to STL sort() rows.
        */
        Horse horse_matrix[5][5];

        /*  
            Function which is passed to sort() https://en.cppreference.com/w/cpp/algorithm/sort
            in order to compare Horse structs by their value in a row.
        */
        static bool CompareHorses(Horse &horse1, Horse &horse2);

        //Initializes random horse values and assigns them a position.
        HorseMatrix();

        /*
            Main function used for racing the horses and figuring out the solution, detects automatically whether
            the given horses are in a same row or column, or if they are chosen at free.
            
            The return value is only given in the last case scenario so it can be passed down into CheckWinners().
        */
        std::unique_ptr<MatrixPosition[]> RaceHorses(MatrixPosition locations[5]);


        int GetRacesAmount() {return number_of_races;};

        void PrintMatrix();

        void CheckWinners(MatrixPosition locations[3]);
};