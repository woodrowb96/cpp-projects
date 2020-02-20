#ifndef FIRE_H
#define FIRE_H

/**********************************
**flename:thrower.h
**author:brendan woodrow
**date:11/25/18
**description:thrower heder
w**input:
**output:
***********************************/


#include "Insect.h"


class Fire:public Insect{

	public:
		Fire();


		virtual void attack(vector<Insect*> (&insects)[10]);

		virtual void move(vector<Insect*> (&insects)[10],int);




		virtual void be_attacked(int,int,int,vector<Insect*> (&insects)[10]);



};









#endif
