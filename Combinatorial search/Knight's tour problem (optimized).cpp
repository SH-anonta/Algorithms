//Knight's tour problem
//give a square in the 8x8 chess board find a path that visits every square of the board exactly once
//the path must move from one square to another like a knight
//

#include <iostream>
#include <cstdio>
#include <cstring>

int cx, cy; //current position coordinates x and y

//parallel arrays to store knight's 8 moves
int x_move[8]= {2, 1, -1, -2, -2, -1,  1,  2};
int y_move[8]= {1, 2,  2,  1, -1, -2, -2, -1};

void printBoard(int board[8][8]);

//optimization (search pruning)
//see of any unvisited square is unreachable/ impossible to reach from current position
bool deadEnd(int board[8][8]){
    int next_x, next_y;
    bool reachable;
    //check every square
    for(int x= 0; x<8; x++){
        for(int y= 0; y<8; y++){
            //if this square has been visited
            if(board[x][y] != -1) continue;
            
            reachable= false;
            for(int move_i= 0; move_i<8; move_i++){
                next_x= x+x_move[move_i];
                next_y= y+y_move[move_i];
                //next move is illegal
                if(next_x<0 || next_y<0 || next_x>7 || next_y>7) continue;
                //if current position is at next move
                if(next_x == cx && next_y == cy) return false;
                
                if(board[next_x][next_y] == -1){
                    reachable = true;
                    break;
                }
            }
            
            //if a square is unreachable the current path is a dead end
            if(reachable == false) return true;
        }
    }

    return false;
}

//keep count of recursive calls
long long cc= 0;

bool knightTourPath(int board[8][8], short x, short y, short count){
    cc++;

    //if path has been found (all squares have been visited)
    if(count == 64){
        std::cout<< "recursive calls: "<< cc<<"\n\n";
        board[x][y]= count;
        printBoard(board);
        return true;
    }
    
    if(count>32 && deadEnd(board)){
        return false;
    }
    
    board[x][y]= count;

    bool path_found= false;
    int next_x, next_y;
    
    for(int move_i= 0; move_i<8; move_i++){
        next_x= x+x_move[move_i];
        next_y= y+y_move[move_i];

        //check if next move is legal [illegal if it goes out of the board or next square has already been visited]
        if(next_x<0 || next_y<0 || next_x>7 || next_y>7 || board[next_x][next_y] != -1) continue;
        
        path_found= knightTourPath(board, next_x, next_y, count+1);
        
        //dont try other path if a path is found
        if(path_found == true) return true;
    }
    
    board[x][y]= -1;
    //if all path failed return false
    return false;
}


//wrapper function
void knightTourPath(int x, int y){
    int board[8][8];
    //mark every square as unvisited
    memset(board, -1, sizeof(int)*8*8);
    
    knightTourPath(board, x, y, 1);
}

int main(void)
{
    using namespace std;
    
    knightTourPath(0,0);
    
    return 0;
}

//print the board's current state
// -1 means unvisited and n>0 is the nth move/visited square 
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
