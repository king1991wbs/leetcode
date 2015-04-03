/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */

//author:https://leetcode.com/discuss/29623/11ms-solution-with-unified-hash-fxn

#include <iostream>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> ret;
    if ( s.length() < 11 )
    {
        return ret;
    }

    char table[1048576] = "";//1024*1024
    unsigned int hash = 0U;

    for ( size_t i = 0; i < 10; ++i )
    {
        /** 'A' - 'A' + 1 = 1  = 1 (mod 5)
         *  'C' - 'A' + 1 = 3  = 3 (mod 5)
         *  'G' - 'A' + 1 = 7  = 2 (mod 5)
         *  'T' - 'A' + 1 = 20 = 0 (mod 5)
         */
        hash = ( hash << 2 ) | ( ( s[i] - 'A' + 1 ) % 5 );
    }

    table[hash] = 1;

    for ( size_t i = 10; i < s.length(); ++i )
    {
        hash = ( ( hash << 2 )
             ^ ( ( s[ i - 10 ] - 'A' + 1 ) % 5 ) << 20 )//erase the first letter and move in new one
             | ( ( s[i] - 'A' + 1 ) % 5 );

        if ( table[hash] == 0 )
        {
            table[hash] = 1;//appear the first time
        }
        else if ( table[hash] == 1 )//already have
        {
            table[hash] = 2;
            ret.push_back( string( s, i - 9, 10 ) );
        }
    }

    return ret;
}