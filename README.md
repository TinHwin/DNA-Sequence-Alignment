# DNA-Sequence-Alignment

/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Truong-Thinh Huynh
Section: 201

(Partnering is optional. See the guidelines on the assignments page.)
Partner's name: Preston Luie

Hours to complete assignment: 8 Hours



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/

Well, we used the example given in the pdf to check for any pattern and we did found a pattern that helps us find the
alignment. First we start from optMatrix[0][0] and check the char value diagonal to see if the two char are the same or not. 
If they are the same, then we know that the cost is 0 so we pushed along with the chars to our string. Then diagonal of that 
index that we just checked. Then we do the same, but if the two char is not the same, we checked to see
if optMatrix[i + 1][j + 1] + 1 has the same value as our current optMatrix[i][j]. If it is then we push the cost as 1 as it is not the 
same and the two chars. But if this is also not the same, then we have to check down and right index. Then we checked
optMatrix[i + 1][j] + 2 or optMatrix[i][j + 1] + 2 to see if either has the same value as our current optMatrix[i][j]. If either are, then
push the cost of two and the char along with - to symbolize a gap. At the end, we can return the string that have been storing our chars, 
and the cost.

/**********************************************************************
 * You are required to create one additional test case by hand. 
 * It should be constructed in such a way that you know the correct 
 * output before running your program on it, and it should be a 
 * "corner case" that helps check if your program handles all special 
 * situations correctly. Please list:
 * - a copy of the test case input
 * - the expected test case output
 * - whether your program ran correctly on it or not
 * - optionally, any other remarks
 **********************************************************************/
Input: lhs and rhs string with only char 'a' in it. This two string will be parameters for the default constructor
for the class EDistance. Then we use BOOST_REQUIRE_EQUAL to check the penalty function with 0 to see if it will gives us
the correct results.

Expected output: Since we know that if two value is the same, we should return 0, but if it returns something else, we can
safety assumed this will break the whole program.

What happened: The BOOST_REQUIRE_EQUAL will return 0 if two values are the same, and 1 if they are not. If the value is flip or return
other integer, then the whole program is wrong.

/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2GB and 4GB.
 **********************************************************************/

8GB

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 1GB (billion bytes) of memory?
 **********************************************************************/ 
a = N + 1
b = M + 1
largest N = 5

To be honest, we are not even a 100% sure if we are approaching this question correctly.
In our program, we first allocate the memory of the column plus 1 to provide space for 
the last column and row that is a gap in the matrix. Then we allocate the memory for each
row plus 1 in each column. But since each column is a pointer, each will be 8 bytes, while
the value for each row will be 4 as each will be int. Therefore, if we have M and N as 10 and
we add 1, both will be 11. So we allocate the pointer of columns first, which will gives us 88 bytes. 
Then we allocate each row so 11 * 4 * 11 which will be 484 bytes. So this our thinking so far.
Then we plugged the numbers into a * N^b and we found out that N has to equals 5 to it to be
less than 1GB.

So the largest N that my program can handle if it is limited to 1GB is 5 as the bytes used will
be 537109375 as N being 6 will be well over 1GB. But this example assumed M and N is 10.

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *  For help on how to do timing, see the checklist (e.g. -Xprof).
 *  If you get an OutOfMemoryError, see the checklist about -Xmx.
 *  If you get "Could not reserve enough space for object heap" or the timing
 *  of these tests takes too long for the last few test cases (N=20000 or higher), 
 *   note this, and skip filling out those rows of the table.
 **********************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.132014 
ecoli5000.txt          160             0.533416
ecoli10000.txt         223             2.25903
ecoli20000.txt         3135            8.8974
ecoli50000.txt         19485           81.4359
ecoli100000.txt        Killed


/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 0.100
b = 3
largest N = 95

We saw that when N is 1, the time in seconds is 0.132014 so we rounded that to 0.100 and have
that as out a as we figured that when N is 1, b doesn't really matter as N will makes it 1. So 
we used that as our starting point so we plugged in values for b until we saw that b gives us similar
results for time in seconds to our values from the table. 

So when plugged in values for N to determine the largest N we can have in 1 day of computation, we know that
N equals 95 is the maximum. The reason is a day in second is 86400 seconds and when we plugged N as 95, we get 
85737.5 which is almost maximizing the time as seconds available to us.

/**********************************************************************
 *  If you worked with a partner, do you have any remarks on the pair
 *  programming method? E.g., how many times did you switch, what are
 *  the tradeoffs of driving vs. navigating, etc.
 **********************************************************************/

I've found pair programming method really good and bad in some spot. The good aspect is that having a partner is
much easier to come up with ideas and help eachother when one person doesn't seems to know the solution. But the
bad aspect is that each one of us has preferences, so this means that it could be hard to read the code that
the other person is writing. But we have slowly learned to adapt to the convention of coding, which means this
process less problematic. Though out our project we have switched nearly 8 which each having 30 minutes to code and this took
us 8 hours. But while one person is coding the other person is giving feedbacks and ideas. The tradeoffs of driving are that you have
to figure a solution that combine your ideas with your partners while being able to have a proper solution. Additionally, it can be
harder to code while having someone examing your code. But the tradeoffs for navigating is that you can't code, but you have to have
give feedbacks so that your partner understand what is needed to be done. Also, it can be frustrating to not being able to come up with
ideas that could help both you and your partner when we are stuck.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs, 
 *  classmates, past Computing IV students, or anyone else.
 **********************************************************************/

None, except my partner Preston Luie

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

There is only one serious problem I've encountered is that the matrix values were messed up in some index that we didn't realized
until we tested the whole program. But we found the solution by printing the min, penalty and other value that can be printed. Then
we found out the our penalty returned the opposite value needed. When both char is the same, it return 1 when it supposed to return 0, so
we != it and it works fine and our matrix is now filled out correctly. Also, when doing valgrind, there is errors regarding uninitialized values,
but we have tried to fix it by giving a, b, and c values and it doesn't go away. But even so, there is no memory leaks, and everything works
perfectly so we decided to leave it as that as futher attempts to fix the code may makes the runtime longer or break the whole program. Plus,
we didn't didn't see anything in the rubrics regarding fixing these errors.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

Extra Credit:

Lambda Expression: We have a lambda expression in my main.cpp that capture by value of the int value for optDistance()
and print it out in the lambda expression's body.

EDistance::min vs std::min: The min that I've written is a bit faster when I printed out the time as seconds it takes to run.
My hypothesis is that my min compared all three values as once and return the min. But even though I did use a nested 
if-statement, it is still faster. The reason is that std::min only takes two values per call, so in order to compare three values,
it has to be call twice and the min from the first two values will be use as a value for the three value. This is slower as std::min
is also nested if_statement, so by seperating it to two std::min, it double the amount of if-statement, which makes it runs slower.
Other than the runtime, I think the memory usage for both is the same as it is only taking the value given and comparing it, and since
it is not allocating any new memory, both are the same.

