#ifndef CLASSMOVEMENTS_H
#define CLASSMOVEMENTS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
						             //********Copy and paste different commands from my commandsList.txt******
class Instructions{
	public:
		vector<int> commands;    //Holds commands
		void readData();         //Reads instruction file
};

class Movements{
	private:
		bool floor[20][20];
	public:
	
		char orientation;     
		int row;                //Floor row
		int col;                //Floor col
	
		void loadFloor();      //Loads the floor of falses
	  void printFloor();     //Prints the floor
	  void moveForward(int,bool);  //Moves the turtle forward
		void Moves(int,int,bool);   // List of actions the turtle can do
		void setMembers();         //Initializes the turtle at position (0,0) however in the array this position is (19,0)
};



#endif
