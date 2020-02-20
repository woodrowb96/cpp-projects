
/**********************************
**Flename:Insect.cpp
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Insect class cpp file
**Input:
**Output:
***********************************/



#include "Insect.h"


/****constructor********/

string Insect::get_type(){

	return type;
}




/*******accesors*****************/
int Insect::get_armor(){

	return armor;
}

int Insect::get_damage(){

	return damage;
}

int Insect::get_index_in_v(){

	return index_in_v;
}

int Insect::get_space(){

	return space;
}

int Insect::get_food_cost(){

	return food_cost;
}

bool Insect::get_mult(){

	return mult_on_space;
}




/**********************MUTATORS********************/


void Insect::set_armor(int a){

	armor = a;
}

void Insect::set_index_in_v(int l){

	index_in_v = l;
}


void Insect::set_space(int  l){

	space = l;
}




//other functions


/************************************
**Function:remove_from_)board
**ddescription:removes insect from board at an index
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/




void Insect::remove_from_board(vector<Insect*>& insects,int index){

	delete insects[index];		//delete memory at that index

	insects[index] = NULL;	//set to NULL

	insects.erase(insects.begin()+index);	//erase index from vector




}


/************************************
**Function:get_number_of_type
**ddescription:gets number of a type at a space
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/




int Insect::get_number_of_type(string t,vector<Insect*> insect){

	int count = 0;

	for(int i =0; i < insect.size();i++){	//loop and countthere is a tyepe ther

		if(insect[i]->get_type() == t)
			count++;

	}	

	return count;

}


