# RSA
RSA Encryption algorithm.

The directory named RSA has a C implementation of this algorithm using data types defined in C. It works but the numbers that are usually required in this algorithm are too large and don't fit in these data types. 

The directory RSA_NumerosGrandes has a C implementation of the algorithm defining a "large number" structure with an array of shorts and defining functions to operate them arithmetically. This is very inefficient and fills up RAM very fast. It seems that the implementation of this algorithm has to be done at binary level to be able to manage these huge numbers while keeping the algorithm into the needed memory constraints.   
