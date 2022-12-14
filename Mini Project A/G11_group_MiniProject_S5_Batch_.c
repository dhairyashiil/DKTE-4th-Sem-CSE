#include <stdio.h>
#include <string.h>
void decode(int n);
int main()
{
    printf("\n*****************************************************************\n\n");

    int n;
    printf("\nEnter the Number which you want to decode : ");
    scanf("%d", &n);

    int n1 = 13733;
    int n2 = 8143861;
    int n3 = 1241072;
    int n4 = 4470;
    int n5 = 4948079;
    int n6 = 278660;
    int n7 = 13733;
    int n8 = 3101;

    decode(n);
    printf("\n\n*****************************************************************\n\n");
    
    printf("Sample Inputs Given in Problem are : \n");
    printf("%d\n", n1);
    printf("%d\n", n2);
    printf("%d\n", n3);
    printf("%d\n", n4);
    printf("%d\n", n5);
    printf("%d\n", n6);
    printf("%d\n", n7);
    printf("%d\n", n8);

    printf("\nSample Outputs for given Sample Inputs are as follows : \n");

    decode(n1);
    decode(n2);
    decode(n3);
    decode(n4);
    decode(n5);
    decode(n6);
    decode(n7);
    decode(n8);

    printf("\n*****************************************************************\n");
    return 0;
}
void decode(int n)
{
    int i = 0;
    char string[100];
    while (n > 0)
    {
        int remainder = n % 26;
        if (remainder == 0)
        {
            string[i++] = 'z';
            n = (n / 26) - 1;
        }
        else
        {
            string[i++] = (remainder - 1) + 'a';
            n = n / 26;
        }
    }
    string[i] = '\0';

    strrev(string);  
    
    printf("The Decoded Word for given Number is : %s\n", string);
    
}