# Disjoint-Test-Union
## Description
Mahir lives in Gridland. Gridland consists of N rows and M columns where every point has a height. To go from one cell to it’s adjacent ones Mahir needs a ladder which is at least as long as the height difference. For example to go from a cell which has height X to a cell which has height Y Mahir needs a ladder at least |X-Y| units long. Mahir is curious, he wants to know the the shortest ladder which allows him to go from one given cell, X, to the other, Y.

3 2

4 5

From (1, 2) to (2, 2) via (1, 1) and (2, 1), 1 unit length of ladder is sufficient. 

**Important Notes:**

- Mahir can only travel from a cell to it’s adjacent ones in a single step.(i.e he can go 4 directions which are left,right,bottom and up.)
- The upper leftmost cell is (1,1) and the bottom rightmost cell is (N,M).


## Input/Output Format 
#### Input Format
The first line of the input file holds two integers, N and M, showing the number of rows and the number of columns respectively.
In the following N lines, heights of cells are given, M integers in every line. In the following line, number of queries Q is given.
Then, the next Q lines will have 4 integers indicating two cells of a query.
#### Output Format
Print the answer for the each query, minimum length of the ladder that Mahir can travel from a cell to the other one, in a new line.
## Examples 
**1.Sample Input**

5 5

1 2 3 4 5

100 100 23 100 100 

100 100 43 100 100

100 100 63 100 100 

100 100 83 100 100

1

1 1 5 3

**Sample Output**

20

**Explanation**

(1,1) → (1,2) → (1,3) → (2,3) → (3,3) → (4,3) → (5,3)
2

**2.Sample Input**

5 5

1 2 3 4 5


100 100 23 100 100 

100 100 43 100 100

100 100 63 100 100 

100 100 83 100 100

2

4 2 4 4

1 1 1 5

**Sample Output**

17 

1

**Explanation**
- First query,(4,2) → (5,2) → (5,3) → (5,4) → (4,4)
- Second query,(1,1) → (1,2) → (1,3) → (1,4) → (1,5)

## Implementation Details
1. Variable limits are as follows:
- 1 ≤ N, M ≤ 103
- 1≤Q≤105
- 1≤heightof acell≤109
2. Execution time limit is 2 seconds.
3. The program will be compiled with cmake CMakeLists.txt && make command.
4. Execute the program with ./project4 inputFile outputFile command.
