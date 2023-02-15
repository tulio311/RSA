# RSA
RSA Encryption algorithm.

The directory with name RSA has a C implementation of RSA using data types defined in C. It works but the numbers that are required to use are too large. The other directory has a C implementation of the algorithm defining a "large number" structure with an array of shorts and functions to operate them. This is very inefficient and fills up RAM memory very fast. Appears to be that this implementation has to be done in binary to be able to manage this huge numbers (Probably there is some library that is capable of managing this numbers. I didn't searched for it because I underestimated this memory problem).   
