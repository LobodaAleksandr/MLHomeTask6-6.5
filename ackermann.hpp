#ifndef ACKERMANN_74TGPUY0

#define ACKERMANN_74TGPUY0

#include "primitives.hpp"

constexpr Function stack_size = M<S<plog, S<nth_prime, U<2,2>>, U<2,1>>>;
constexpr Function stack_push = S<multiplicate, U<2,1>, S<pow, S<nth_prime, S<stack_size, U<2,1>>>, S<N, U<2,2>>>>;
constexpr Function stack_top = S<decrement, S<plog, S<nth_prime, S<decrement, S<stack_size, U<1,1>>>>, U<1,1>>>;
constexpr Function stack_pop = S<divide, U<1,1>, S<pow, S<nth_prime, S<decrement, S<stack_size, U<1,1>>>>, S<N, stack_top>>>;
constexpr Function if_n_not_zero = S<stack_push, S<stack_push, S<stack_push, U<3,1>, S<decrement, U<3,2>>>, U<3,2>>, S<decrement, U<3,3>>>;
constexpr Function if_m_not_zero = S<R<if_n_not_zero, S<stack_push, S<stack_push, U<5,1>, S<decrement, U<5,2>>>, S<N, S<Z, U<5,1>>>>>, U<3,1>, U<3,2>, U<3,3>, S<is_zero, U<3,3>>>;
constexpr Function work_with_extracted_data = S<R<if_m_not_zero, S<stack_push, U<5, 1>, S<add, U<5,3>, S<N, S<Z, U<5,1>>>>>>, U<3,1>, U<3,2>, U<3,3>, S<is_zero, U<3, 2>>>; //3 args
constexpr Function iteration = S<work_with_extracted_data, S<stack_pop, S<stack_pop, U<1,1>>>, S<stack_top, S<stack_pop, U<1,1>>>, S<stack_top, U<1,1>>>;
constexpr Function guarded_iteration = S<R<iteration, U<3,1>>, U<1,1>, S<is_zero, S<decrement, S<stack_size, U<1,1>>>>>;
constexpr Function n_iterations = R<U<1,1>, S<guarded_iteration, U<3,3>>>;
constexpr Function five = S<N, S<N, S<N, S<N, S<N, Z>>>>>;
constexpr Function koef = S<multiplicate, five, five>;
constexpr Function needed_iterations = M<S<substract, S<stack_size, S<n_iterations, U<2,1>, S<multiplicate, U<2,2>, S<koef, U<2,1>>>>>, S<N, S<Z, U<2,1>>>>>;
constexpr Function ackermann_stack = S<n_iterations, S<stack_push, S<stack_push, S<N, S<Z, U<2,2>>>, U<2,1>>, U<2,2>>, S<S<multiplicate, needed_iterations, koef>,S<stack_push, S<stack_push, S<N, S<Z, U<2,2>>>, U<2,1>>, U<2,2>>>>;
constexpr Function ackermann = S<stack_top, ackermann_stack>;
#endif /* end of include guard: ACKERMANN_74TGPUY0 */
