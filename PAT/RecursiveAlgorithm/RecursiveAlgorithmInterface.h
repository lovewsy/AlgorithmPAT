#ifndef RecursiveAlgorithmInterface_H
#define RecursiveAlgorithmInterface_H

/*
Full permutation 
*/ 
void BasicFullPermutation();

/*
* n queue
* Place n queens on an n*n chess board, and require that no queen is in same row, column or diagonal as each other. 
* Give the count of solutions!
* Every column only has one queen and every row only has one queen. 
* We can consider the column index of queen as known condition, 
* queens' indexs from 1 to n correspond to the indexs of columns from 1~n one by one.
* Then perform full permutation on 1~n of row index.
* Therefore we can get the solutions which all queens are placed in different row and column. 
* Finally, we filter the solutions which some queens exist in same diagonal.
*/
void NQueens();

#endif
