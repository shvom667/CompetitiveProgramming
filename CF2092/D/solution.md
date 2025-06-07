
If only one unique character is present then the answer is -1



Figure out the count of A, B, C

ca 
cb
cc

Let's say that A has 2nd greatest count ca

find a location where a substring of A touches a substring of some other char say B  [only for example it could be C too]

eg A has least count

AABABBBBBC
Location found

AA|BABBBBBC


now insert Greatest + smallest combination here until cnt smallest count != 2nd smallest count

AA BCBC  BABBBBBC

Now both A and C are present 3 times.

Greatest count is for B, 
and A and C count are equal


Now choose the position between greatest and any of the two other chars 
AA BCBC |  BABBBBBC

add combination of third char and other smaller  till the size is equal
and we have insert AC pairs here

AA BCBC ACACACACAC  BABBBBBC

AABCBCACACACACACBABBBBBC






