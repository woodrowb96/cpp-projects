/**********************************************************************
 ** Program Filename: helper_functions.cpp
 ** Author: Brendan Woodrow
 ** Date: 2/1/2018
 ** Description: These are the functions for assignment 3
 ** Input: strings, integers, floats for different funtions 
 ** outputes : booleans, string, ints for different functions
 ***************************************************************/

#include "helper_functions.h"

/***********************************************************
 ** Function: check_range
 ** Description: returns bool true if test value is between upper and lower value false if not
 ** Parameters: int lower_bound, upper_bound, test_value
 ** Pre-conditions: inputs should be int
 ** post-conditions: funtion returns bool 
*********************************************************/
 

bool check_range (int lower_bound,int  upper_bound,int  test_value){

	bool result;

	if( lower_bound < test_value &&  test_value < upper_bound){

		result = true;

	}

	else{

		result = false;

	}

	return result;

};




/***********************************************************
 ** Function: is_int 
 ** Description: returns true if string is int, false if not 
 ** Parameters:string num
 ** Pre-conditions: inputs should be string
 ** post-conditions: funtion returns boolean
*********************************************************/



bool is_int(string num){

	bool result;

	for(int i = 0; i < num.length(); i++){                 /* If bellow checks if char is number*/

		if(num[i] > 47 && num[i] < 58){

			result = 1;

		} else if( i == 0 && num[i] == 45 && (num[i+1] < 58 && num[i+1] > 47)){   /* if char is 1st it can be - char only if followed by number*/

			result = 1;
		}

		
		else {

			result = 0;

			break;

		}


	}


	return result;

}




/***********************************************************
 ** Function: number_present 
 ** Description: returns true if string has numbers in it false if not
 ** Parameters:string sentance
 ** Pre-conditions: inputs should be string
 ** post-conditions: bool
*********************************************************/


bool numbers_present(string sentance){

	bool result;

	for(int i = 0; i < sentance.length(); i++){

		if( sentance[i] < 58 && sentance[i] > 47){

			result = true;

			break;

		} else {

			result = false;

		}	

	}

	return result;

}





/***********************************************************
 ** Function: letters_present 
 ** Description: returns true if string has letters in it false if not
 ** Parameters:string sentance
 ** Pre-conditions: inputs should be string
 ** post-conditions: bool
*********************************************************/




bool letters_present(string sentance){

	bool result;

	for(int i = 0; i < sentance.length(); i++){

		if(( sentance[i] < 91 && sentance[i] > 64) ||(sentance[i] < 123 && sentance[i] > 96) ){

			result = true;

			break;

		} else {

			result = false;

		}	

	}

	return result;

}

/***********************************************************
 ** Function: word_count  
 ** Description: provides number of words in string
 ** Parameters: string sentance
 ** Pre-conditions: inputs should be string
 ** post-conditions: int
*********************************************************/



int word_count(string sentance){

	int result = 0;

	for( int i = 0; i < sentance.length(); i++){


		if( i == 0 && (sentance[i] != 32)){ /* if char is first and not a space its a word*/

			result ++;

		}

		if( sentance[i] == 32 && (sentance[i+1] != 32) && (sentance[i+1] != 0)){ /* if there is a space thats not followed by another space or by null  its a word*/

			result ++;

		} 

	}

	return result;

}




/***********************************************************
 ** Function: get_int 
 ** Description: checks if string from user is integer, if true returns string as int
 ** Parameters: string prompt
 ** Pre-conditions: inputs should be string
 ** post-conditions: int
*********************************************************/

int get_int(string prompt){

	int result = 0;

	bool check;

	do{    /* do while to check if what was entered was integer, and reprompt if not */

		if( is_int(prompt) == 1 ){ /*if it is int convert*/

			if(prompt[0] == 45){ /*if the string begins with a - creat in starting at i = 1, then flip sign at end*/

				
				int power = prompt.length() - 2; /*first position should be multiplied by 10^length - 2 since first position is -*/

				for( int i = 1; i < prompt.length(); i ++){

					result = result +(( prompt[i] - 48) * pow(10 , power ));

					power --;

				}

				result = -result; /*flip result sign*/	


			}

			else if(prompt[0] != 45){ /*dont need to worry about fliping sign if there is no -*/

			int power = prompt.length() - 1; /*power to raise each char too*/

			for( int i = 0; i < prompt.length(); i ++){

				result = result +(( prompt[i] - 48) * pow(10 , power ));

				power --;

			}
			}

			check = true;
		
		}

			


	} while ( check == false);

	return result;



}




	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


