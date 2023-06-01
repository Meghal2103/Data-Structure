#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int lenghtOfString(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

void upperToLower(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[i] = s[i] + 32;
        }
    }
}

void lowerToUpper(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[i] = s[i] - 32;
        }
    }
}

void changeCase(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            s[i] = s[i] + 32;
        }
        else if(s[i]>=97 && s[i]<=122)
        {
            s[i] = s[i] - 32;
        }
    }
}

int countVovel(char s[])
{
    int j=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
        {
            j++;
        }
    }
    return j;
}

int countWords(char s[])
{
    int j=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if((s[i]==' ' && s[i-1]!=' ') || (s[i+1]=='\0' && s[i]!=' '))
        {
            j++;
        }
    }
    return j;
}

int containsOnlyAlphabetNumbers(char s[])
{
    int i=0;
    int j=0;
    while(s[i]!='\0')
    {
        if((s[i]>=90 && s[i]<=65) || (s[i]<=97 && s[i]>=122))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

char * reversingString(char s[])
{
    int len = lenghtOfString(s)-1;
    char * result = (char *)malloc(sizeof(char)*len);
    for(int i = 0; i < len+1; i++)
    {
        result[i] = s[len-i];
    }
    result[len+1]='\0';
    return result;
}

void reversingStringSame(char s[])
{
    int len = lenghtOfString(s);
    for(int i = 0; i < len/2; i++)
    {
        swap(&s[i], &s[len-i-1]);
    }
}

void countAlphabetChar(char s[])
{
    int alpbhabet[26]={0};
    for(int i = 0; i < 26; i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            alpbhabet[s[i]-65]++;
        }
        else if(s[i]>=97 && s[i]<=122)
        {
            alpbhabet[s[i]-97] = alpbhabet[s[i]-97] + 1;
        }
    }
    for(int i=0; i<26; i++)
    {
        if(alpbhabet[i]!=0)
        {
            printf("%c \n", i+65);
        }
    }
}

int pallindrome(char s[])
{
    int i = 0;
    int j = lenghtOfString(s)-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void duplicateAlphabet(char *s)
{
    int j=0;
    for(int i=0;i<lenghtOfString(s);i++)
    {
        int x=0;
        if(s[i]>=65 && s[i]<=90)
        {
            x=1;
            x=x<<(s[i]-'A');
        }
        else if(s[i]>=97 && s[i]<=122)
        {
            x=1;
            x=x<<(s[i]-'a');
        }
        if(x&j)
        {
            printf("Duplicate character is %c", s[i]);
        }
        else
        {
            j=x||j;
        }
    }
}

void anagram(char s1[], char s2[])
{
    int x = lenghtOfString(s1); 
    int y = lenghtOfString(s2);
    int arr[26]={0};
    int k=0;
    if(x==y)
    {
        int j=0;
        for(int i=0;i<x;i++)
        {
            int x=0;
            if(s1[i]>=65 && s1[i]<=90)
            {
                arr[s1[i]-65]++;
            }
            else if(s1[i]>=97 && s1[i]<=122)
            {
                arr[s1[i]-97]++;
            }
        }
        for(int i=0;i<y;i++)
        {
            if(s2[i]>=65 && s2[i]<=90)
            {
                arr[s2[i]-65]--;
            }
            else if(s2[i]>=97 && s2[i]<=122)
            {
                arr[s2[i]-97]--;
            }
        }
        for(int i=0; i<x; i++)
        {
            if(arr[i]!=0)
            {
                printf("Not Anagram");
                k=0;
                break;
            }
            k=1;
        } 
    }
    else
    {
        printf("Not Anagram");
    }
    if(k==1)
    {
        printf("Anagram");
    }
   
}

int main()
{
    // char a[] = "aBCDEf ghi___jKLMno pqrsT uvWXyZ";
    // int i = lenghtOfString(a);
    // printf("%d", i);
    // changeCase(a);
    // containsOnlyAlphabetNumbers(a);
    // printf("%d\n", countWords(a));
    // // char * f;
    // printf("%s \n", a);
    // reversingStringSame(a);
    // printf("%s \n", a);
    // char p[]="racecar";
    // int x = pallindrome(a);
    char a[]="racecar";
    char b[]="racecar";
    // countAlphabetChar(a); 
    // duplicateAlphabet(a);
    anagram(a,b);
}