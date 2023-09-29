# dynamic programming 

1. Dynamic programming  is a technique to solve problmes by breaking it down into a collection of sub problems.
2. solving of those each sub problems just once and stroing these solutions inside the cache memory.

# recursion Issues

1. wheneven we see a recursive solution that has repeated calls for same input,we can optimize it using dp.

# Two different ways to stre our values so that they can be used at a laster

1. Memoization or Top down approach
2. Tabulition or Buttom up approach

# Memoization

1. we start from the extreme state  and compute result by using values that can be reach the destination i.e base condition

# Tabulization

1. we start from the base state  and compute results all the way till the extreme state.

# we can use dp if the problem can be

1. Divided into sub problmes
2. solved using recurrsive solution
3. containing repeative sub problem (optimal sub structure)