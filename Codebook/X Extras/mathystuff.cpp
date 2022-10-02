/*
Burnside lemma: 
---------------
(1/n)*sum(c[0]...c[n-1])
where n ways to change positions and c[k] is 
combinations that remain unchanged when k'th way applied
c[0] = total combinations usually

Derangement rec:
----------------
D[n] = (n-1)(D[n-1] + D[n-2])
D[1] = 0, D[2] = 1

Catalan Number
--------------
2n_C_n - 2n_C_(n+1) 
C[n] = no. of binary trees of n nodes (l and r diff)
C[n] = no of trees of n+1 nodes (l and r same)

Fermats theorem
---------------
a^p = a (mod p) 
(when a,p coprime) 
so a^(p-1) mod p = 1

Wilson's Theorem
----------------
if p is prime then
(p-1)! = -1 or p-1 (mod p)

Game Theory
-----------
Parital Games - Eg: Chess, TicTacToe
Impartial - Moves only depend on state of the game.

Types of Impartial Games -
a) Normal Game: Player who plays the last move wins
b) Misere Game: Player who plays the last move loses
    
NIM GAME- Impartial Normal Game;
rules-  
Stone piles:  [a_1, a_2, a_3....... a_n] 
In each turn, a player : choose one pile -> remove atleast one or more stones
The player who takes the last stone wins.
Alice moves first.
If XOR(a_1, a_2 .... a_n) == 0
    Bob wins
else 
    Alice wins

What is Sprague-Grundy Theorem? 
Suppose there is a composite game (more than one sub-game) made up of N sub-games and two players, A and B. Then Sprague-Grundy Theorem says that if both A and B play optimally (i.e., they don’t make any mistakes), then the player starting first is guaranteed to win if the XOR of the grundy numbers of position in each sub-games at the beginning of the game is non-zero. Otherwise, if the XOR evaluates to zero, then player A will lose definitely, no matter what.
We can apply Sprague-Grundy Theorem in any impartial game and solve it. The basic steps are listed as follows: 
-Break the composite game into sub-games.
-Then for each sub-game, calculate the Grundy Number at that position.
-Then calculate the XOR of all the calculated Grundy Numbers.
-If the XOR value is non-zero, then the player who is going to make the turn (First Player) will win else he is destined to lose, no matter what.

 A Dynamic Programming (Memoization-based) approach to 
 calculate Grundy Number of a Game
 Game Description-
 Just like a one-pile version of Nim, the game starts with
 a pile of n stones, and the player to move may take any 
 positive number of stones.
 The last player to move wins. Which player wins the game?

A Function to calculate Mex of all the values in that set
This function remains same 
*/
int calculateMex(unordered_set<int> Set) {
	int Mex = 0;
	while (Set.find (Mex) != Set.end())
		Mex++;
	return (Mex);
}

// A function to Compute Grundy Number of 'n'
// Only this function varies according to the game
int calculateGrundy(int n, int Grundy[]) {
	if (n == 0)
		return (0);
	if (Grundy[n] != -1)
		return (Grundy[n]);
	unordered_set<int> Set; // A Hash Table
	for (int i=0; i<=n-1; i++)
			Set.insert(calculateGrundy(i, Grundy));
	// Store the result
	Grundy[n] = calculateMex (Set);
	return(Grundy[n]);
}
//Driver program to test above functions
int main() {
	int n = 10;	
	// An array to cache the sub-problems so that
	// re-computation of same sub-problems is avoided
	int Grundy[n+1];
	memset (Grundy, -1, sizeof(Grundy));
	printf ("%d", calculateGrundy(n, Grundy));
	return (0);
}
