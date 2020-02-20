
/**********************************
**Flename:Bee.cpp
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Bee class cpp file
**Input:
**Output:
***********************************/

#include "Bee.h"



/*******Constructor**********/

Bee::Bee(){

	type = "B";

	armor = 3;

	damage = 1;

	space  = 9;

	food_cost = 0;

	mult_on_space = true;


}





/************************************
**Function:attack
**ddescription:does bees attack
**Paramaters:
**Preconditions:
**Postconditions:
************************************/



void Bee::attack(vector<Insect*> (&insects)[10]){


	int size = insects[space].size();

	if(get_number_of_type("Bd",insects[space]) == 0){		//if there are no bds attack as normal

		for(int i = 0; i < insects[space].size();i++){		//loop and attack everything thats ot a bee

			if(insects[space][i]->get_type() != "B"){

				insects[space][i]->be_attacked(damage,space,i,insects);

				break;

			
			}

		}
	}



	if(get_number_of_type("Bd",insects[space]) != 0){		//if there is a bd only attack it

		for(int i = 0; i < insects[space].size();i++){

			if(insects[space][i]->get_type() == "Bd"){	//attack bd buyt nothing else

				insects[space][i]->be_attacked(damage,space,i,insects);

				break;
			}
		}
	}



}


/************************************
**Function:move
**ddescription:does bees move
**Paramaters:
**Preconditions:
**Postconditions:
************************************/

void Bee::move(vector<Insect*> (&insects)[10],int index){
	


	if(get_number_of_ants(insects[space]) == 0){		//if there are no ants on space move ant forward

		cout <<"Move"<<endl;

		insects[space-1].push_back( insects[space][index] );		//move bee to back of next insect vectos

		insects[space].erase(insects[space].begin() + index);		//remove from current vector

		space--;


		

	}

	else if(get_number_of_type("N",insects[space]) ==		//if there are just ninjas can still move forward but will be attacked by ninja
		get_number_of_ants(insects[space]) ){

				cout <<"Move"<<endl;

				insects[space-1].push_back( insects[space][index] );

				insects[space].erase(insects[space].begin() + index);

				space--;

				be_attacked(1,space,insects[space].size()-1,insects);

			
			}

		
		


	else{			//else do attack

		cout << "Attack"<<endl;

		attack(insects);

	}




}


/************************************
**Function:get_number_of ants
**ddescription:coutns ants on a spacxe
**Paramaters:
**Preconditions:
**Postconditions:
************************************/



int Bee::get_number_of_ants(vector<Insect*> insects){

	int count = 0;

	for(int i = 0; i < insects.size();i++)	
		if(insects[i]->get_type() != "B")	//loop and if type is not a bee increment count
			count++;

	return count;

}



/************************************
**Function:be_attacked
**ddescription:does bee being attacked
**Paramaters:
**Preconditions:
**Postconditions:
************************************/



void Bee::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){



	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;	//DECREASE amor

	if( armor > 0){
		cout<<"		Armor: " <<armor<<endl;
	

	}

	if(armor <= 0){			//if amror is less than zero remove bee from board

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;



		remove_from_board(insects[space],index);
	}
}

