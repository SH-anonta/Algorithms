//Knight's tour problem
//give a square in the 8x8 chess board find a path that visits every square of the board exactly once
//the path must move from one square to another like a knight

#include <iostream>
#include <cstdio>

void printBoard(int board[8][8]){
    std::cout<<"  ";
    for(int i= 0; i<8; i++){
        std::cout.width(2);
        std::cout<< i+1 <<" ";
    }
    std::cout<<std::endl;

    for(int r= 0; r<8; r++){
        std::cout<< char(r+'A') <<" ";
        for(int c= 0; c<8; c++){
            std::cout.width(2);
            std::cout<< board[r][c] <<" ";
        }
        std::cout<<std::endl;
    }
}

//TODO see if current path is a dead end
bool seek(int board[8][8]){
    for(int r= 0; r<8; r++){
        for(int c= 0; c<8; c++){
            
        }
    }
}

bool knightTourPath(int board[8][8], short x, short y, short count){
    //if path has been found (all squares have been visited)
    if(count == 65){
        printBoard(board);
        return true;
    }
    //if path tries to leave the board
    if(x<0 || y<0 || x>7 || y>7) return false;
    
    //if this square has been visited already
    if(board[x][y] != 0) return false;
    
    board[x][y]= count;
    //here if apath has been found true will be returned
    bool res= knightTourPath(board, x+2, y+1, count+1)
           || knightTourPath(board, x+1, y+2, count+1)
           || knightTourPath(board, x-1, y+2, count+1)
           || knightTourPath(board, x-2, y+1, count+1)
           || knightTourPath(board, x-2, y-1, count+1)
           || knightTourPath(board, x-1, y-2, count+1)
           || knightTourPath(board, x+1, y-2, count+1)
           || knightTourPath(board, x+2, y-1, count+1);

    if(res == true) return true;
    board[x][y]= 0;
    return res;
}


//wrapper function
void knightTourPath(int x, int y){
    int board[8][8];
    //mark every square as unvisited
    for(int r= 0; r<8; r++){
        for(int c= 0; c<8; c++){
            board[r][c]= 0;
        }
    }
    
//    board[0][0]= 1;
    knightTourPath(board, x, y, 1);
}

int main(void)
{
    using namespace std;
    
    knightTourPath(0,0);
    
    return 0;
}