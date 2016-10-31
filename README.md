Knapsack(0-1)

Given two n-tuples

{v1, v2, v3....vn} and {w1, w2, w3....wn},and, W>0. We wish to determine a subset T such that Maximizes - ,Subject to - ≤ W.

Meaning, given n items of weight wi and value vi,find the items that should be taken such that the weight is less than the maximum weight W and the corresponding total value is maximum.

We can either take the complete item (1) or not (0).

Let A(i,j) represents maximum value that can be attained if the maximum weight
is W and items are chosen from 1...i. We have the following recursive definition
This problem exhibits both overlapping subproblems and optimal substructure and is therefore a
good candidate for dynamic programming.
