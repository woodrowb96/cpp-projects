#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H



/***************************************
**Program filename: helper_functions.h
**Author: Brendan Woodrow
**Date: 2/9/2018
** Description: headers for helper_functions.cpp
** input: none
** output: none
*********************************/








#include<string>

#include<cmath>

#include <iostream>


using namespace std;

bool check_range(int lower_bound, int upper_bound, int test_value);

bool is_int(string num);


bool numbers_present(string sentance);

bool letters_present(string sentance);

int word_count(string sentance);


int get_int(string);

#endif


