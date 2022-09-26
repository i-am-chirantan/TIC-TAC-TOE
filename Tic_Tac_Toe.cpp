
#include <iostream>
#include <iomanip> // Centerize text
#include <vector>
using namespace std;
void displayGrid(vector<vector<int>> grid)
{
    cout << "\n\n";
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
int checkWin(vector<vector<int>> grid)
{
    // row1
    if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][2] != -1)
    {
        return 1;
    }
    // row2
    else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][2] != -1)
    {
        return 1;
    }
    // row3
    else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][2] != -1)
    {
        return 1;
    }
    // col1
    else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[1][0] && grid[2][0] != -1)
    {
        return 1;
    }
    // col2
    else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[2][1] != -1)
    {
        return 1;
    }
    // col3
    else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[2][2] != -1)
    {
        return 1;
    }
    // diag1
    else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != -1)
    {
        return 1;
    }
    // diag1
    else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != -1)
    {
        return 1;
    }
    return 0;
}
int checkMove(vector<vector<int>> &grid, int row, int col, int player, int &count)
{
    row--;
    col--;
    if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != -1)
    {
        return -1;
    }
    grid[row][col] = player;
    count++;
    displayGrid(grid);
    if (checkWin(grid) == 1)
    {
        return player; // 0 1
    }
    return 3;
}
void playGame(vector<vector<int>> grid, string a, string b)
{
    int count = 0;
    int turn = 0; // 0 1
    int x, y, k;
    while (count != 9)
    {
        cout << "\nIts Turn for Player ";
        if (turn == 0)
            cout << a;
        else
            cout << b;
        cout << "\n\nEnter the Coordinates between {(1,1) and (3,3)}:\t";
        cin >> x >> y;
        k = checkMove(grid, x, y, turn, count);
        if (k == -1)
        {
            cout << "\nInvalid Move";
            continue;
        }
        turn = (turn + 1) % 2;
        if (k == 0)
        {
            cout << "\nPlayer " << a << " has Won";
            break;
        }
        else if (k == 1)
        {
            cout << "\nPlayer " << b << " has Won";
            break;
        }
    }
    if (count != 9 && k != 0 && k != 1)
    {
        cout << "\n\n Its a Draw";
    }
}
int main()
{
    cout << setw(25);
    cout << "\t\t\t..........Welcome to TIC TAC TOE Game..........";
    cout << "\n\n\n";

    string name1, name2;
    int player;
    // cout << "Press 1: for player human vs human:\t";
    //  cout << "Press 2: for player human vs computer:";
    // cin >> player;
    cout << "\nEnter name of Player 1:\t";
    cin >> name1;
    cout << "\nEnter name of Player 2:\t";
    cin >> name2;

    vector<vector<int>> grid(3, {-1, -1, -1});
    displayGrid(grid);
    playGame(grid, name1, name2);
    cout << "\n";

    return 0;
}