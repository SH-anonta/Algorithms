#include <iostream>
#include <cmath>

using namespace std;

class point{
    public:
    double x, y;
    
    double distance(point p){
        int xlen= x-p.x;
        int ylen= y-p.y;
        return sqrt(xlen*xlen+ylen*ylen);
    }
    
    point(){}
    point(int xx, int yy){x= xx; y= yy; }
};

class segment{
    public:
    point a, b;

    //return the determinant of the matrix which represents a triangle
    
    double slope(){
        if(a.x == b.x) return 0; //this case would cause error
        
        return (a.y-b.y)/(a.x-b.x);
    }
    
    //positive = anti clockwise, negative = clockwise, 0 = collinear
    double orientation(point p){
        return a.x*(b.y - p.y) - a.y*(b.x - p.x) + (b.x*p.y - p.x * b.y);
    }

    bool pointsOnSameSide(point A, point B){
        int p1= orientation(A);
        int p2= orientation(B);

        if(p1 >= 0 && p2 >= 0 || p1 <= 0 && p2 <= 0) return true;

        return false;
    }

    //check with slope if two segments are parallel
    bool isParallel(segment other){
        return (a.y - b.y) * (other.a.x - other.b.x)
            == (a.x - b.x) * (other.a.y - other.b.y);
    }

    bool intersects(){

    }
    
    segment(point aa, point bb){a= aa;b=bb; if(a.x > b.x) swap(a, b);}
    segment(){}
};



int main(){
    point p(46,-2);
    point q(2,50);

    point a(-2 ,-3);
    point b(-2 ,-2);


    segment s(p,q);
    segment t(a,b);

    cout<< s.slope() <<endl;

    return 0;
}
