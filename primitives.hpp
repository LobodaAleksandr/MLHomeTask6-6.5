#ifndef PRIMITIVES_PVUVQCJY

#define PRIMITIVES_PVUVQCJY
#include "functions.hpp"
#ifdef FAST
Number divide(std::vector<Number>& args){
	return args[0] / args[1];
}

Number add(std::vector<Number>& args){
	return args[0] + args[1];
}

Number substract(std::vector<Number>& args){
	if(args[0] < args[1]){
		return 0;
	}
	return args[0] - args[1];
}

Number multiplicate(std::vector<Number>& args){
	return args[0] * args[1];
}

Number mod(std::vector<Number>& args){
	return args[0] % args[1];
}

Number pow(std::vector<Number>& args){
	Number res = 1;
	Number a = args[0];
	Number b = args[1];
	for(Number i = 0; i < b; ++i){
		res *= a;
	}
	return res;
}

Number plog(std::vector<Number>& args){
	Number x = args[1];
	Number p = args[0];
	Number i = 0;
	Number res = 0;
	Number tmp = p;
	while(true){
		++i;
		if(tmp > x){
			return res;
		}	
		if(x % tmp == 0){
			res = i;
		}
		tmp *= p;
	}
}

#endif
constexpr Function decrement = S<R<Z, U<3,2>>, U<1,1>, U<1,1>>;
#ifndef FAST
constexpr Function add = R<U<1,1>,S<N, U<3,3>>>; // Needed to do
constexpr Function substract = R<U<1,1>, S<decrement, U<3, 3>>>; //Needed to do
constexpr Function multiplicate = R<Z, S<add, U<3,1>, U<3,3>>>; 
#endif
constexpr Function is_zero = S<R<S<N,Z>,S<Z, U<3,2>>>, U<1,1>, U<1,1>>;
constexpr Function is_not_zero = S<substract, S<N,Z>, is_zero>;
constexpr Function less_or_equals = S<is_zero, substract>;
constexpr Function more = S<substract, S<N, S<Z, U<2,1>>>, less_or_equals>;
constexpr Function min = S<R<U<2,2>, U<4,1>>, U<2,1>, U<2,2>, less_or_equals>;
constexpr Function max = S<substract, add, min>;
constexpr Function first_not_zero_arg = S<R<U<2, 1>, U<4, 2>>, U<2,1>, U<2,2>, S<is_zero, U<2,1>>>;
#ifndef FAST
constexpr Function divide = S<substract, S<R<S<Z, U<2, 1>>, S<first_not_zero_arg, U<4,4>, S<R<S<Z, U<1,1>>, U<3,1>>, U<4,3>,S<more, S<multiplicate, U<4,1>, U<4,3>>, U<4,2>>>>>, U<2,2>, add, add>, S<N, S<N, S<Z, U<2,1>>>>>; // Needed to do
constexpr Function mod = S<substract, U<2,1>, S<multiplicate, U<2,2>, divide>>; // Needed to do
#endif
constexpr Function two = S<N, S<N, Z>>;
constexpr Function part_for_prime = S<R<Z, S<first_not_zero_arg, U<3,3>, S<is_zero, S<mod, U<3,1>, S<add, U<3,2>, S<two, U<3,1>>>>>>>, U<1,1>, S<substract, U<1,1>, two>>;
constexpr Function is_prime = S<R<S<substract, S<N, Z>, part_for_prime>, S<Z, U<3,1>>>, U<1,1>, S<less_or_equals, U<1,1>, S<N, Z>>>; // Needed to do
constexpr Function count_of_prime_numbers = S<R<Z, S<add, U<3,3>, S<is_prime, U<3,2>>>>, U<1,1>, S<N,U<1,1>>>; 
constexpr Function nth_prime = M<S<substract, S<N, U<2,1>>, S<count_of_prime_numbers, U<2,2>>>>; // Needed to do
#ifndef FAST
constexpr Function pow = R<S<N,Z>, S<multiplicate, U<3,1>, U<3,3>>>;	
constexpr Function plog = S<R<S<Z,U<2,1>>, S<max, U<4,4>, S<R<S<Z, U<1,1>>, U<3,1>>, U<4,3>, S<is_zero, S<mod, U<4,2>, S<pow, U<4,1>, U<4,3>>>>>>>, U<2,1>, U<2,2>, U<2,2>>; // Needed to do
#endif /* fast realisation*/
#endif /* end of include guard: PRIMITIVES_PVUVQCJY */
