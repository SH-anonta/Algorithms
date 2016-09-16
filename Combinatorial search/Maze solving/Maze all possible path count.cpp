//maze solving algorithm
//given a maze of 2d array find the number of simple paths from point S to point E
//valid moves are up, down, left and right

/*
 * Sample inputs
 
4 4
####
#S #
# E#
####
  
##########
#   S    #
# #  #  ##
# # #### #
#       ##
# ##  E  #
##########
 
##########
# # S    #
# #  #  ##
# ####   #
#        #
# #### E #
##########
 
 */
#include <utility>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
//Macros
short CC_;
#define sf scanf
#define pf printf
#define PP getchar();
#define NL cout<<"\n";
#define pqueue priority_queue
#define testb(x_, i_) ((x_&1<<i_)!=0)
#define setb(x_, i_) (x_=(x_|(1<<i_)))
#define clrb(x_, i_) (x_=(x_&(!(1<<i_))))
#define all(container) container.begin(),container.end()
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

//symbol to represent wall
const char WALL_SYMB= '#';
const int max_size= 100;
char maze[max_size][max_size];
int grow, gcol;

//for debugging
void printMaze(){
    cout<<endl;
    for(int r= 0; r<grow; r++){
        for(int c= 0; c<gcol; c++){
            cout<<maze[r][c];
        }
        cout<<endl;
    }
}

long long pathCount(int xpos, int ypos, const int szx, const int szy){
    //path goes out of grid/maze
    if(xpos<0 || ypos< 0 || xpos>=szx || ypos>= szy) return 0;
    
    //path tries to go through wall
    if(maze[xpos][ypos] == WALL_SYMB || maze[xpos][ypos] == 'V') return 0;
    
    //if path has reached end point. count this path
    if(maze[xpos][ypos] == 'E'){
//        printMaze();      //to see the path in maze (trail of 'V's)
        return 1;
    }
    
    int sum= 0;
    //mark current position as visited square
    char temp= maze[xpos][ypos];
    maze[xpos][ypos]= 'V';
    
    //try all four direction
    sum+= pathCount(xpos+1, ypos, szx, szy);
    sum+= pathCount(xpos-1, ypos, szx, szy);
    sum+= pathCount(xpos, ypos+1, szx, szy);
    sum+= pathCount(xpos, ypos-1, szx, szy);
    
    //un marking it as visited so other paths don't skip this square
    maze[xpos][ypos]= temp;
    
    return sum;
}

//wrapper function
//pointer to matrix and it's size
long long pathCount(int row, int col){
    int startx, starty;
    
    for(int r= 0; r<row; r++){
        for(int c= 0; c<col; c++){
            if(maze[r][c] == 'S'){
                startx= r;
                starty= c;
                break;
            }
        }
    }
    
    return pathCount(startx, starty, row, col);
}


int main(void)
{
    using namespace std;
    
    int row, col;
    
    while(cin>>row>>col && row != 0 && col != 0){
        grow= row;
        gcol= col;
        for(int r= 0; r<row; r++){
            for(int c= 0; c<col; c++){
                //incase end of line is reached ignore it
                maze[r][c]= cin.get();
                if(maze[r][c] == '\n') c--;
            }
        }
        
        cout<< pathCount(row, col) <<endl;
        
    }
    
    return 0;
}