//#define FAST
#include <time.h>  
#include "functions.hpp"
#include "primitives.hpp"
#include "ackermann.hpp"
#include <vector>
#include <iostream>

using namespace std;

// Number defined in functions.hpp

int main(int argc, const char *argv[])
{
	srand (time(NULL));
	// Tests
	for(int i = 0; i < 4; ++i){
		vector<Number> args = {rand() % 100, rand() % 100};
		cout << args[0] << " + " << args[1] << " = " << add(args) << endl; 
	}	
	for(int i = 0; i < 4; ++i){
		vector<Number> args = {rand() % 100, rand() % 100};
		cout << args[0] << " - " << args[1] << " = " << substract(args) << endl; 
	}
	for(int i = 0; i < 4; ++i){
		vector<Number> args = {rand() % 30, rand() % 30 + 1};
		cout << args[0] << " / " << args[1] << " = " << divide(args) << endl; 
	}
	for(int i = 0; i < 4; ++i){
		vector<Number> args = {rand() % 30, rand() % 30 + 1};
		cout << args[0] << " % " << args[1] << " = " << mod(args) << endl; 
	}
	for(int i = 0; i < 4; ++i){
		vector<Number> args = {rand() % 30};
		cout << "is_prime(" << args[0] << ") = " << is_prime(args) << endl; 
	}	
	for(int i = 0; i < 7; ++i){
		vector<Number> args = {i};
		cout << "nth_prime(" << args[0] << ") = " << nth_prime(args) << endl; 
	}
	for(int i = 0; i < 9; ++i){
		vector<Number> args = {2, i};
		cout << "plog(" << args[0] << ", " << args[1] << ") = " << plog(args) << endl; 
	}
#ifdef FAST
	vector<vector<Number> > ackermann_tests = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2,1}, {1,2}, {2,2}, {3,0}, {0, 3}, {1, 3}, {2,3}};
	for(int i = 0; i < ackermann_tests.size(); ++i){
		cout << "Ackermann(" << ackermann_tests[i][0] << ", " << ackermann_tests[i][1] << ") = " << ackermann(ackermann_tests[i]) << endl;
	}
#endif
	return 0;
}
