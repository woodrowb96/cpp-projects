
/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/


#include "Fire.h"

Fire::Fire(){

	type = "F";

	armor = 1;

	damage = 10000;

	food_cost = 4; 



}





/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/

void Fire::attack(vector<Insect*>(&insects)[10]){

	cout <<"A fire ant on space " <<space+1;

	cout <<" has died all bees on space " << space + 1;

	cout <<"lose all armor " <<endl;


}


/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/




void Fire::move(vector<Insect*> (&insects)[10],int index){


}





/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



	
void Fire::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;

		attack(insects);				//if fire dies it does its attack

	
		remove_from_board(insects[space],index);


	}
}

