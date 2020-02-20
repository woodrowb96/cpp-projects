

/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/







#include "Short.h"


Short::Short(){

	type = "S";

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



void Short::attack(vector<Insect*> (&insects)[10]){

	for(int i = space; i < space + 2;i++){			//loop and attack first space up to two away

		if(get_number_of_type("B",insects[i]) != 0){

			cout <<"Thrower on space "<<space+1<<" throws leaf at bee's on ";

			cout <<"space " <<i+1<<endl;

			for(int k = 0; k < insects[i].size();k++){
	
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


void Short::move(vector<Insect*> (&insects)[10],int i){
	
	attack(insects);
	

}


/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Short::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){//same as bee be_attacked

	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}

