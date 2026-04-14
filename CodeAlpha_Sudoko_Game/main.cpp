#include <iostream>
using namespace std;

void printGrid(int grid[9][9])
{
    cout << "        0   1    2  3   4   5   6   7   8  " << endl;
    cout << "      +---+---+---+---+---+---+---+---+---+" << endl;
    for (int i = 0; i < 9; i++)
    {

        cout << "ROW " << i << " | ";
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
        cout << "      +---+---+---+---+---+---+---+---+---+" << endl;
    }
}
bool isSafe(int grid[9][9], int row, int col, int num)
{

    // Row check
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == num)
            return false;
    }

    // Column check
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
            return false;
    }

    // 3x3 Box check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}
int main()
{

    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "Sudoku Grid:\n\n";
    printGrid(grid);
    int row;
    int column;
    int num;
    cout << "\n For inserting Number, please tell row number and coulmn number where do you want to add your number.";

    while (true)
    {
        cout << "\n Enter row number : ";
        cin >> row;
        cout << "\n Enter Coulmn : ";
        cin >> column;
        cout << "\n Enter Number : ";
        cin >> num;
        if (isSafe(grid, row, column, num))
        {
            grid[row][column] = num;
            printGrid(grid);
        }
        else
        {
            cout << "\nNot Safe! Try again.";
        }

        return 0;
    }
}