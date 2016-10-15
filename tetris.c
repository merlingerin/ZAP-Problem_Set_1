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
//MOVE KAREL
void moveUp(void);
void moveDown(void);
void moveLeft(void);
void moveRight(void);
void moveBack(void);
//DROW
void drowLeftSide11();
void drowLeftSide01();
void drowLeftSide10();
void drowCenter11();
void drowCenter10();
void drowRightSide11();
void drowRightSide10();
void drowRightSide01();
void drowRightSide00();
//PICK
void pickAllBeeper();
void pickLeftBeeper();
void pickRightBeeper();
void pickBehindBeeper();
void pickBehindLeftBeeper();
void pickBehindRightBeeper();
void pickCenterBeeper();
//PUT
void putAllBeeper();
void putCenterBeeper();
void putLeftBeeper();
void putRightBeeper();
void putBehindBeeper();
void putBehindRightBeeper();
void putBehindLeftBeeper();

//MOVE BEEPER
void moveBehindRightBeeper();
void moveBehindLeftBeeper();
void moveBehindBeeper();
void moveLeftBeeper();
void moveRightBeeper();
void moveCenterBeeper();



int leftBeeper();
int rightBeeper();
int topBeeper();
int downBeeper();
int rightBeeper();
int rightBeeper();
int frontRightBlocked();
int frontLeftBlocked();




int main()
{ 	turnOn("tetris.kw");
	
	setStepDelay(100);


		moveToItem();
		defineShape();
		moveLeft();
		moveBehindLeftBeeper();
		moveBehindBeeper();
		moveCenterBeeper();
		moveRightBeeper();
		// if (leftBeeper() && beepersPresent() && rightBeeper() )
		// {
		// 	if (!frontLeftBlocked() && !leftIsBlocked() && !frontRightBlocked() )
		// 	{
		// 		pickAllBeeper();
		// 		putAllBeeper();
		// 	}
		// }
		// else if (leftBeeper() && beepersPresent() && !rightBeeper()) {
		// 	if (!frontLeftBlocked() && !leftIsBlocked())
		// 	{
		// 		putLeftBeeper();
		// 		putCenterBeeper();
		// 	}
		// }
		// else if (!leftBeeper() && beepersPresent() && rightBeeper())
		// {
		// 	if
		// }
		
	turnOff();
return 0;
}


			//Define functions

			//Define Type Of Item 
// void item111000() {
// 	if ( behindleftBeeper() && topBeeper() && behindRightBeeper() )
// 	{
// 		while( !frontLeftBlocked() && !leftIsBlocked() && frontRightBlocked() ) {
// 			putLeftBeeper();
// 			putCenterBeeper();
// 			putRightBeeper();
// 		}

// 	}
// }

			//Additionals Pick & Put & Move Beeper
void moveBehindBeeper() {
	pickBehindBeeper();
	putBeeper();
}

void moveBehindLeftBeeper() {
	pickBehindLeftBeeper();
	putBehindLeftBeeper();
}

void moveBehindRightBeeper() {
	pickBehindRightBeeper();
	putBehindRightBeeper();
}

void moveLeftBeeper() {
	pickLeftBeeper();
	putLeftBeeper();
}

void moveRightBeeper() {
	pickRightBeeper();
	putRightBeeper();
}

void moveCenterBeeper() {
	pickCenterBeeper();
	moveDown();
	putBeeper();
	moveUp();
}


// void moveleftBeeper() {
// 	pickLeftBeeper();
// 	putLeftBeeper();
// }
// void moveleftBeeper() {
// 	pickLeftBeeper();
// 	putLeftBeeper();
// }

// void moveleftBeeper() {
// 	pickLeftBeeper();
// 	putLeftBeeper();
// }

// void moveleftBeeper() {
// 	pickLeftBeeper();
// 	putLeftBeeper();
// }


void pickCenterBeeper() {
	if ( beepersPresent() )
	{
		pickBeeper();
	}
}
void pickLeftBeeper() {
	moveLeft();
	if ( beepersPresent() )
	{
		pickBeeper();
		moveRight();
	}
	else {
		moveRight();
	}
}

void pickRightBeeper() {
	moveRight();
	if ( beepersPresent() )
	{
		pickBeeper();
		moveLeft();
	}
	else {
		moveLeft();
	}	
}

void pickBehindRightBeeper() {
	moveUp();
	moveRight();
	if ( beepersPresent() )
	{
		pickBeeper();
		moveLeft();
		moveDown();
	}
	else {
		moveLeft();
		moveDown();
	}	
}

void pickBehindLeftBeeper() {
	moveUp();
	moveLeft();
	if ( beepersPresent() )
	{
		pickBeeper();
		moveRight();
		moveDown();

	}
	else {
		moveRight();
		moveDown();
	}	
}

void pickBehindBeeper() {
	moveUp();
	if ( beepersPresent() )
	{
		pickBeeper();
		moveDown();
	}
	else {
		moveDown();
	}	
}

void putAllBeeper() {
	putCenterBeeper();
	putLeftBeeper();
	putRightBeeper();
}

