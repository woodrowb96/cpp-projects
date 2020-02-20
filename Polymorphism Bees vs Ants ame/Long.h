
/**********************************
**flename:Long.cpp
**author:brendan woodrow
**date:11/25/18
**description:header file
w**input:
**output:
***********************************/





#ifndef LONG_H
#define LONG_H


#include "Insect.h"

class Long:public Insect{

	public:
		Long();

	
		virtual void attack(vector<Insect*> (&insects)[10]);

		virtual void move(vector<Insect*> (&insects)[10],int);



		virtual void be_attacked(int,int,int,vector<Insect*> (&insects)[10]);


};





#endif
