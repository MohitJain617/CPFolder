/*
Burnside lemma: 
---------------
(1/n)*sum(c[0]...c[n-1])
where n ways to change positions and c[k] is 
combinations that remain unchanged when k'th way applied
c[0] = total combinations usually

Game theory: 
-------------
Derangement rec:
----------------
D[n] = (n-1)(D[n-1] + D[n-2])
D[1] = 0, D[2] = 1

Catalan Number
--------------
2n_C_n - 2n_C_(n+1) 
C[n] = no. of binary trees of n nodes (l and r diff)
C[n] = no of trees of n+1 nodes (l and r same)
*/