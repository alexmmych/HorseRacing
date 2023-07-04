#include "HorseMatrix.h"

InitializeMatrix::InitializeMatrix() {

    cout << "Initial horse placements: " << endl;

    for (int y = 0; y < 5; y++) {

        for (int x = 0; x < 5; x++) {

            int random_number = rand() % 26;

            ignore_count = count(ignore_vector.begin(),ignore_vector.end(),random_number);

            while (ignore_count > 0 || random_number == 0) {
                random_number = rand() % 26;
                ignore_count = count(ignore_vector.begin(),ignore_vector.end(),random_number);
            }

            number_matrix[y][x] = random_number;

            ignore_vector.push_back(random_number);

            cout << "\t" << number_matrix[y][x];
        }

        cout << endl;
    }
}


HorseMatrix::HorseMatrix() {
    for (int y = 0; y < 5; y++) {

        for (int x = 0; x < 5; x++) {
            horse_matrix[y][x] = {number_matrix[y][x]};
            horse_matrix[y][x].location = {y,x};
        }
    }
}

void HorseMatrix::RaceLine(int line, char option) {
    int race[5];
    number_of_races += 1;

    if (option == ROW) {
        for (int i = 0; i < 5; i++) {
            race[i] = horse_matrix[line][i].value;
        }

        sort(race, race + sizeof race / sizeof race[0]);

        for (int i = 0; i < 5; i++)  {
            horse_matrix[line][i].value = race[4-i];
        }
        
    } else if (option == COLUMN) {
        for (int i = 0; i < 5; i++) {
            race[i] = horse_matrix[i][line].value;
        }

        sort(race, race + sizeof race / sizeof race[0]);

        int rep = 0;

        for (int i = 0; i < 5; i++)  {
            for (int b = 0; b < 5; b++) {
                if (horse_matrix[b][line].value == race[i]) {
                    swap(horse_matrix[b],horse_matrix[rep]);
                    rep += 1;
                }
            }
        }
        for (int y = 0; y < 5; y++)  {
            for (int x = 0; x <5; x++) {
                cout << "\t" << horse_matrix[y][x].value;
            }
            cout << endl;
        }
    }
}

HorseMatrix::MatrixPosition* HorseMatrix::RaceHorses(MatrixPosition locations[5]) {
    number_of_races += 1;

    int race[5];

    MatrixPosition* pos = new MatrixPosition[5];

    for (int i = 0; i < 5; i++) {
        race[i] = horse_matrix[locations[i].y][locations[i].x].value;
    }

    sort(race, race + sizeof race / sizeof race[0]);

    for (int i = 0; i < 5; i++) {
        for (int b = 0; b < 5; b++) {
            if (race[i] == horse_matrix[locations[b].y][locations[b].x].value) {
                pos[i] = locations[b];
            }
        }
    }
        
    return pos;
}

void HorseMatrix::CheckWinners(MatrixPosition locations[3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        cout << "Position chosen at: " << "[" << locations[i].y << "," << locations[i].x << "]";

        if (horse_matrix[locations[i].y][locations[i].x].value == i+1) {
            count += 1;

            cout << " is ";

            switch (count) {
                case 1:
                    cout << "first place!" << endl;
                    break;
                case 2:
                    cout << "second place!" << endl;
                    break;
                case 3:
                    cout << "third place!" << endl;
                    break;
                default:
                    cout << "not a winner :(" << endl;
                    
            }

        }
    }

    if (count == 3) {
        cout << "You are correct!" << endl;
    }
} 

int HorseMatrix::GetRacesAmount() {
    return number_of_races;
}

