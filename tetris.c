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
//FAST MOVE 	
void moveUpF(void);
void moveDownF(void);
void moveLeftF(void);
void moveRightF(void);
void moveBackF(void);

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

void moveItem110011();
void moveItem111000();
void moveItem011110();
void moveItem110110();
void moveItem111010();
void moveItem010111();

void moveObject();
void Exit();

int behindLeftBeeper();
int behindRightBeeper();
int leftBeeper();
int rightBeeper();
int topBeeper();
int downBeeper();
int rightBeeper();
int rightBeeper();
int behindIsBlocked();
int frontRightBlocked();
int frontLeftBlocked();

//ITEMS
int item111000();
int item110011();
int item011110();
int item110110();
int item011011();
int item111010();
int item010111();


int main()
{ 	turnOn("tetris.kw");
	
	setStepDelay(SPEED);

		moveToItem();
		defineShape();
		moveLeft();
		moveObject();
		Exit();
	turnOff();
return 0;
}


			//Define functions
			//Karel goes to exit

void Exit() {
	loop(2){
		turnRight();
	}
	while ( frontIsClear() || leftIsClear() ) {
		 if (frontIsClear()){
			while (frontIsClear()){
				moveRight();
			}
		}
		else if (leftIsClear() ){
			while(leftIsClear()){
				moveUp();
			}
		}
	}
	if ( rightIsClear() && frontIsBlocked() && leftIsBlocked() ){
		while(rightIsClear()){
			moveDown();
		}
	}
}

// void Exit() {
// 	turnRight();
// 	while( !frontIsBlocked() ) {
// 		moveUp();
// 		if ( frontIsBlocked() )
// 		{	
// 			while(frontIsBlocked() || rightIsClear() ){
// 				moveRight();
// 			}
// 		}
// 	}
// 	while ( rightIsClear() ) {
// 		moveRight();
// 		if ( rightIsBlocked() && frontIsBlocked() )
// 		{
// 			while( !behindIsBlocked() ){
// 				moveDown();
// 			}
// 		}
// 	}
// }

			//Move Objects
void moveObject() {
	setStepDelay(0);
	if ( item111000() )
	{
		moveItem111000();
	}
	else if ( item110011() )
	{
		moveItem110011();
	}
	else if ( item011110() )
	{
		moveItem011110();
	}
	else if ( item110110() )
	{
		moveItem110110();
	}
	else if ( item111010() )
	{
		moveItem111010();
	}
	else if ( item010111() )
	{
		moveItem010111();
	}
}

			//Define Type Of Item 
int item111000() {
	setStepDelay(0);
	if ( behindLeftBeeper() && topBeeper() && behindRightBeeper() && !leftBeeper() && !beepersPresent() && !rightBeeper() )
	{
		return 1;
	}
	else 
		return 0;
}

int item110011() {
	setStepDelay(0);
	if (behindLeftBeeper() && topBeeper() && !behindRightBeeper() && !leftBeeper() && beepersPresent() && rightBeeper() )
	{
		return 1;
	}
	else 
		return 0;
}

int item011110() {
	setStepDelay(0);
	if (!behindLeftBeeper() && topBeeper() && behindRightBeeper() && leftBeeper() && beepersPresent() && !rightBeeper() )
	{
		return 1;
	}
	else 
		return 0;
}

int item110110() {
	setStepDelay(0);
	if (behindLeftBeeper() && topBeeper() && !behindRightBeeper() && leftBeeper() && beepersPresent() && !rightBeeper() )
	{
		return 1;
	}
	else 
		return 0;
}

int item111010() {
	setStepDelay(0);
	if (behindLeftBeeper() && topBeeper() && behindRightBeeper() && !leftBeeper() && beepersPresent() && !rightBeeper() )
	{
		return 1;
	}
	else 
		return 0;
}

int item010111() {
	setStepDelay(0);
	if (!behindLeftBeeper() && topBeeper() && !behindRightBeeper() && leftBeeper() && beepersPresent() && rightBeeper() )
	{
		return 1;
	}
	else 
		return 0;
}

			//Move Items
void moveItem111000() {
		moveUp();
		while (!frontLeftBlocked() && !leftIsBlocked() && !frontRightBlocked()){
				moveLeftBeeper();
				moveCenterBeeper();
				moveRightBeeper();
				moveDown();
			}
}

void moveItem110011() {
		while (!frontIsBlocked() && !leftIsBlocked() && !frontRightBlocked()){
				moveBehindLeftBeeper();
				moveBehindBeeper();
				moveCenterBeeper();
				moveRightBeeper();
				moveDown();
			}
}

void moveItem011110() {
		while (!frontLeftBlocked() && !leftIsBlocked() && !behindIsBlocked()){
				moveBehindLeftBeeper();
				moveBehindBeeper();
				moveBehindRightBeeper();
				moveDown();
			}
}

