#include <iostream>

using namespace std;

char CreateBoard[][] = {{1,2,3}, {4,5,6}, {7,8,9}};

int currentplayer;
char currentmarker;




void _CreateBoard(){
    cout << " " << CreateBoard[0][0] << " | " << CreateBoard[0][1] << " | " << CreateBoard[0][2] << endl;
    cout << "------------\n";
    cout << " " << CreateBoard[1][0] << " | " << CreateBoard[1][1] << " | " << CreateBoard[2][2] << endl;
    cout << "------------\n";
    cout << " " << CreateBoard[2][0] << " | " << CreateBoard[2][1] << " | " << CreateBoard[2][2] << endl;
}

void PlaceMarker(int loc){
    int row = loc/3;
    int col;

    if(loc % 3 == 0){
        row = row-1;
        col = 2;
    }
    else{
        col = (loc % 3) - 1;

        CreateBoard[row][col] = currentmarker; 
    }

}

int winner(){

    for(int i = 0; i < 3; i++){
        if(CreateBoard[i][0] == CreateBoard[i][1] && CreateBoard[i][1] == CreateBoard[i][2]){
            return currentplayer;
        }
        if(CreateBoard[0][i] == CreateBoard[1][i] && CreateBoard[1][i] == CreateBoard[2][i]){
            return currentplayer;
        }
    }

    if(CreateBoard[0][0] == CreateBoard[1][1] && CreateBoard[1][1] == CreateBoard[2][2]){
        return currentplayer;
    }
    if(CreateBoard[0][0] == CreateBoard[1][1] && CreateBoard[1][1] == CreateBoard[2][2]){
        return currentplayer;
    }

    return 0;
    
}
void swapturn(){
    if(currentmarker == "X"){
        currentmarker = "O";
    }
    else{
        currentmarker = "X";
    }
    if(currentplayer == 1){
        currentplayer = 2;
    }
    else{
        currentplayer = 1;
    }
}

void playgame(){
    cout << "Player one make your move: " << endl;
    char p1;
    cin >> p1;

    currentplayer = 1;
    currentmarker = p1;


    _CreateBoard();

    int win_;

    for(int i = 0; i < 9; i++){
        cout << "It's player " << currentplayer << "'s turn. Enter: " << endl;
        int n;
        cin >> n;

        
        PlaceMarker(n);
        _CreateBoard();

        win_ = winner();

        if(win_ == 1){
            cout << "Player one won! ";
            break;
        }
        if(win_ == 2){
            cout << "Player two won! ";
            break;
        }

        swapturn();
        
        
    }

    if(win_ == 0){
        cout << "Tie!" << endl;
    }

}


int main(){

    playgame();

}