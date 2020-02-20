
/**********************************
**Flename:Game.cpp
**Author:Brendan Woodrow
**Date:11/25/18
**Description:Game class cpp file
**Input:
**Output:
***********************************/



#include "Game.h"

//constructor


Game::Game(){

	food = 50;	//just need to set up food at start	

}



/**************Other Functions***************************/





/************************************
**Function:print_board()
**ddescription:prints game board
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/




void Game::print_board(){

	cout<<"_________________________________";
		
	cout <<"_________________________________________________"<<endl;

	
	
	for(int i = 0; i < 10; i++){	//loop and cout space numbers 		

		cout <<"|   " <<i+1 <<"   ";

	
	}

	cout <<"|"<<endl;


	for(int k = 0; k < max_vector_size()+1;k++){ 	//loop enough to output all insects in largest vecotr

		print_board_2(k);

		
	
	}



	cout<<"_____________________________________";
	cout<<"_____________________________________________"<<endl<<endl<<endl;


}




/************************************
**Function:print_board_2()
**ddescription:prints game board
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



void Game::print_board_2(int k){

	for(int i = 0; i < 10; i++){	//loop through each cpase

			if(k == 0 && i == 0){		//if your at 0 or 9 place queen anmd hive
				cout <<"|   Q   ";
			}

			else if(k == 0 &&i == 9){
				cout <<"|   Hv  ";
			}

			else if(insects[i].size() >= k){	//if there are still insects to be printed

				cout <<"|   ";

				if( i == 0 || i == 9){			//if your at 9 or 10 output one less because of q and HV

					cout << insects[i][k-1]->get_type()<<"   "; 

				}
				else if(insects[i].size() != k){		//if Bd adjuyst amount of space to cout since it 1 letter longer
					if(insects[i][k]->get_type() == "Bd")
						cout <<insects[i][k]->get_type()<<"  ";

					else
						cout <<insects[i][k]->get_type()<<"   ";		//else just cout type
				}

				else
					cout <<"    ";

			}
			else{
				cout <<"|       ";
			}
		}

		cout <<" |"<<endl;	

}




/************************************
**Function:continue_and_cleare()
**ddescription:prints game board
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Game::continue_and_clear(){    //prompts user for  to continue then clears screen

	string  ans;

	cout <<"Enter 1 to continue: ";
	cin >>ans;

	while(ans != "1"){

		cout <<"Enter a valid input(1): ";

		cin >>ans;

	}
	cout <<string(100,'\n');		//100 new line chare to clear screen 
	



}


/************************************
**Function:play_game()
**ddescription:prints game board
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Game::play_game(){

	bool play;	//play checks if you want to keep playing

	int turn = 1;

	do{
		cout <<string(100,'\n');		//clear screen	

		cout <<"Turn " << turn<<": " <<endl<<endl;
		
		play = do_turn();	//do one turn	

		turn++;

	}while(play);

}




/************************************
**Function:print_board()
**ddescription:does each step in a turn
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


bool Game::do_turn(){

	print_board();

	continue_and_clear();

	generate_bee();

	generate_ant();

	do_ant_moves();

	do_bee_moves();

	harvest();

	if(check_winner()){		//check if there is a winner

		return false;	//if there is leave game
	}

	return keep_playing();	//get user inout if they want to keep playing

}





/************************************
**Function:check_winner()
**ddescription:checks to see if someone has won the game
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


bool Game::check_winner(){


	/*****check if bees have reached hive*******/

	for(int i = 0; i < insects[0].size();i++){

		if(insects[0][i]->get_type() == "B"){	//if there is a bee at queen the game is over

			print_board();

			cout <<"Bees have reached the queen, you have lost"<<endl;

			cout <<endl << "GAME OVER"<<endl<<endl;

			return true;
		}
	}


	/*****coutn how many bees are left on board**********/


	int count =0;		//count total num bees

	for(int i =0; i < 10;i++){

		count = count + get_number_of_bees(i);	//add up all bees



	}

	if(count == 0){		//if no bees are on board youve won

		cout <<"There are no Bees on the board"<<endl;

		cout<<endl<<endl <<"YOU HAVE WON"<<endl<<endl;

		return true;
	}

	return false;		//if none of the above is true keep playing
}




