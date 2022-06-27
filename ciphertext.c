#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptPlainText();
void decryptCipherText();

char upperLetter[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char lowerLetter[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(void)
{
    int n;

    while (1)
    {
        // taking input from user to encrypt or decrypt or exit.
        printf("For Encrypt Press 1.\nFor Decrypt Press 2.\nFor EXIT Press 0.\n");
        do
        {
            scanf("%d", &n);
            if (n != 1 && n != 2 && n != 0)
                printf("You DID NOT Press the Right Number!\n");
        } while (n != 1 && n != 2 && n != 0);

        // for exit the program.
        if (n == 0)
            break;

        // for encryptting plain text.
        else if (n == 1)
            encryptPlainText();

        // for decryptting ciphertext.
        else
            decryptCipherText();
    }

    return 0;
}

// encryptting plain text.
void encryptPlainText()
{
    int i, j, k, key, len;
    char plainText[1000];

    printf("Enter the KEY: ");
    scanf("%d", &key);
    getchar();
    printf("Enter the Plain Text: ");
    fgets(plainText, 1000, stdin);

    len = strlen(plainText);

    // printting encryptting text.
    printf("Ciphertext (Encrypted) Text: ");
    for (i = 0; i < len; i++)
    {
        // encryptting and printting lower case latter.
        if (islower(plainText[i]))
        {
            for (j = 0; j < 26; j++)
            {
                if (plainText[i] == lowerLetter[j])
                {
                    k = (j + key) % 26;
                    printf("%c", lowerLetter[k]);
                    break;
                }
            }
        }

        // encryptting and printting upper case latter.
        else if (isupper(plainText[i]))
        {
            for (j = 0; j < 26; j++)
            {
                if (plainText[i] == upperLetter[j])
                {
                    k = (j + key) % 26;
                    printf("%c", upperLetter[k]);
                    break;
                }
            }
        }

        // printting whitespace and symbol.
        else
            printf("%c", plainText[i]);
    }
    printf("\n\n");
}

// dencryptting plain text.
void decryptCipherText()
{
    int i, key, len;
    char cipherText[1000], ch;

    printf("Enter the KEY: ");
    scanf("%d", &key);
    getchar();
    printf("Enter the Cipher Text: ");
    fgets(cipherText, 1000, stdin);

    len = strlen(cipherText);

    // printting dencryptting text.
    printf("Plaintext (Dencrypted) Text: ");
    for (i = 0; i < len; i++)
    {
        // dencryptting and printting lower case latter.
        if (islower(cipherText[i]))
        {
            ch = cipherText[i] - key;
            if (ch < 'a')
                ch = ch + 'z' - 'a' + 1;
            printf("%c", ch);
        }

        // dencryptting and printting upper case latter.
        else if (isupper(cipherText[i]))
        {
            ch = cipherText[i] - key;
            if (ch < 'A')
                ch = ch + 'Z' - 'A' + 1;
            printf("%c", ch);
        }

        // printting whitespace and symbol.
        else
            printf("%c", cipherText[i]);
    }
    printf("\n\n");
}