void moveItem110110() {
		while (!frontLeftBlocked() && !leftIsBlocked()){
				moveBehindLeftBeeper();
				moveBehindBeeper();
				moveLeftBeeper();
				moveCenterBeeper();
				moveDown();
			}
}

void moveItem111010() {
		while (!frontIsBlocked() && !leftIsBlocked() && !behindIsBlocked()){
				moveBehindLeftBeeper();
				moveBehindBeeper();
				moveBehindRightBeeper();
				moveCenterBeeper();
				moveDown();
			}
}

void moveItem010111() {
		while (!frontLeftBlocked() && !leftIsBlocked() && !frontRightBlocked()){
				moveLeftBeeper();
				moveBehindBeeper();
				moveRightBeeper();
				moveCenterBeeper();
				moveDown();
			}
}


			//Additionals Pick & Put & Move Beeper

//MOVE
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

//PICK
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

//PUT
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
	moveUpF();
	moveLeftF();
	if ( beepersPresent() ){
		moveRightF();
		moveDownF();
		return 1;
	}	
	else {	 
		moveRightF();
		moveDownF();
		return 0;
	}		
}

int behindRightBeeper() {
	setStepDelay(0);
	moveUpF();
	moveRightF();
	if ( beepersPresent() ){
		moveLeftF();
		moveDownF();
		return 1;
	}	
	else {	 
		moveLeftF();
		moveDownF();
		return 0;
	}		
}

int leftBeeper() {
	setStepDelay(0);
	moveLeftF();
	if ( beepersPresent() ){
		moveRightF();
		return 1;
	}	
	else {	 
		moveRightF();
		return 0;
	}		
}

int rightBeeper() {
	setStepDelay(0);
	moveRightF();
	if ( beepersPresent() ){
		moveLeftF();
		return 1;
	}	
	else {
		moveLeftF();
		return 0;
	}		
}

int topBeeper() {
	setStepDelay(0);
	moveUpF();
	if ( beepersPresent() ){
		moveDownF();
		return 1;
	}	
	else {	 
		moveDownF();
		return 0;
	}		
}

int downBeeper() {
	setStepDelay(0);
	moveDownF();
	if ( beepersPresent() ){
		moveUpF();
		return 1;
	}	
	else {	 
		moveUpF();
		return 0;
	}		
}

			//Additions Block Sensors
int behindIsBlocked() {
	setStepDelay(0);
	turnBack();
	if (frontIsBlocked())
	{
		return 1;
	}
	else
		return 0;
}

int frontLeftBlocked(){
	setStepDelay(0);
	moveLeftF();
	if ( leftIsBlocked() )
	{
		moveRightF();
		return 1;
	}
	else {
		moveRightF();
		return 0;
	}
}

int frontRightBlocked(){
	setStepDelay(0);
	moveRightF();
	if ( leftIsBlocked() )
	{
		moveLeftF();
		return 1;
	}
	else {
		moveLeftF();
		return 0;
	}
}


			//Define Shape of Item
void defineShape() {
	setStepDelay(0);
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
	setStepDelay(0);
	loop(3) {
		turnLeft();
	}
}

	
			//Turn Back
void turnBack() {
	setStepDelay(0);
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


			//Moves for Define of Item
void moveUpF(void) {
	setStepDelay(0);
	if (facingNorth())
	{	
		movek();
	}
	else if (facingSouth())
	{
		moveBackF();
	}
	else if (facingEast())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		turnLeft();
	}
	else if (facingWest())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		movek();
		turnLeft();
	}
}

void moveLeftF(void) {
	setStepDelay(0);
	if (facingWest())
	{	
		movek();
	}
	else if (facingEast())
	{
		moveBackF();
	}
	else if (facingNorth())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		turnLeft();
	}
	else if (facingSouth())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		movek();
		turnLeft();
	}
}

void moveRightF(void){
	setStepDelay(0);
	if (facingEast())
	{	
		movek();
	}
	else if (facingWest())
	{	
		moveBackF();
	}
	else if (facingSouth())
	{
		turnLeft();
		movek();
		turnLeft();
		turnLeft();
		turnLeft();
	}
	else if (facingNorth())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		movek();
		turnLeft();
	}
}

void moveDownF(void){
	setStepDelay(0);
	if (facingSouth())
	{	
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
		turnLeft();
	}
	else if (facingEast())
	{
		turnLeft();
		turnLeft();
		turnLeft();
		movek();
		turnLeft();
	}
}

void moveBackF(void){
   setStepDelay(0);
   turnLeft();
   turnLeft();
   movek();
   turnLeft();
   turnLeft();
}
			//Karel Moves for Animation
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
	setStepDelay(0);
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
	setStepDelay(0);
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
	setStepDelay(0);
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
	setStepDelay(0);
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