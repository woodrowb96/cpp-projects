
/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/

#include "Wall.h"


Wall::Wall(){

	type = "W";

	armor = 4;

	damage = 0;

	food_cost = 4; 



}

void Wall::attack(vector<Insect*> (&insects)[10]){		//wall hgas no move or attack

}

void Wall::move(vector<Insect*> (&insects) [10],int index){


}





/************************************
**Function:set_up_property
**ddescription:thrower
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/





//smae as bee be_attacked 

void Wall::be_attacked(int dam,int space,int index,vector<Insect*> (&insects)[10]){


	cout <<type<<" on space " <<space+1<<" was attacked"<<endl;

	armor = armor - dam;

	if( armor > 0)
		cout<<"		Armor: " <<armor<<endl;

	if(armor <= 0){

		cout <<"	"<<type <<" had 0 armor left and has died"<<endl;


		remove_from_board(insects[space],index);


	}
}

