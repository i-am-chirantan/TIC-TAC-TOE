
#include <iostream>
#include <iomanip> // Centerize text
#include <vector>
using namespace std;
int checkMove(vector<vector<int>> grid, int row, int col, int player)
{
    if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != -1)
    {
        return false;
    }
    grid[row][col] = player;
}
void displayGrid(vector<vector<int>> grid)
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == -1)
                cout << '*';
            else if (grid[i][j] == 1)
                cout << 'X';
            else
                cout << 'O';
            cout << "  |  ";
        }
        cout << "\n.................\n";
    }
}
int main()
{
    cout << setw(25);
    cout << "\t\t\t..........Welcome to TIC TAC TOE Game..........";
    cout << "\n\n\n";

    // do
    {
        string name1, name2;
        int player;
        cout << "Press 1: for 2player human vs human:\t";
        // cout << "Press 2: for 1player human vs computer:";
        cin >> player;
        cout << "\nEnter name of Player 1:\t";
        cin >> name1;
        cout << "\nEnter name of Player 2:\t";
        cin >> name2;
    }
    vector<vector<int>> grid(3, {-1, -1, -1});
    displayGrid(grid);
    cout << "\n";

    return 0;
}