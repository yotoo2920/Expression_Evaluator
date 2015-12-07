#ifndef ASSOCIATIVITY_H
#define ASSOCIATIVITY_H

// This is part of the Shunting Yard algorithm
// Find the associativity of the right and left value
// For example input: 3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3
// Returns associativity of
/*
	operator | Precedence | Associativity
		^			4			Right
		*			3			Left
		/			3			Left
		+			2			Left
		-			2			Left
*/
enum AssociativityEnum
{
  Right, Left
};

#endif
