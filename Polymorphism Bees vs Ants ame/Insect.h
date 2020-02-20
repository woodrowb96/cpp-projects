

/**********************************
**Flename:Insect.h
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Insect header file
**Input:
**Output:
***********************************/


#ifndef INSECT_H
#define INSECT_H


#include <string>
#include <vector>
#include "helper_functions.h"

using namespace std;
class Insect{

	protected:
		string type;
		int armor;
		int damage;
		int index_in_v;
		int space;
		int food_cost;
		bool mult_on_space;

		vector<Insect*>::iterator itr;


	public:

		//accesor
		string get_type();	
		int get_armor();
		int get_damage();
		int get_index_in_v();
		int get_space();
		int get_food_cost();
		bool get_mult();

		//mutators
		void set_armor(int);
		void set_space(int);
		void set_index_in_v(int);


		/*****Vitural functiosn*********/
	

		virtual void attack(vector<Insect*> (&insects)[10]) = 0; 

		virtual void move(vector<Insect*> (&insects)[10],int) = 0;

		virtual void  be_attacked(int,int,int,vector<Insect*> (&insects)[10]) = 0;


		/***************************/



		void remove_from_board(vector<Insect*>&);

		void remove_from_board(vector<Insect*>&,int);

		int get_number_of_type(string,vector<Insect*>);

	

};
#endif
