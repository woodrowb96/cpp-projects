#ifndef GAME_H
#define GAME_H


/**********************************
**Flename:Game.h
**Author:Brendan Woodrow
**Date:11/25/18
**Description:header file for game class
**Input:
**Output:
***********************************/
#include <iostream>
#include <vector>
#include "Insect.h"
#include "Bee.h"
#include "Harvester.h"
#include "Thrower.h"
#include "Fire.h"
#include "Long.h"
#include "Short.h"
#include "Wall.h"
#include "Ninja.h"
#include "Bodyguard.h"
#include "helper_functions.h"

using namespace std;

class Game{

	private:
		int food;

		vector<Insect*> insects[10];

		vector<Insect*>::iterator itr;
		

	public:
		//constructor
		Game();


		//other functions
		void print_board();

		void print_board_2(int);

		void continue_and_clear();

		void play_game();

		bool do_turn();

		int check_for_fire(vector<Insect*>&);

		bool check_for_bd(vector<Insect*>&);

		void do_fire_turn(vector<Insect*> (&insects)[10],int);

		void do_bee_moves();

		void do_ant_moves();

		void harvest();

		bool keep_playing();

		int max_vector_size();

		void generate_bee();

		void generate_ant();

		bool check_winner();

		int get_number_of_bees(int);

		void add_ant(int,string);

		bool check_ant_answer(string);

		bool check_space(string,string);

		bool check_mult_ants(int,string);

		int get_num_of_type(int,string);

		int get_total_num_ants(int,int);

		Insect* get_ant_of_type(string);

	

		//destructor
		~Game();

};

#endif
