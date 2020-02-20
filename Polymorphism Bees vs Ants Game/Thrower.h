
/**********************************
**Flename:Thrower.h
**Author:Brendan Woodrow
**Date:11/25/18
**Description:thrower heder
w**Input:
**Output:
***********************************/
#ifndef THROWER_H
#define THROWER_H

#include "Insect.h"

class Thrower:public Insect{

	public:
		Thrower();
	
		virtual void attack(vector<Insect*> (&insects)[10]);

		virtual void move(vector<Insect*> (&insects)[10],int);



		virtual void be_attacked(int,int,int,vector<Insect*> (&insects)[10]);


};



#endif
