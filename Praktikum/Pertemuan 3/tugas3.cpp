// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string board[5][5] = {
        {".",".","*","*","."},
        {".","*","*","y","."},
        {".","*","*","*","."},
        {".",".",".",".","."},
        {".",".",".",".","*"}
    };

        
        int xfinal;
        int yfinal;

        int getxfinal() {
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(board[i][j] == "y"){
                        xfinal = i;
                    }
                }
            }
            return xfinal;
        }

        int getyfinal() {
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(board[i][j] == "y"){
                        yfinal = j;
                    }
                }
            }
            return yfinal;
        }
        
   
    bool cekBoard(int x, int y, int xfinal, int yfinal) {
        if (board[x][y] == board[xfinal][yfinal]) {
            return true;
        }
        return false;
    }

    void printBoard() {
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << left << setw(2) << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool solve(int x, int y, int step) {
        // tembus papan
        if(x > 4 || x < 0 || y < 0 || y > 4 || board[x][y] != "." and board[x][y] != "y"){
            return false;
        }
        board[x][y] = "x";
        printBoard();
        cout << endl;

        if(cekBoard(x, y, getxfinal(), getyfinal())){
            return true;
        }
        board[x][y] = to_string(step);
       
        if(solve(x+1, y, step+1)) return true;
        if(solve(x, y+1, step+1)) return true;
        if(solve(x-1, y, step+1)) return true;
        if(solve(x, y-1,step+1)) return true;
       
        board[x][y] = ".";
        return false;
    }
   
int main() {
    // Write C++ code here
    solve(0,0,0);
   
    return 0;
}