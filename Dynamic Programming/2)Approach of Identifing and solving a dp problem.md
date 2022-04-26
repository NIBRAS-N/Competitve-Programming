# How to Identify a DP problem?

It is very important to idnetify a dp problem when you see a question.  
Generally [Not every time]  if the problem statement asks for these queries:
- Count the total number of ways
- Given multiple ways of doing a task, which way will give the minimum or the maximum output.  

We can try to apply recursion. Once we get the recursive solution, we can go ahead to convert it to a dynamic programming one.


# Steps To Solve The Problem After Identification:
- Try to represent the problem in terms of indexes.
- Try all possible choices/ways at every index according to the problem statement.
- If the question states
    - Count all the ways – return sum of all choices/ways.
    - Find maximum/minimum- return the choice/way with maximum/minimum output.
