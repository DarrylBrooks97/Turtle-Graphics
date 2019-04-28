#include "classMovements.h"

		void Instructions::readData(){                   //Gets commands from file
			string temp,temporyMove,s;
			ifstream doc;
			vector<string> tempCommands;
			vector<string> realCommands;
			doc.open("Instruction.dat");
			
			while(!doc.eof()){                          //Parses the commands by ' , '
				getline(doc,temp,',');
				tempCommands.push_back(temp);
			}
			
			for(int i=0;i<tempCommands.size();i++){
				temporyMove = tempCommands[i];             // Stores the parsed commands into variable 
				istringstream stringStream(temporyMove);
				while(getline(stringStream,s,' ')){            // Parses the commands again expect by spaces and stores them
					realCommands.push_back(s);
				}
			}
			for(int j=0; j<realCommands.size(); j++){
				commands.push_back(atoi(realCommands[j].c_str()));    //Converts all string commands into integers and places them into the actual commands list 
			}
			doc.close();
		}	

		void Movements::loadFloor(){
			for(int i=0;i<20;i++){
				for(int j=0; j<20;j++){
					floor[i][j] = false;
				}
			}
		}

		void Movements::setMembers(){
			orientation = 'U';
			row = 19;
			col = 0;
			floor[row][col] = false;
		}
	
		void Movements::moveForward(int distance,bool penDown){
			int lastRow = row;
			int lastCol = col;
			if(orientation == 'U'){
				
				row -= distance;
				if(row<0) {
					row += distance; 
				}else if((row>0) && (penDown==true)){
					for(int k=0;k<=distance;k++){
						floor[lastRow-k][col] = true;        //Makes a trail of where the turtle walked
					}
				}
				
			}
			if(orientation == 'L'){
				
				col -= distance;
				
				if(col<0) {
					col += distance;
				} else if((col>0) && (penDown==true)){
					for(int k=0;k<=distance;k++){
						floor[row][lastCol-k] = true;        //Makes a trail of where the turtle walked
					}
				}
			
			}
			if(orientation == 'R'){
				
				col += distance;
				if(col>20) {
					col -= distance;
				} else if((col<20) && (penDown==true)) {
					for(int k=0;k<=distance;k++){
						floor[row][lastCol+k] = true;        //Makes a trail of where the turtle walked
					}
				}
			
			}
			if(orientation == 'D'){
				
				row += distance;
				
				if(row>20) {
					row -= distance;
				}else if((row<20) && (penDown==true)){
					for(int k=0;k<=distance;k++){
						floor[lastRow+k][col] = true;        //Makes a trail of where the turtle walked
					}
				}
			}
		}
	
		void Movements::Moves(int steps,int dis,bool penDown){
			
			switch(steps){
				case 3:
					if(orientation == 'U') orientation = 'R';
					else if(orientation == 'L') orientation = 'U';
					else if(orientation == 'R') orientation = 'D';
					else orientation = 'L';
					break;
				case 4:
					if(orientation == 'U') orientation = 'L';
					else if(orientation == 'L') orientation = 'D';
					else if(orientation == 'R') orientation = 'U';
					else orientation = 'R';
					break;
				case 5:
					moveForward(dis,penDown);
					break;
				case 6:
					printFloor();
					break;
				case 9:
					exit(0);
					break;
				default:
					cout<<steps<<" is an incorrect value"<<endl;
					exit(0);
					break;
			}
		}

		void Movements::printFloor(){
			cout<<"=========== Turtle's Postion =========="<<endl;
			for(int m=0; m<20;m++){
				for(int n=0;n<20;n++){
					if(floor[m][n] == true)cout<<"X ";
					else cout<<"  ";
				}
				cout<<endl;
			}
			cout<<"=======================================";
			cout<<endl;
		}

	
