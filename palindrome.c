#include <stdio.h>

int palindrome(char word[], int l, int r){
    if(l>=r)
        return 0;
    else if(word[r] == word[l])
            palindrome(word,l+1,r-1);
}


int main(){
    char x[] = "apoaopa";
    int l = 0;
    int r = 6;
    int p = palindrome(x,l,r);
    if(p==0)
        printf("eh palindromo");
    else
        printf("não é");
}