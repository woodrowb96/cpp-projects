
/**********************************
**flename:fire.cpp
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/




#ifndef SHORT_H
#define SHORT_H



#include "Insect.h"

class Short:public Insect{

	public:
		Short();
	
		virtual void attack(vector<Insect*> (&insects)[10]);

		virtual void move(vector<Insect*> (&insects)[10],int);

		virtual void be_attacked(int,int,int,vector<Insect*> (&insects)[10]);




};




#endif

