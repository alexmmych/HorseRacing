#include "HorseMatrix.h"

// Random generator function:
int randomize(int i) { return std::rand() % i; }

HorseMatrix::HorseMatrix()
{
  const int size = 25;

  // Array which will be shuffled in order to create the matrix
  int values[size];

  for (int i = 0; i < size; i++) {
    values[i] = i + 1; //+1 to avoid 0.
  }

  std::random_shuffle(std::begin(values), std::end(values), randomize);

  // Used in the for loop in order to get every value of the previously shuffled array.
  int array_index = 0;

  for (int y = 0; y < 5; y++) {

    for (int x = 0; x < 5; x++) {
      horse_matrix[y][x] = { values[array_index] };
      horse_matrix[y][x].location = { y, x };

      array_index += 1;
    }
  }

  std::cout << "Initial matrix: " << std::endl;
  PrintMatrix();
}

// Note that sort() will give variables in a descending order, this is done in order for the fastest horses to be on the right
bool HorseMatrix::CompareHorses(Horse& horse1, Horse& horse2)
{
  return horse1.value > horse2.value;
}

void HorseMatrix::ResetCoordinates()
{
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      horse_matrix[y][x].location = { y, x };
    }
  }
}

void HorseMatrix::PrintMatrix()
{
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      std::cout << "\t" << horse_matrix[y][x].value;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::unique_ptr<HorseMatrix::MatrixPosition[]> HorseMatrix::RaceHorses(MatrixPosition locations[5])
{
  number_of_races += 1;

  // Int variables used to identify cases where the horses belong in the same row or column
  int vertical_count = 0;
  int horizontal_count = 0;

  // Variable used to contain currently selected horses for a temporary period.
  Horse horses[5];
  // Variable to be returned. Only has value on the last case, since it's needed to check the winners.
  std::unique_ptr<HorseMatrix::MatrixPosition[]> final_horses = std::make_unique<MatrixPosition[]>(5);

  for (int i = 0; i < 5; i++) {
    if (locations[0].y == locations[i].y) {
      horizontal_count += 1;
    }

    if (locations[0].x == locations[i].x) {
      vertical_count += 1;
    }
  }

  if (horizontal_count == 5) {
    int row = locations[0].y;
    int size = sizeof horse_matrix / sizeof horse_matrix[0];

    // Really easy and simple usage of sort.
    std::sort(horse_matrix[row], horse_matrix[row] + size, &CompareHorses);

  } else if (vertical_count == 5) {
    int column = locations[0].x;
    Horse temp_matrix[5][5];
    int size = sizeof temp_matrix / sizeof temp_matrix[0];

    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        temp_matrix[x][y] = horse_matrix[y][4 - x];
      }
    }

    /*
    This techincally races all of the previous horses a second time,
    if we equate sorting to racing, but since it's much more difficult
    to move them accordingly to the first positions, rather than just
    sorting them again, then it's allowed since the logic behind it
    stays the same
    */
    int max = 1;
    if (number_of_races == 5) {
      max = 5;
    }
    for (int i = 0; i < max; i++) {
      std::sort(temp_matrix[i], temp_matrix[i] + size, &CompareHorses);
    }
    std::swap(temp_matrix, horse_matrix);
    ResetCoordinates();

  } else {

    for (int i = 0; i < 5; i++) {
      horses[i] = horse_matrix[locations[i].y][locations[i].x];
    }

    int size = sizeof horses / sizeof horses[0];

    std::sort(horses, horses + size, &CompareHorses);

    // But here, instead of ordering, we just return the selected horses
    for (int i = 0; i < 5; i++) {
      std::cout << "Horse: " << horses[4 - i].value << " at (" << horses[4 - i].location.y << "," << horses[4 - i].location.x << ")" << std::endl;
      final_horses.get()[i] = horses[4 - i].location;
    }

    std::cout << std::endl;
  }

  return final_horses;
}

void HorseMatrix::CheckWinners(MatrixPosition locations[3])
{
  int count = 0;
  for (int i = 0; i < 3; i++) {
    std::cout << "Position chosen at: "
              << "[" << locations[i].y << "," << locations[i].x << "]";

    if (horse_matrix[locations[i].y][locations[i].x].value == i + 1) {
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
        break;
      }
    }
  }

  if (count == 3) {
    std::cout << "You are correct!" << std::endl;
  } else {
    std::cout << "You are incorrect. You lose" << std::endl;
  }
}
