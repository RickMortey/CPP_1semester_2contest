#include <iostream>


///
/// @brief finds max of two numbers
///
/// @return max of two numbers
///
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

///
/// @brief allocate 2D array
///
/// @param[in] rows - number of rows
///
/// @param[in] cols - number of cols
///
/// @return allocated 2D array
///
int** allocate(int rows, int cols) {
    int** a = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        a[i] = new int[cols];
    }
    return a;
}

///
/// @brief deallocated 2D array
///
/// @param[in] rows - number of rows
///
void deallocate(int** a, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

///
/// @brief fills 2D array with input data
///
/// @param[in] a - 2D array which must be filled
///
/// @param[in] rows - number of rows
///
/// @param[in] cols - number of cols
///
void fillMatrix(int** a, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> a[i][j];
        }
    }
}
///
///@brief finds the maximum on a portion of the array
///
///@note there is a check for array sizes
///
///@param[in] **a - array
///
///@param[in] lowestRow - upper boundary of the part of the array
///
///@param[in] highestRow - lower boundary of the part of the array
///
///@param[in] leftCol - left boundary of the part of the array
///
///@param[in] rightCol - right boundary of the part of the array
///
///@param[out] x, y - coordinates of the maximum element in the section
///
///@param[in] rows - number of array lines
///
///@param[in] cols - number of array columns
///
///@return maximum in the part of the array
///
int maxValue(int** a, int lowestRow, int highestRow, int leftCol, int rightCol,
    int& x, int& y, int rows, int cols) {
    int max = a[lowestRow][leftCol];
    x = lowestRow;
    y = leftCol;
    highestRow = min(highestRow, rows);
    rightCol = min(rightCol, cols);
    for (int i = lowestRow; i < highestRow; ++i) {
        for (int j = leftCol; j < rightCol; ++j) {
            
            if (a[i][j] > max) {
                max = a[i][j];
                x = i;
                y = j;
            }
        }
    }

    return max;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    int height, width; // area of visibility of the general
    std::cin >> height >> width;
    int** a = allocate(rows, cols);
    fillMatrix(a, rows, cols);
    int answer_x = 0;
    int answer_y = 0;
    int tmp_x = answer_x;
    int tmp_y = answer_y;
    int max = a[0][0];

    while (answer_x < rows && answer_y < cols) {
        int max1 = maxValue(a, answer_x, answer_x + height, answer_y,
            answer_y + width, tmp_x, tmp_y, rows, cols);
        if (max1 > max) {
            answer_x = tmp_x;
            answer_y = tmp_y;
            max = max1;
        }
        else if (max1 == max) {
            break;
            // due to each a[i][j] is unique
        }
    }

    std::cout << answer_x << ' ' << answer_y;

    deallocate(a, rows);
    return 0;
}