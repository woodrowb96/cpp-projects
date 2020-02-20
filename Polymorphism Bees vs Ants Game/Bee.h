

/**********************************
**Flename:Bee.h
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Bee class header
**Input:
**Output:
***********************************/




#ifndef BEE_H
#define BEE_H

#include "Insect.h"

class Bee:public Insect{

	public:
		Bee();

		virtual void attack(vector<Insect*> (&insects)[10]);

		virtual void move(vector<Insect*> (&insects)[10],int);

		virtual void be_attacked(int,int,int,vector<Insect*> (&insects)[10]);

		int get_number_of_ants(vector<Insect*>);


	

};

#endif
