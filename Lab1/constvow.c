#include <stdio.h>
int main(){
    char str[100];
    printf("Enter string::");
    scanf("%[^\n]%*c", str);
	    
    printf("\nThe string entered:: %s", str);
    int vowel=0;
    int consonant=0;
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='o' || str[i]=='u' || str[i]=='i'){
            vowel++;
        }
        else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            vowel++;
        }
        else if('a'<=str[i] && str[i]<='z'){
            consonant++;
        }
        else if('A'<=str[i] && str[i]<='Z'){
            consonant++;
        }
    }
    printf("\nNumber of vowel :: %d", vowel);
    printf("\nNumber of consonant :: %d", consonant);	    
    return 0;
}
