#include <bits/stdc++.h>
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
        return 2;
    }
    // row3
    else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][2] != -1)
    {
        return 3;
    }
    // col1
    else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[2][0] != -1)
    {
        return 4;
    }
    // col2
    else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[2][1] != -1)
    {
        return 5;
    }
    // col3
    else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[2][2] != -1)
    {
        return 6;
    }
    // diag1
    else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != -1)
    {
        return 7;
    }
    // diag1
    else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != -1)
    {
        return 8;
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
    if (checkWin(grid) > 0)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << grid[i][j] << "\t";
            }
            cout << "\n";
        }
        return player; // 0 1
    }
    return 3;
}
void playGame(vector<vector<int>> grid, string a, string b, int choice, map<string, int> &mp, int &round)
{
    if (mp.count(a) == 0)
        mp[a] = 0;
    if (mp.count(b) == 0)
        mp[b] = 0;
    int count = 0;
    int turn = 0; // 0 1
    int x, y, k;
    int draw = 1;
    set<int> st;
    for (int i = 1; i <= 9; i++)
    {
        st.insert(i);
    }
    while (count != 9)
    {
        cout << "\nIts Turn for Player ";
        if (turn == 0)
            cout << a;
        else
            cout << b;
        if ((choice == 1) || (choice == 2 && turn == 0))
        {
            cout << "\n\nEnter the Coordinates between {(1,1) and (3,3)}:\t";
            cin >> x >> y;
        }
        if (choice == 2 && turn == 1)
        {
            do
            {
                int randnumber = (rand() % st.size());
                x = (randnumber / 3) + 1;
                y = (randnumber % 3) + 1;
                k = checkMove(grid, x, y, turn, count);
                if (k == -1)
                    continue;
                else
                {
                    st.erase(randnumber);
                    break;
                }
            } while (1);
        }
        else
        {
            k = checkMove(grid, x, y, turn, count);
            if (k == -1)
            {
                cout << "\n\nInvalid Move";
                continue;
            }
        }
        turn = (turn + 1) % 2;
        if (k == 0)
        {
            cout << "\nPlayer " << a << " has Won";
            mp[a]++;
            round++;
            break;
        }
        else if (k == 1)
        {
            cout << "\nPlayer " << b << " has Won";
            round++;
            mp[b]++;
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
    srand(time(NULL));

    cout << "\t\t\t..........Welcome to TIC TAC TOE Game..........";
    cout << "\n\n\n";
    string name1, name2;
    int choice, round = 0;
    char pass = 'y';
    map<string, int> mp;
    do
    {
        cout << "Press 0: for exit:";
        cout << "\nPress 1: for player human vs human:";
        cout << "\nPress 2: for player human vs computer:\t";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        if (choice == 1 || choice == 2)
        {

            if (choice == 1)
            {
                cout << "\nEnter name of Player 1:\t";
                cin >> name1;
                cout << "\nEnter name of Player 2:\t";
                cin >> name2;
            }
            else // if (choice == 2)
            {
                cout << "\nEnter name of Player:\t";
                cin >> name1;
                name2 = "Computer";
            }
            vector<vector<int>> grid(3, {-1, -1, -1});
            displayGrid(grid);
            playGame(grid, name1, name2, choice, mp, round);
        }
        else
        {
            cout << "\n\nxxxxxx Invalid Choice xxxxxx ";
        }
        cout << "\n";
        cout << "\n\nDo You want to Continue? Y or y for YES otherwise its No:\t";
        cin >> pass;
    } while (pass == 'y' || pass == 'Y');
    if (round > 0)
    {
        cout << "\n\n\n.......ScoreBoard........";
        cout << "\nSl.\tName\tScore";
        int count = 0;
        for (auto it : mp)
        {
            cout << "\n"
                 << count << ".\t" << it.first << "\t" << it.second;
        }
    }
    return 0;
}