/************************************
**Function:get_number_of_bees()
**ddescription:coutn bees on spoace
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/



int Game::get_number_of_bees(int space){

	int count = 0;

	for(int i =0; i < insects[space].size();i++){		//loop through and add to count if there is a bee at spot

		if(insects[space][i]->get_type() == "B")
			count++;
	}

	return count;
}






/************************************
**Function:Harvest()
**ddescription:harvests food from harvesters
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/

void Game::harvest(){

	for(int i = 0; i < 10;i++){  //lop through each space

		for(int k = 0; k < insects[i].size();k++){	//loop through all nsects

			if(insects[i][k]->get_type() == "H"){	//if insect is a harv gather food

				cout << "Harvester on space " << i+1;

				cout <<" gathers 1 food"<<endl;

				food++;					//incease food

				cout << "Food bank: " <<food<<endl;
			}
		}
	}
}




/************************************
**Function:do_ant_move()
**ddescription:prints game board
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Game::do_ant_moves(){


	cout <<"Ant actions "<<endl<<endl;

	print_board();

	for(int i = 0; i < 10;i++){			//loop throughb all apaces

		for(int k = 0; k < insects[i].size();k++){	//loop throug all insects

			if(insects[i][k]->get_type() != "B"){		//if there is not a  bee do its move

				insects[i][k]->move(insects,i);

				print_board();
			}
		}
	}

	continue_and_clear();

}


int Game::check_for_fire(vector<Insect*>& in){

	int index = 10000000;

	for(int i = 0; i < in.size();i++){


		if(in[i]->get_type() == "F"){

			index = i;
			break;
		}
	}

	return index;

}


void Game::do_fire_turn(vector<Insect*>(&insects)[10],int space){

	int size = insects[space].size();

	for(int i = 0; i < insects[space].size();){

		if(insects[space][i]->get_type() == "B"){

			insects[space][i]->be_attacked(100,space,i,insects);
		}

		else
			i++;

	}

}


bool Game::check_for_bd(vector<Insect*>& insects){

	for(int i = 0; i < insects.size();i++){

		if(insects[i]->get_type() == "Bd")
			return true;
	}

	return false;

}
/************************************
**Function:do_bee_move)
**ddescription:does moves for bees
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Game::do_bee_moves(){

	cout <<"Bee actions " <<endl <<endl;

	print_board();

	for(int i = 0; i <10;i++){		//loop through spaces

		int size = insects[i].size();		//size at start opf loop

		int f_i = check_for_fire(insects[i]);

		for(int k = 0; k < insects[i].size();){		//loop through insects

			if(insects[i][k]->get_type() == "B" && i != 0){		//if its not bee do move

				insects[i][k]->move(insects,k);			//do move,if an ant is killed and remove it will change array size
										//that may cause us to skip some beesin the array,
					
				if(i > f_i /*&& !check_for_bd(insects[i])*/){


					do_fire_turn(insects,i);

					print_board();

					break;
				}

				print_board();
			}

			if(size == insects[i].size()){		//if the size of vector was not changed increae k
								//if it had been changed k would not have increased and we 
								//could have done one more loop to get lost bee
				k++;

			}

			size = insects[i].size();		//make sure curernt size is equal to siz eof array

		}

	}	

	continue_and_clear();

}



