#include "karel.h"

void defineLeftSide();
void defineShape();
void climbStairs();
void turnBack();
void turnRight();
void moveToItem();
void item1();

int main()
{ 	turnOn("tetris1.kw");
	
	setStepDelay(100);
	moveToItem();
	defineShape();
	turnOff();
return 0;
}
			//Define functions


			//Define Shape of Item
void defineShape() {
	if ( frontIsBlocked() )
	{
		turnRight();
		defineLeftSide();
	}
}

			//Define Center Side Of Item
void defineCenterSide() {
	if (!frontIsBlocked())
			{
				movek();
				putBeeper();
			}
	else {
		turnRight();
		movek();
		turnLeft();
		movek();
		loop(2){
			putBeeper();
		}
	}		
}

			//Define Left Side Of Item
void defineLeftSide() {
	if ( leftIsBlocked() )
		{
			movek();
			if ( leftIsBlocked() )
			{
				movek();
				turnLeft();
				movek();
				loop(2){
					putBeeper();
				}
			}
			else {
				turnLeft();
				movek();
				putBeeper();
			}
		}
}


			//Turn Right
void turnRight() {
	loop(3) {
		turnLeft();
	}
}


			//Move Back
void moveBack() {
	loop(2) {
		turnLeft();
	}
	movek();
}
	
			//Turn Back
void turnBack() {
	loop(2) {
		turnLeft();
	}
}

			//Climb Stairs
void climbStairs() {
	if ( rightIsBlocked() )
	{
		turnBack();
	}
}

			//MovekToItem
void moveToItem() {
	while( frontIsClear() ){
		movek();		
	}
	turnRight();
	while( frontIsClear() ){
		movek();		
	}
}

			//Define Type Of Item 1
void item1() {
	if (frontIsBlocked() && rightIsClear()) {
		turnRight();
		movek();
		if (rightIsClear()){
			turnLeft();
			movek();
		}
		while(leftIsBlocked()){
			movek();
		}
	}
}

			//Search place for Item1
void placeForItem1() {
	moveBack();
	movek();
	turnLeft();
	while ( frontIsClear() && rightIsClear() ) {
		movek();
		if ( rightIsBlocked() )
		{
			moveBack();
		}

	}


}