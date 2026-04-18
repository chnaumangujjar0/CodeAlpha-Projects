#include <iostream>
using namespace std;

// Check if number is safe
bool isSafe(int grid[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
        if (grid[row][i] == num)
            return false;

    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return false;

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (grid[i][j] == num)
                return false;

    return true;
}

//  Solver
bool solveSudoku(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isSafe(grid, i, j, k))
                    {
                        grid[i][j] = k;

                        if (solveSudoku(grid))
                            return true;

                        grid[i][j] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Print Grid
void printGrid(int grid[9][9])
{
    cout << "        0   1   2   3   4   5   6   7   8  " << endl;
    cout << "------+-----------+-----------+-----------+" << endl;
    for (int i = 0; i < 9; i++)
    {

        cout << "ROW " << i << " | ";
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
        if (i == 2 || i == 5 || i == 8)
        {
            cout << "------+-----------+-----------+-----------+" << endl;
        }
    }
}

//  Check if game complete
bool isComplete(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0)
                return false;

    return true;
}

int main()
{
    int row, col, num;
    int moves = 5;
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

    printGrid(grid);
    while (true)
    {
        if (moves <= 0)
        {
            cout << "\n Game Over, You are run out of moves!";
            break;
        }
        cout << "\nEnter Row (0-8): ";
        cin >> row;
        cout << "Enter Column (0-8): ";
        cin >> col;
        cout << "Enter Number (1-9): ";
        cin >> num;

        if (row < 0 || row > 8 || col < 0 || col > 8)
        {
            cout << "Invalid position!\n";
            continue;
        }

        if (num < 1 || num > 9)
        {
            cout << "Invalid number!\n";
            continue;
        }
        //  Prevent overwrite
        if (grid[row][col] != 0)
        {
            cout << "Cell already filled!\n";
            continue;
        }

        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            printGrid(grid);
        }
        else
        {
            moves--;
            cout << "Invalid move!\n";
            cout << "Moves left : " << moves<<endl ;
        }

        //  Check win
        if (isComplete(grid))
        {
            cout << "\n🎉 Congratulations! You solved Sudoku!\n";
            break;
        }

        int choice;
        cout << "\nPress 1 for solution, 2 to continue: ";
        cin >> choice;

        if (choice == 1)
        {
            if (solveSudoku(grid))
            {
                cout << "\nSolved by system:\n";
                printGrid(grid);
            }
            else
            {
                cout << "No solution exists!";
            }
            break;
        }
    }

    return 0;
}