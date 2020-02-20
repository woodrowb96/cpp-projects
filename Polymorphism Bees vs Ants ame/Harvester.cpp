
/**********************************
**Flename:Harvester.cpp
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Harvester class cpp file
**Input:
**Output:
***********************************/



#include "Harvester.h"





Harvester::Harvester(){

	type = "H";

	armor = 1;

	damage = 0;

	food_cost = 2; 



}

/***************HARvester doesnt attack or move just harvests more food at end of turn, this is done in function in GAme class*******/

void Harvester::attack(vector<Insect*> (&insects)[10]){

}

void Harvester::move(vector<Insect*> (&insects)[10],int i){

	

}


/************************************
**Function:be_attacked
**ddescription:does attacking
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Harvester::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){ 	///same as be_attacked in Bee class

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}

