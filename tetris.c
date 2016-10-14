#include "karel.h"

#define SPEED 100

void defineRightSide();
void defineCenterSide();
void defineLeftSide();
void defineShape();
void climbStairs();
void turnBack();
void turnRight();
void moveToItem();
void item1();
void moveUp(void);
void moveDown(void);
void moveLeft(void);
void moveRight(void);
void moveBack(void);


int main()
{ 	turnOn("tetris.kw");
	
	setStepDelay(100);
	while(frontIsClear()){
		moveUp();
		moveDown();
	}

	// moveToItem();
	// defineShape();
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
		defineCenterSide();
		defineRightSide();
	}
}

			//Define Right Side Of Item
void defineRightSide() {
	movek();
	if ( leftIsBlocked() )
	{
		putBeeper();
	}
	else {
		turnLeft();
		movek();
		putBeeper();
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
// void moveBack() {
// 	loop(2) {
// 		turnLeft();
// 	}
// 	movek();
// }
	
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

void moveUp(void) {
	setStepDelay(20);
	if (facingNorth())
	{	
		setStepDelay(SPEED);
		movek();
	}
	else if (facingSouth())
	{
		moveBack();
	}
	else if (facingEast())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		setStepDelay(SPEED);
		turnLeft();
	}
	else if (facingWest())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		setStepDelay(SPEED);
		movek();
	}
}

void moveLeft(void) {
	setStepDelay(20);
	if (facingWest())
	{	
		setStepDelay(SPEED);
		movek();
	}
	else if (facingEast())
	{
		moveBack();
	}
	else if (facingNorth())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		setStepDelay(SPEED);
		turnLeft();
	}
	else if (facingSouth())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		movek();
		setStepDelay(SPEED);
		turnLeft();
	}
}

void moveRight(void){
	setStepDelay(20);
	if (facingEast())
	{	
		setStepDelay(SPEED);
		movek();
	}
	else if (facingWest())
	{	
		moveBack();
	}
	else if (facingSouth())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		setStepDelay(SPEED);
		turnLeft();
	}
	else if (facingNorth())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		movek();
		setStepDelay(SPEED);
		turnLeft();
	}
}

void moveDown(void){
	setStepDelay(100);
	if (facingSouth())
	{	
		setStepDelay(SPEED);
		movek();
	}
	else if (facingNorth())
	{
		moveBack();
	}
	else if (facingWest())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		setStepDelay(SPEED);
		turnLeft();
	}
	else if (facingEast())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		setStepDelay(SPEED);
		movek();
	}
}

void moveBack(void){
   setStepDelay(0);
   turnLeft();
   turnLeft();
   movek();
   turnLeft();
   setStepDelay(SPEED);
   turnLeft();
}