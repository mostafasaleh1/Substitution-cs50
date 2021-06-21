#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //checking the validation of the key

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
   
    //Checking if the input is 26 character or not
    
    if (strlen(argv[1]) != 26)
    {
        printf("The key must be 26 characters\n");
        return 1;
    }
   
    //checking if it's all alphabet or not
   
    int arraylength = strlen(argv[1]);
   
    for (int i = 0; i < arraylength; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("The key must be characters only\n");
            return 1;
        }
    }
    //
    char a[2][26];
    for (int i = 0; i < arraylength; i++)
    {
        a[0][i] = 'A' + i;
        a[1][i] = argv[1][i];
    }
    // chaking if there are repeated characters
    for (int i = 0; i < arraylength; i++)
    {
        int j = 0;
        for (int k = 0; k < arraylength; k++)
        {
            if (toupper(a[1][k]) == toupper(a[1][i]))
            {
                j++;
                if (j == 2)
                {
                    printf("The key must't have repeated characters\n");
                    
                }
            }
        }
    }
    
//prompt the input from the user and checking if it's lower or upper and printing the results
   
    string PlainText = get_string("plaintext: ");
    printf("ciphertext: ");
   
    for (int i = 0, j = strlen(PlainText); i < j; i++)
    {
        if (isalpha(PlainText[i]))
        {  
            if (islower(PlainText[i]))
            {
                for (int j = 0; j < arraylength; j++)
                {
                    if (tolower(a[0][j]) == PlainText[i])
                    {   
                        printf("%c", tolower(a[1][j]));
                    }
                }
            }
            if (isupper(PlainText[i]))
            {
                for (int j = 0; j < arraylength; j++)
                {
                    if (toupper(a[0][j]) == PlainText[i])
                    {   
                        printf("%c", toupper(a[1][j]));
                    }
                }
            }
        }
        else
        {
            printf("%c", PlainText[i]);
        }
    }
    printf("\n");
}