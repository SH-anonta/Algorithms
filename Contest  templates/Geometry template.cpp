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
    point(int xx, int yy){x= xx; y= yy;}
};

class segment{
    public:
    point a, b;

    //return the determinant of the matrix which represents a triangle
    int determinant(point p){
        return a.x*(b.y - p.y) - a.y*(b.x - p.x) + (b.x*p.y - p.x * b.y);
    }

    bool pointsOnSameSide(point A, point B){
        int p1= determinant(A);
        int p2= determinant(B);

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
    
    segment(point aa, point bb){a= aa;b=bb;}
    segment(){}
};



int main(){
    point p(3,1);
    point q(3,3);

    point a(-2 ,-3);
    point b(-2 ,-2);


    segment s(p,q);
    segment t(a,b);

    cout<< q.distance(p)<<endl;

    return 0;
}
