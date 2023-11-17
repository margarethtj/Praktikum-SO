#include <iostream>
#include <string>

using namespace std;

// program rekursif untuk faktorial
int fact(int n) {
    if (n <= 1) {
        return 1;
    }
    return n*fact(n-1);
}

// program rekursif untuk pemangkatan (mempersingkat coding dripd looping)
int pow(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return x*pow(x, y-1);
}

// BACK TRACKING, kayak kuda yang mau smuane jadi angka, 
// itu dee coba sampe abis kalo mentok dee bakal kembali ke langkah seblum"e
string board[5][5] = {
        {".",".",".",".","."},
        {".",".",".",".","."},
        {".",".",".",".","."},
        {".",".",".",".","."},
        {".",".",".",".","."}
    };
   
    bool cekBoard()
    {
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(board[i][j] == "."){
                    return false;
                }
            }
        }
        return true;
    }
    void printBoard()
    {
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout << left << setw(2) << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool solve(int x,int y,int step)
    {
        // tembus papan
        if(x > 4 ||x < 0 || y < 0||y > 4||board[x][y] != "."){
            return false;
        }
        board[x][y] = "K";
        printBoard();
        cout << endl;
        if(cekBoard()){
            return true;
        }
        board[x][y] = to_string(step);
       
        if(solve(x+1,y+2,step+1)) return true;
        if(solve(x+2,y+1,step+1)) return true;
        if(solve(x+2,y-1,step+1)) return true;
        if(solve(x+1,y-2,step+1)) return true;
        if(solve(x-1,y-2,step+1)) return true;
        if(solve(x-2,y-1,step+1)) return true;
        if(solve(x-2,y+1,step+1)) return true;
        if(solve(x-1,y+2,step+1)) return true;
       
        board[x][y] = ".";
        return false;
    }
   
int main() {
    cout << fact(5);
    cout << pow(3,5);

    // Write C++ code here
    solve(0,0,0);
   
    return 0;
}