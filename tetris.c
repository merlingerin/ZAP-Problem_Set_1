						
						//ALGORITHM 1


#include "karel.h"

int main()
{ 	turnOn("tetris.kw");

	while( rightIsBlocked() ){
		while( frontIsClear() ){
			movek();
			if ( frontIsBlocked() )
			{	
				if ( noBeepersPresent() )
				{
					putBeeper();
				}
				turnLeft();
			}
		}

	}
	

	turnOff();
return 0;
}


						//ALGORITHM 2



#include "karel.h"

// int main()
// { 	turnOn("marker3.kw");

// 	while( beepersInBad() > 4 ){
// 		while( frontIsClear() ){
// 			movek();
// 			if ( frontIsBlocked() )
// 			{	
// 				if ( noBeepersPresent() )
// 				{
// 					putBeeper();
// 				}
// 				turnLeft();
// 			}
// 		}

// 	}
	

// 	turnOff();
// return 0;
// }



						//ALGORIGHTM 3



// #include "karel.h"

// int main()
// { 	turnOn("marker2.kw");

// int count = 0;

// 			while( count != 4 ){
// 				movek();
// 				if ( frontIsBlocked() )
// 				{	
// 					if (!beepersPresent())
// 					{
// 						putBeeper();
// 						count++;
// 					}
// 					else 
// 					count++;	
// 					turnLeft();
// 				}
// 			}

// 	turnOff();
// return 0;
// }