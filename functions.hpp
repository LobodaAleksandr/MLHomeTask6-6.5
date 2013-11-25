#ifndef FUNCTIONS_DMJZRKNG

#define FUNCTIONS_DMJZRKNG

#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
#include "bigint/BigIntegerLibrary.hh"

typedef BigInteger Number;

typedef Number (*Function)(std::vector<Number>&);
class IllegalArgumentsNumber {
public:
	IllegalArgumentsNumber (std::string cause) :cause(cause)
	{}
	std::string get_cause(){
		return cause;
	}
	virtual ~IllegalArgumentsNumber (){}

private:
	std::string cause;
};

template<Function f, Function... gs>
Number S(std::vector<Number>& args){
		const int arg_size = args.size();
		const int size = sizeof...(gs);
		Function functions[size] = {gs...};
		std::vector<Number> sub;
		for(int i = 0; i < size; ++i){
			sub.push_back(functions[i](args));
		}
		return f(sub);
}

Number Z(std::vector<Number>& args){
	const int arg_size = args.size();
	if(args.size() != 1){
		throw(IllegalArgumentsNumber("Z must take argument")); 
	}	
	return 0;
}

Number N(std::vector<Number>& args){
	const int arg_size = args.size();
	if(args.size() != 1){
		throw(IllegalArgumentsNumber("N must take 1 argument"));
	}
	return args[0] + 1;
}

template<int n, int i>
Number U(std::vector<Number>& args){
	const int arg_size = args.size();
	if(args.size() != n || i > n){
		std::string info = "(args given: ";
		char args_size[100];
		char template_n[100];
		char template_i[100];
		sprintf(args_size, "%u", (unsigned)args.size());
		sprintf(template_n, "%d", n);
		sprintf(template_i, "%d", i);
		info += args_size;
		info += ", i:  ";
		info += template_i;
		info += ", n: ";
		info += template_n;
		info += ")";
		throw(IllegalArgumentsNumber("U function take bad args" + info));
	}
	return args[i - 1];
}

template<Function f, Function g>
Number R(std::vector<Number>& args){
	const int arg_size = args.size();
	if(args.size() == 0){
		throw(IllegalArgumentsNumber("R function take 0 args"));
	}	
	Number y = 0;
	Number count = args[args.size() - 1];
	args.pop_back();
	Number res = f(args);
	args.push_back(0);
	args.push_back(res);
	for(Number i = 0; i < count; i++){
		res = g(args);
		args[args.size() - 2]++;
		args[args.size() - 1] = res;
	}
	args.pop_back();
	args.pop_back();
	args.push_back(count);
	return res;
}

template<Function f>
Number M(std::vector<Number>& args){
	const int arg_size = args.size();
	Number i = 0;
	args.push_back(0);
	while(true){
		if(f(args) == 0){
			args.pop_back();
			return i;
		}
		++i;
		args[args.size() - 1]++;
	}
}
#endif /* end of include guard: FUNCTIONS_DMJZRKNG */
