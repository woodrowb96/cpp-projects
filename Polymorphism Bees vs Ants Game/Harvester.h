
/**********************************
**Flename:Harvester.h
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Insect header
**Input:
**Output:
***********************************/





#ifndef HARVESTER_H
#define HARVESTER_H

#include "Insect.h"

class Harvester:public Insect{

	public:
		Harvester();

		virtual void attack(vector<Insect*> (&insects)[10]);

		virtual void move(vector<Insect*> (&insects)[10],int);

		virtual void be_attacked(int,int,int,vector<Insect*> (&insects)[10]);



};

#endif
