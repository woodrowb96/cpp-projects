
/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/



#include "Long.h"


Long::Long(){

	type = "L";

	armor = 1;

	damage = 1;

	food_cost = 3; 



}







/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



void Long::attack(vector<Insect*> (&insects)[10]){		

	for(int i = space+4; i < 10;i++){

		if(get_number_of_type("B",insects[i]) != 0){  	///LOOP AND ATTACK FIRST space with bees 

			cout <<"Thrower on space "<<space+1<<" throws leaf at bee's on ";

			cout <<"space " <<i+1<<endl;

			for(int k = 0; k < insects[i].size();k++){		//attack all bees on space
	
				if(insects[i][k]->get_type() == "B"){

					insects[i][k]->be_attacked(damage,i,k,insects);
				}
			}

			break;
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




void Long::move(vector<Insect*> (&insects)[10],int i){

	if(space <= 6){

		attack(insects);
	}

}




/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/





void Long::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){		//same as bee be_attacled

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}

