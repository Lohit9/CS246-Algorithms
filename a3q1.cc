#include <iostream>
#include <string>
using namespace std;

#include "drone.h"
struct Position
{
	int ew,ns, count;

	Position(int ew=0 , int ns =0, int count =0)
	{
		this->ew = ew;
		this->ns = ns;
		this->count = count;
	}

	 void forward()  // – move one unit forward
    {
    	this->ns ++;
    	this->count++;
 	

    }

     void backward()
     {
     	this->ns -- ;
     	this->count++;
     }

     void left()
     {
     	this->ew--;
     	this->count++;
     }

     void right()
     {
     	this->ew ++ ;
     	this->count++;
     }

     int totalDistance()
     {
     	return this->count;
     }

     int manhattanDistance()
     {
     	int x =this->ns;
     	int y = this->ew;
     	int dist = x - y;
     	if (dist<0) return -dist;
     	return dist ;
     }

     bool repeated()
     {
     	return 1;

     }
};





 



int main() {
  Drone d;
  Position p;
  char c;
  while (cin >> c) {
    switch(c) {
      case 'f':
        d.forward();
        break;
      case 'b':
        d.backward();
        break;
      case 'l':
        d.left();
        break;
      case 'r':
        d.right();
        break;
      case 'c':
        p = d.current();
        cout << p.ew << " " << p.ns << endl;
        cout << (d.repeated() ? "Repeated" : "Not repeated") << endl;
        break;
      case 't':
        cout << d.totalDistance() << endl;
        break;
      case 'm':
        cout << d.manhattanDistance() << endl;
    }
  }
}




