# Lab0 - 7-11 Merchandise
Making money as a student at NYCU can be quite difficult, especially for those who don’t own a vehicle. People who own a scooter at least get to travel around Hsinchu and earn $700NTD/hour as a tutor, but those without a vehicle are simply out of luck.  

You are a sophomore who wants to achieve financial freedom by the age of 22, thus you’ve made the mind that nothing is going to stop you from making money. After hours of research, you’ve decided to apply for a part-time job as a clerk at the 7-11 at Dining Hall 2.  

The day of the interview has come and you are given a test to show that you are capable of doing the job. The test description is as follows:  

Organizing merchandise and putting them on shelves is an important skill for anyone working at a convenience store. For this 7-11, there are a total of NN types of merchandise ready to be sold. Each type of merchandise has to be put in its respective position on the shelf, and for multiple merchandise of the same type, they are lined up one behind another at the same position. The frontmost item at one position is indexed 0, items that are placed later are put behind and indexed 1, 2, 3, ... and so on. From time to time, a random merchandise of its type has to be taken off the shelf and examined whether or not it has expired, therefore each merchandise has a value vv, which denotes the expiration date.  

Today, the 7-11 manager wants to test your capabilities of putting items on shelves and examining expiration dates of merchandises. Therefore, you are given a total number of QQ instructions. For each instruction, you are asked either to:  

1. Given a merchandise of type a (an integer) with expiration date x (an integer), put it on the a-th position on the shelf.  
2. For the merchandise of type a, check and tell us the expiration date x of the item indexed y.  

Note that, the shelf is empty at the beginning.  

Since the manager is querying randomly, if there is no item indexed y of merchandise type a, print -1.  

If you pass this test, you will be able to get the job. Can you succeed and eventually achieve financial freedom?  
## Input Format
On the first line there are 2 integers, NN indicates how many types of merchandise there are and QQ indicates the number of instructions.

QQ lines follow, each with 3 integers representing either instruction type 1 or 2:

For instruction type 1, the input takes three numbers 1 a x in a line with aa and xx representing the type of merchandise and the expiration date.

For instruction type 2, the input takes three numbers 2 a y in a line with aa and yy representing the type of merchandise and the index you are asked to check.

Constraints:

1 \le N \le 10^51≤N≤10 
5
 
1 \le Q \le 10^61≤Q≤10 
6
 
\text{Instruction type} \in \{1,2\}Instruction type∈{1,2}
0\le a \lt N0≤a<N
0\le x \lt 2^{31}0≤x<2 
31
 
0\le y \lt 10^50≤y<10 
5
