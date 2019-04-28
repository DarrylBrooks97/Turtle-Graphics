#include "classMovements.h"

int main(){

	Instructions instructObj;
	Movements movObj;
	
	int move,moveHolder,turtDis=0, i = 0;
	bool moveFoward =false;
	instructObj.readData();       // Reads data into commands vector 
	movObj.loadFloor();           // Loads floor array with false
	movObj.setMembers();          // Initilizes public members 
	
	if(instructObj.commands.back()!=9){
		cout<<"File does not end with 9"<<endl; exit(0);        //Checks to see if file has ending statement 
	}
	move = instructObj.commands[i];
	
	if((move != 1) && (move != 2) ){                           
		cout<<"Command file must start with a 1 or 2"<<endl;    //Checks to see if file has starter statements   
		exit(0);
	}
	
	while((move != 9) && (i<instructObj.commands.size())){
		  move = instructObj.commands[i];
		
		  while((move!=2) && (i<instructObj.commands.size())){   //Move = 1
			moveHolder = instructObj.commands[i];
			  if((moveHolder == 2) && (moveFoward == false)) break;
			  move = moveHolder;
			  if(i==0){
				  ++i;
			  } else {
				   if((move==5) && (moveFoward==false)){        // If the program sees a '5' it will notice that the next integer is the distance to be moved
						moveFoward = true;
					}else{
					   
					   if(moveFoward==true){
							turtDis = move;
							movObj.Moves(5,turtDis,false);
							moveFoward = false;
						} 
						else{
							if(move!=1){
								movObj.Moves(move,0,false);
// 								cout<<"Orientation: "<<movObj.orientation<<endl;
							}
							
						}
				     }
				   ++i;
			    }
			
		 }
		  
		  
		  while(i<instructObj.commands.size()){   //Move = 2 
			  moveHolder = instructObj.commands[i];
			  if((moveHolder == 1) && (moveFoward == false)) break;
			  move = moveHolder;
			  if(i==0){
				  ++i;
			  } else {
				   if((move==5) && (moveFoward==false)){        // If the program sees a '5' it will notice that the next integer is the distance to be moved
						moveFoward = true;
					}else{
					   
					   if(moveFoward==true){
							turtDis = move;
							movObj.Moves(5,turtDis,true);
							moveFoward = false;
						} 
						else{
							if(move!=2){
								movObj.Moves(move,0,true);
// 								cout<<"OrientationX: "<<movObj.orientation<<endl;
							}
							
						}
				     }
				   ++i;
			    }
			
		 }
		    ++i;
	}
	
	return 0;
}


