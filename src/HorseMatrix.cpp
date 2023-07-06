#include "HorseMatrix.h"

// random generator function:
int randomize (int i) { return std::rand()%i; }

HorseMatrix::HorseMatrix() {
    const int size = 25;

    int values[size];

    for (int i = 0; i < size; i++) {
        values[i] = i+1;
    }

    std::random_shuffle(std::begin(values),std::end(values),randomize);

    int array_index = 0;

    for (int y = 0; y < 5; y++) {

        for (int x = 0; x < 5; x++) {
            horse_matrix[y][x] = {values[array_index]};
            horse_matrix[y][x].location = {y,x};

            array_index += 1;
        }
    }

    std::cout << "Initial matrix: " << std::endl;

    PrintMatrix();
}
bool HorseMatrix::CompareHorses(Horse &horse1, Horse &horse2) {
    return horse1.value > horse2.value;
}

void HorseMatrix::PrintMatrix() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            std::cout << "\t" << horse_matrix[y][x].value;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HorseMatrix::RaceHorses(MatrixPosition locations[5]) {
    number_of_races += 1;

    int vertical_count = 0;
    int horizontal_count = 0;


    for (int i = 0; i < 5; i++) {
        if (locations[0].y == locations[i].y) {
            horizontal_count += 1;
        }

        if (locations[0].x == locations[i].x) {
            vertical_count += 1;
        }
    }

    if (horizontal_count == 5) {
        std::cout << "Row detected" << std::endl;
        int row = locations[0].y;
        int size = sizeof horse_matrix / sizeof horse_matrix[0];

        std::sort(horse_matrix[row], horse_matrix[row] + size, &CompareHorses);
        
    } else if (vertical_count == 5) {
        std::cout << "Column detected" << std::endl;
        int column = locations[0].x;
        Horse horses[5];

        for (int i = 0; i < 5; i++) {
            horses[i] = horse_matrix[i][column];
        }

        int size = sizeof horses / sizeof horses[0];

        std::sort(horses, horses + size, &CompareHorses);

        Horse temp_matrix[5][5];

        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                temp_matrix[y][x] = horse_matrix[horses[4-y].location.y][x];
                temp_matrix[y][x].location = {y,x};
            }
        }
        std::swap(temp_matrix,horse_matrix);
    }
}

std::unique_ptr<HorseMatrix::MatrixPosition[]> HorseMatrix::FinalRace(MatrixPosition locations[5]) {
    Horse horses[5];

    for (int i = 0; i < 5; i++) {
        horses[i] = horse_matrix[locations[i].y][locations[i].x];
    }

    int size = sizeof horses / sizeof horses[0];

    std::sort(horses, horses + size, &CompareHorses);

    auto p = std::make_unique<MatrixPosition[]>(5);

    for (int i = 0; i < 5; i++) {
        std::cout << "Horse: " << horses[4-i].value << " at (" << horses[4-i].location.y << "," << horses[4-i].location.x  << ")" << std::endl;
        p.get()[i] = horses[4-i].location;
    }

    std::cout << std::endl;

    return p;
}

void HorseMatrix::CheckWinners(MatrixPosition locations[3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        std::cout << "Position chosen at: " << "[" << locations[i].y << "," << locations[i].x << "]";

        if (horse_matrix[locations[i].y][locations[i].x].value == i+1) {
            count += 1;

            std::cout << " is ";

            switch (count) {
                case 1:
                    std::cout << "first place!" << std::endl;
                    break;
                case 2:
                    std::cout << "second place!" << std::endl;
                    break;
                case 3:
                    std::cout << "third place!" << std::endl;
                    break;
                default:
                    std::cout << "not a winner :(" << std::endl;
                    
            }

        }
    }

    if (count == 3) {
        std::cout << "You are correct!" << std::endl;
    }
} 

int HorseMatrix::GetRacesAmount() {
    return number_of_races;
}

