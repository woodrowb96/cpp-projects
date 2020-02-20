

/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/




#include "Bodyguard.h"


Bodyguard::Bodyguard(){

	type = "Bd";

	armor = 2;

	damage = 0;

	food_cost = 4; 



}


//bodyguard has no attack or move

void Bodyguard::attack(vector<Insect*> (&insects)[10]){

}

void Bodyguard::move(vector<Insect*> (&insects)[10],int index){


}


/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/





void Bodyguard::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){		//same as bee be_attacked

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}

