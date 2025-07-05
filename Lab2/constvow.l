%{
#include <stdio.h>

// Variables to count vowels and consonants
int v = 0, c = 0;

%}

%%

// Match vowels (both uppercase and lowercase) and increment the vowel count
[aeiouAEIOU]   v++;  

// Match any alphabetic character and increment the consonant count
[a-zA-Z]       c++;  

%%

int main()  
{
    // Prompt the user for input
    printf("ENTER INPUT : ");
    
    // Start lexical analysis using Flex's yylex() function
    yylex();  
    
    // Display the counts of vowels and consonants
    printf("VOWELS=%d\nCONSONANTS=%d\n", v, c);

    return 0;
}

// Define yywrap function to indicate end of input
int yywrap() {
    return 1;
}
