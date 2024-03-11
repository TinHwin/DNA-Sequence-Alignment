// "Copyright [2023] <Truong-Thinh Huynh, Preston Luie>"

#include <string>
#include <iostream>
#include <algorithm>

#include "EDistance.hpp"

EDistance::EDistance(std::string inStringCol, std::string inStringRow) {
  stringCol = inStringCol;
  stringRow = inStringRow;

  // Convert .size() to int so it can be use to determine the allocation for the matrix.
  stringColSize = static_cast<int>(stringCol.size());
  stringRowSize = static_cast<int>(stringRow.size());

  // Dynamically allocate the column, then the row per column.
  optMatrix = new int*[stringColSize + 1];

  for (int i = 0; i < stringColSize + 1; ++i) {
    optMatrix[i] = new int[stringRowSize + 1];
  }
}

// Return 1 if a NOT b, and vice versa.
int EDistance::penalty(char a, char b) {
  return a != b;
}

// Return the smallest int though nested if-statements.
int EDistance::min(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  } else if (b <= a && b <= c) {
    return b;
  } else {
    return c;
  }
}

int EDistance::optDistance() {
  // M = Columns
  // N = Rows

  int a;
  int b;
  int c;

  for (int i = stringColSize - 1; i != -1; i--) {
    // Since the whole last column is increasing by 2 starting optMatrix[M][N].
    // It can be easily fill in.
    optMatrix[i][stringRowSize] = 2 * (stringColSize - i);

    for (int j = stringRowSize - 1; j != -1; j--) {
      // Since the whole last row is increasing by 2 starting optMatrix[M][N].
      // It can be easily fill in.
      optMatrix[stringColSize][j] = 2 * (stringRowSize - j);

      a = optMatrix[i + 1][j + 1] + penalty(stringCol[i], stringRow[j]);
      b = optMatrix[i + 1][j] + 2;
      c = optMatrix[i][j + 1] + 2;

      // Fill optMatrix[i][j] with the min(a, b, c).
      optMatrix[i][j] = min(a, b, c);
    }
  }

  return optMatrix[0][0];
}

std::string EDistance::alignment() {
  int j = 0;

  // Determine the alighment based on the matrix values.
  // Then push the result to a string, which will be return.
  for (int i = 0; i < stringColSize; i++) {
    if (stringCol[i] == stringRow[j]) {
      stringOptimalAlignment.push_back(stringCol[i]);
      stringOptimalAlignment.push_back(' ');
      stringOptimalAlignment.push_back(stringRow[j]);
      stringOptimalAlignment.append(" 0\n");

      j++;
    } else if (optMatrix[i][j] == optMatrix[i + 1][j + 1] + 1) {
      stringOptimalAlignment.push_back(stringCol[i]);
      stringOptimalAlignment.push_back(' ');
      stringOptimalAlignment.push_back(stringRow[j]);

      stringOptimalAlignment.append(" 1\n");

      j++;
    } else if (optMatrix[i][j] == optMatrix[i + 1][j] + 2) {
      stringOptimalAlignment.push_back(stringCol[i]);
      stringOptimalAlignment.push_back(' ');
      stringOptimalAlignment.push_back('-');

      stringOptimalAlignment.append(" 2\n");
    } else {
      stringOptimalAlignment.push_back('-');
      stringOptimalAlignment.push_back(' ');
      stringOptimalAlignment.push_back(stringRow[j]);

      stringOptimalAlignment.append(" 2\n");

      i--;
      j++;
    }
  }

  return stringOptimalAlignment;
}

void EDistance::clearMatrix() {
  // Go though the column, free each row first before freeing the column.
  for (int i = 0; i < stringColSize + 1; i++) {
    delete [] optMatrix[i];
  }

  delete [] optMatrix;
}

int EDistance::eCOptDistance() {
  // M = Columns
  // N = Rows

  int a;
  int b;
  int c;

  for (int i = stringColSize - 1; i != -1; i--) {
    // Since the whole last column is increasing by 2 starting optMatrix[M][N].
    // It can be easily fill in.
    optMatrix[i][stringRowSize] = 2 * (stringColSize - i);

    for (int j = stringRowSize - 1; j != -1; j--) {
      // Since the whole last row is increasing by 2 starting optMatrix[M][N].
      // It can be easily fill in.
      optMatrix[stringColSize][j] = 2 * (stringRowSize - j);

      a = optMatrix[i + 1][j + 1] + penalty(stringCol[i], stringRow[j]);
      b = optMatrix[i + 1][j] + 2;
      c = optMatrix[i][j + 1] + 2;

      // Fill optMatrix[i][j] with the min(a, b, c).
      optMatrix[i][j] = std::min({a, b, c});
    }
  }

  return optMatrix[0][0];
}