void putCenterBeeper() {
	moveDown();
	putBeeper();
	moveUp();
}

void putLeftBeeper() {
	moveDown();
	moveLeft();
	putBeeper();
	moveRight();
	moveUp();
}

void putRightBeeper() {
	moveDown();
	moveRight();
	putBeeper();
	moveLeft();
	moveUp();
}

void putBehindLeftBeeper() {
	moveLeft();
	putBeeper();
	moveRight();
}

void putBehindRightBeeper() {
	moveRight();
	putBeeper();
	moveLeft();
}
			//Additionals Sensors

int behindLeftBeeper() {
	setStepDelay(0);
	moveUp();
	moveLeft();
	if ( beepersPresent() ){
		setStepDelay(SPEED);
		moveRight();
		moveDown();
		return 1;
	}	
	else {	 
		moveRight();
		moveDown();
		return 0;
	}		
}

int behindRightBeeper() {
	setStepDelay(0);
	moveUp();
	moveRight();
	if ( beepersPresent() ){
		setStepDelay(SPEED);
		moveLeft();
		moveDown();
		return 1;
	}	
	else {	 
		moveLeft();
		moveDown();
		return 0;
	}		
}

int leftBeeper() {
	setStepDelay(0);
	moveLeft();
	if ( beepersPresent() ){
		setStepDelay(SPEED);
		moveRight();
		return 1;
	}	
	else {	 
		moveRight();
		return 0;
	}		
}

int rightBeeper() {
	setStepDelay(0);
	moveRight();
	if ( beepersPresent() ){
		moveLeft();
		return 1;
	}	
	else {
		moveLeft();
		return 0;
	}		
}

int topBeeper() {
	setStepDelay(0);
	moveUp();
	if ( beepersPresent() ){
		moveDown();
		return 1;
	}	
	else {	 
		moveDown();
		return 0;
	}		
}

int downBeeper() {
	setStepDelay(0);
	moveDown();
	if ( beepersPresent() ){
		moveUp();
		return 1;
	}	
	else {	 
		moveUp();
		return 0;
	}		
}

			//Additions Block Sensors
int frontLeftBlocked(){
	moveLeft();
	if ( leftIsBlocked() )
	{
		moveRight();
		return 1;
	}
	else {
		moveRight();
		return 0;
	}
}

int frontRightBlocked(){
	moveRight();
	if ( leftIsBlocked() )
	{
		moveLeft();
		return 1;
	}
	else {
		moveLeft();
		return 0;
	}
}


			//Define Shape of Item
void defineShape() {
	defineLeftSide();
	defineCenterSide();
	defineRightSide();

}

			//Define Right Side Of Item
void defineRightSide() {
	moveRight();
	moveUp();
	moveRight();
	moveUp();
	moveUp();
	turnBack();
	if ( frontIsBlocked() )
	{
		moveDown();
		if ( frontIsBlocked() )
		{
			drowRightSide11();
		}
		else {
			drowRightSide10();
		}
	}
	else if ( frontIsClear() ) {
		moveDown();
		if ( frontIsClear() )
		{
			drowRightSide00();
		}
		else {
			drowRightSide01();
		}
	}

}
			//Define Center Side Of Item
void defineCenterSide() {
	moveUp();
	moveRight();
	if ( leftIsBlocked() )
	{
		drowCenter11();
	}
	else {
		drowCenter10();
	}
}

			//Define Left Side Of Item
void defineLeftSide() {
	if ( frontIsBlocked() && rightIsBlocked() ){
			drowLeftSide01();
	}
	else if ( frontIsBlocked() && rightIsClear() ){
		moveDown();
		if ( frontIsBlocked() ){
			drowLeftSide11();
		}
		else {
			drowLeftSide10();
		}		
	}
}

			//Drow Right Side
void drowRightSide10(){
	moveDown();
	moveLeft();
	putBeeper();
	moveDown();
}

void drowRightSide11(){
	moveDown();
	moveLeft();
	putBeeper();
	moveDown();
	putBeeper();
}

void drowRightSide01(){
	moveDown();
	moveLeft();
	moveDown();
	putBeeper();
}

void drowRightSide00(){
	moveDown();
	moveLeft();
	moveDown();
	moveDown();
}

			//Drow Center
void drowCenter11() {
	putBeeper();
	moveDown();
	putBeeper();
}

void drowCenter10() {
	putBeeper();
	moveDown();
}

			//Drow Left Side
void drowLeftSide01() {
	moveLeft();
	moveDown();
	moveDown();
	moveRight();
	moveDown();
	putBeeper();
}

void drowLeftSide10() {
	moveDown();
	moveRight();
	putBeeper();
	moveDown();
}

void drowLeftSide11() {
	moveDown();
	moveRight();
	putBeeper();
	moveDown();
	putBeeper();
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
		moveUp();		
	}
	turnRight();
	while( frontIsClear() ){
		moveRight();		
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
		movek();
		setStepDelay(SPEED);
		turnLeft();
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
		movek();
		setStepDelay(SPEED);
		turnLeft();
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