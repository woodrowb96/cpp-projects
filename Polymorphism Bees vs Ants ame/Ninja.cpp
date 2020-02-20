


/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/




#include "Ninja.h"


Ninja::Ninja(){

	type = "N";

	armor = 1;

	damage = 1;

	food_cost = 6; 



}




void Ninja::attack(vector<Insect*> (&insects)[10]){	//ninja attack is done within bee class move function


	//bee move function just call be attacked with 1 damage when it is on space with ninnja and moves
}

void Ninja::move(vector<Insect*> (&insects)[10],int index){

	

}





/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



void Ninja::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){		//same as bee be_attacked

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}