/************************************
**Function:generate_bee()
**ddescription:generates a \bee into arra
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/






void Game::generate_bee(){

	cout <<"Generate New Bee" << endl;

	if(insects[9].size() == 0){	//check if there are already bees on spot
		
		insects[9].push_back(new Bee);		//add new bee at back of vector on space 10

		insects[9][0]->set_index_in_v(0);



	}

	print_board();

	continue_and_clear();

}



/************************************
**Function:generate_ant()
**ddescriptiongenerates ant from user
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/





void Game::generate_ant(){

	string answer,space;

	print_board();
	
	do{				//do until valid answer

	cout <<"Food Bank: " << food<<endl;

	cout <<"Enter type of ant to generate: "<<endl<<endl;

	cout <<"Harvester (H), Thrower (T), Fire (F), Long Thrower (L)"<<endl;

	cout <<"cost 2         cost 4       cost 4    cost 3"<<endl<<endl;

	cout <<"Short Thrower (S), Wall (W), Ninja (N), Bodyguard (Bd)"<<endl;

	cout <<"cost 3             cost 4    cost 6     cost 4"<<endl <<endl;

	cout <<"or enter 0 to add no ants: "<<endl;

	cin >> answer;

	}while(check_ant_answer(answer));		//check answer

	if(answer != "0"){   	//if answer was 0 we dont add ant to vector


		do{			//do until valuid space

			cout <<"Enter space (2-9) to place ant: ";

			cin >> space;


		}while(check_space(space,answer));	//check space

		int s = get_int(space);

		add_ant(s-1,answer);		//add ant at index s-1

	}

	continue_and_clear();

	

}


/************************************
**Function:add_ant()
**ddescription:adds ant at space in bodrds
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


void Game::add_ant(int space,string type){


	insects[space].push_back(get_ant_of_type(type));	//push back ins of type to back of vector at space

	int size = insects[space].size();		//size used to set space

	insects[space][size-1]->set_space(space);	//set the insects space at its index to spaxe

	food = food - insects[space][size-1]->get_food_cost();		//remove food cost

	cout <<endl << "Food Bank: "  <<food<<endl;

	print_board();

}



/************************************
**Function:check_space()
**ddescription:checks answer for spae
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/





bool Game::check_space( string space,string type){

	if(!is_int(space)){			//check if answer wads an int

		cout <<"Enter a number "<<endl;
		return true;

	}


	int s = get_int(space);		//get int of answer
	
	if(! (s < 10 && s > 1)){		//spasce should be between 2 and 9

			cout <<"Enter a space between 2 and 9"<<endl;

			return true;
	}

	if(check_mult_ants(s-1,type)){		//check if tehre are alreade ants oin the soace

			return true;

	}

	return false;
}






/************************************
**Function:check_mult_ants()
**ddescription:checks waht ants are on a space
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/

bool Game::check_mult_ants(int space,string type){

	if(type == "Bd"){  		//if your adding a Bodyguard 

		if(get_total_num_ants(space,0) <= 1){	//you can add it to a spot with more whan one ant

			if(get_num_of_type(space,"Bd") == 0){	//can only have 1 bd on a space

				return false;

			}


		}

	}

	if(type != "Bd"){		//if its not a bd can only have 1 on space

		if(get_total_num_ants(space,0) == 0){		//if there are no ants not coiunting bd

			if(get_num_of_type(space,"Bd") <= 1){	//if there are only 1 bd

					return false;
			}
		}
	}

	cout <<"There are already Ants on this space enter a valid space ";

	return true;


}




/************************************
**Function:get_num_of_tyep()
**ddescription:counts total num of type on a space
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/

int Game::get_num_of_type(int space,string type){

	int count = 0;

	for(int i = 0; i < insects[space].size();i++){		//loop and count up tyep

		if(insects[space][i]->get_type() == type)
			count++;

	}

	return count;

}


/************************************
**Function:print_board()
**ddescription:gets total number of ant on a space
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/




int Game::get_total_num_ants(int space,int w_b){

	int count =0;

	if(w_b == 0){			//if w_b is 0, dont count Bodyguard ants 

		for(int i = 0; i < insects[space].size();i++)
			if(insects[space][i]->get_type() != "B")
				if(insects[space][i]->get_type() != "Bd")  //if its not a Bd or b increase count
					count++;
	}

	if(w_b == 1){			//if w_b is 1 count bodyuguiards

		for(int i = 0; i < insects[space].size();i++)
			if(insects[space][i]->get_type() != "B")
				count++;
	}

	return count;

	

}


/************************************
**Function:check_)ant-answer()
**ddescription:checks user an anserw
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


bool  Game::check_ant_answer(string a){

	Insect* i;

	if(a == "0")		//0 is a valid input
		return false;

	if(a != "H" && a !=  "T" && a!= "F" && a!= "L" && a!=  "S" && a!=  "W" && a!= "N" &&  a!= "Bd"){	//if its not one ofg these

		cout <<endl<<"Enter a volid ant type "<<endl;

		return true;
	}

	i = get_ant_of_type(a);	//get the type they want


	if(food - i->get_food_cost() < 0){		//check if there is enough food

		delete i;
		return true;
	}

	else{
		delete i;		//if there is ffod its a good answer
		return false;

	}



}




/************************************
**Function:get_ant_of_type()
**ddescription:pgets ant of string tyepd
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/


Insect* Game::get_ant_of_type(string a){

	if(a == "H")
		return new Harvester;
	if(a == "T")
		return new Thrower;
	if(a == "F")
		return new Fire;
	if(a == "L")
		return new Long;
	if(a == "S")
		return new Short;
	if(a == "W")
		return new Wall;
	if(a == "N")
		return new Ninja;
	if(a == "Bd")
		return new Bodyguard;



}



/************************************
**Function:keep_playing()
**ddescription:asks if user wants to keep playing
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/

bool Game::keep_playing(){

	bool answer;

	string an;

	do{		//do until anwerr is valid

		cout <<"Would you like to keep playing enter 1(YES) 0(NO)";

		cin >> an;

	}while(! (an == "1" || an == "0"));	//answer shiuodn only be 1 or 0

	return get_int(an);

}




/************************************
**Function:max_vector_soze()
**ddescription:prints game board
**Paramaters:none
**Preconditions:
**Postconditions:
************************************/

int Game::max_vector_size(){

	int max = 0;	//max starts at 0


	for(int i = 0; i < 10;i++){	//loop through all vectors in aray

		if(insects[i].size() >= max){	//if the size of v is larer than max
			max = insects[i].size();	//replace max 

		}
	}


		return max;
}



//destructor

Game::~Game(){

	for(int i = 0; i < 10;i++){	//loop through each index vector in array

		for(itr = insects[i].begin(); itr != insects[i].end();itr++){  //loop through all insects stored in vector 

			if(insects[i].size() != 0){

				delete *itr;

				*itr = NULL;
			}	
		}
	}

}

