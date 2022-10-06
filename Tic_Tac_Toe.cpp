#include <bits/stdc++.h>
using namespace std;
void displayGrid(vector<vector<int>> grid)
{
    cout << "\n\n\t\t\t";
<<<<<<< HEAD
<<<<<<< HEAD
    int n = 3;
=======
    int n = grid.size();
>>>>>>> 1f30eff... Indentation Add
=======
    int n = 3;
>>>>>>> 8421087... .
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
        cout << "\n\t\t\t.................\n";
        cout << "\t\t\t";
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
    if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != -1)
    {
        return -1;
    }
    grid[row][col] = player;
    count++;
    displayGrid(grid);
    if (checkWin(grid) > 0)
    {
        return player; // 0 1
    }
    return 3;
}
void playGame(vector<vector<int>> grid, const string a, const string b, int choice, map<string, int> &mp, int &round)
{
    if (mp.count(a) == 0)
        mp[a] = 0;
    if (mp.count(b) == 0)
        mp[b] = 0;
    int count = 0;
    int turn = 0; // 0 1
    int x, y, k, cell;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    int draw = 1;
>>>>>>> 1f30eff... Indentation Add
=======
>>>>>>> 8421087... .
    set<int> st;
    for (int i = 1; i <= 9; i++)
    {
        st.insert(i);
    }
    while (count != 9)
    {
        cout << "\n\t\t\tIts Turn for Player ";
        if (turn == 0)
            cout << a;
        else
            cout << b;
        if ((choice == 1) || (choice == 2 && turn == 0))
        {
            cout << "\n\n\t\t\tEnter the Cell No. :\t";
            cin >> cell; // 1 2 3 4 5 6 7 8 9
            x = (cell - 1) / 3;
            y = (cell - 1) % 3;
        }
        if (choice == 2 && turn == 1)
        {
            do
            {
                int randnumber = (int)(rand() % st.size());
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
            } while (true);
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            //cout << x << y << " ";
=======
            cout << x << y << " ";
>>>>>>> 1f30eff... Indentation Add
=======
            //cout << x << y << " ";
>>>>>>> 8421087... .
=======
            // cout << x << y << " ";
>>>>>>> 8dfdc1f... Commented lines
            k = checkMove(grid, x, y, turn, count);
            if (k == -1)
            {
                cout << "\n\n\t\t\tInvalid Move";
                continue;
            }
        }
        turn = (turn + 1) % 2;
        if (k == 0)
        {
            cout << "\n\t\t\tPlayer " << a << " has Won";
            mp[a]++;
            round++;
            break;
        }
        else if (k == 1)
        {
            cout << "\n\t\t\tPlayer " << b << " has Won";
            round++;
            mp[b]++;
            break;
        }
    }
    if (count == 9 && k != 0 && k != 1)
    {
        cout << "\n\n\t\t\tIts a Draw";
    }
}
int main()
{
    srand(time(nullptr));

    cout << "\t\t\t..........Welcome to TIC TAC TOE Game..........";
    cout << "\n\n\n";
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 8421087... .
    cout << "\t\t\t..........Rules of the Game:-  ";
    cout << "\n\t\t1. The game must be played by two players (human vs human/computer).";
    cout << "\n\t\t2. Both players mark their cells with the letters 'O' and 'X' .";
    cout << "\n\t\t3. The game ends when one of the players fills an entire row, column or diagonal with)";
    cout << "\n\t\t   either the character ('O' or 'X') of that player.";
    cout << "\n\t\t4. If no one wins, the match is considered a draw.";
    cout << "\n\n\n\t\t\tLets Play the Game";
    cout << "\n\t\t\tChoose a cell numbered from 1 to 9 as below and play \n\n ";
<<<<<<< HEAD
=======
    cout << "\t\t\tChoose a cell numbered from 1 to 9 as below and play \n\n ";
>>>>>>> 1f30eff... Indentation Add
=======
>>>>>>> 8421087... .
    cout << " \t\t\t 1 | 2 | 3 \n";
    cout << " \t\t\t -------------- \n ";
    cout << " \t\t\t 4 | 5 | 6 \n";
    cout << " \t\t\t -------------- \n ";
    cout << " \t\t\t 7 | 8 | 9 \n\n ";
    string name1, name2;
    int choice, round = 0;
    char pass = 'y';
    map<string, int> mp;
    do
    {
        cout << "\n\t\t\tPress 0: for exit:";
        cout << "\n\t\t\tPress 1: for player human vs human:";
        cout << "\n\t\t\tPress 2: for player human vs computer:\t";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        if (choice == 1 || choice == 2)
        {

            if (choice == 1)
            {
                cout << "\n\t\t\tEnter name of Player 1:\t";
                cin >> name1;
                cout << "\n\t\t\tEnter name of Player 2:\t";
                cin >> name2;
            }
            else // if (choice == 2)
            {
                cout << "\n\t\t\tEnter name of Player:\t";
                cin >> name1;
                name2 = "Computer";
            }
            vector<vector<int>> grid(3, {-1, -1, -1});
            displayGrid(grid);
            playGame(grid, name1, name2, choice, mp, round);
        }
        else
        {
            cout << "\n\n\t\t\txxxxxx Invalid Choice xxxxxx ";
        }
        cout << "\n";
        cout << "\n\n\t\t\tDo You want to Continue? Y or y for YES otherwise its No:\t";
        cin >> pass;
    } while (pass == 'y' || pass == 'Y');
    if (round > 0)
    {
        cout << "\n\n\n\t\t\t.......ScoreBoard........";
        cout << "\n\t\t\tSl.\tName\t\tScore";
        int count = 0;
        for (const auto &it : mp)
        {
            cout << "\n\t\t\t"
                 << count << ".\t" << it.first << "\t\t" << it.second;
        }
    }
    return 0;
}