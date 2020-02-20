
/**********************************
**Flename:Thrower.cpp
**Author:Brendan Woodrow
**Date:11/25/18
**Description:thrower cpp
w**Input:
**Output:
***********************************/





#include "Thrower.h"


Thrower::Thrower(){

	type = "T";

	armor = 1;

	damage = 1;

	food_cost = 4; 



}


/************************************
**Function:attack
**ddescriptiondoes attack for thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/




void Thrower::attack(vector<Insect*> (&insects)[10]){

	if(get_number_of_type("B",insects[space]) != 0){

		cout <<"Thrower on space " << space+1<<" throws leaf at bee on ";

		cout <<"space " <<space+1 <<endl;

		for(int i = 0; i < insects[space].size();i++){	//loops and atacks firt bee on a space

			if(insects[space][i]->get_type() == "B"){

				insects[space][i]->be_attacked(damage,space,i,insects);		//attack the bee
				break;								//break after firt attack to only attack one bee
			}
		}
	}

}


/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



void Thrower::move(vector<Insect*> (&insects)[10],int i){
		
	
	attack(insects);		//thrower does its attack on its move

}



/************************************
**Function:be_attacked
**ddescription:does 
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



void Thrower::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){	//same as is attacked in bee class

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}


