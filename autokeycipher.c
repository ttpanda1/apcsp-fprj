
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char table[26][26];

void createTable() {
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for ( int i = 0; i < 26; i++ ) {
        for ( int j = 0; j < 26; j++ ) {
            table[i][j] = letters[(i + j) % 26];
        }
    }
}

char *encryptMessage(char *plainText, char *keyWords)
{
    char *keyText = malloc(strlen(plainText) * sizeof(char) + 1);
    char *tmpText = malloc((strlen(plainText) + strlen(keyWords))* sizeof(char) + 1);
    char *eMessage = malloc(strlen(plainText) * sizeof(char) + 1);

    strcpy(tmpText, keyWords);
    strcpy(tmpText + strlen(keyWords) * sizeof(char), plainText);

    int j = 0;
    for(int i=0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            while( !isalpha(tmpText[j])) {
                j++;
            }

            keyText[i] = tmpText[j];

            j++;
        }
        else
        {

            keyText[i] = plainText[i];
        }

        keyText[i] = toupper(keyText[i]);
    }

    for ( int i = 0; i < strlen(plainText); i++ ) {
        if (isalpha(plainText[i])) {
            int rowNum = keyText[i] - 65;
            int colNum = plainText[i] - 65;

            eMessage[i] = table[rowNum][colNum];
        }
        else {
            eMessage[i] = plainText[i];
        }
    }

    return eMessage;
}

char *decryptMessage(char *eMessage, char *keyWords) {
    char *dMessage = malloc(strlen(eMessage) * sizeof(char) + 1);
    char *tmpKey = malloc((strlen(eMessage) + strlen(keyWords))* sizeof(char) + 1);

    strcpy(tmpKey,keyWords);

    for ( int i = 0; i < strlen(eMessage); i++ ) {
        tmpKey[i] = toupper(tmpKey[i]);

        if (isalpha(eMessage[i])) {
            dMessage[i] = eMessage[i] - tmpKey[i];

            if ( dMessage[i] < 0 ) {
                dMessage[i] = dMessage[i] + 26 + 65;
            }
            else {
                dMessage[i] = dMessage[i] + 65;
            }

            char tmp = dMessage[i];
            strncat(tmpKey, &tmp, 1);
        }
        else {
            dMessage[i] = eMessage[i];

            char tmp = tmpKey[i];
            strncat(tmpKey, &tmp, 1);
        }
    }

    return dMessage;
}

int main(int argc, char* argv[])
{
    createTable();

    /*char input[256], ED[256];
    int t = 0;

    while ( t == 0 ) {
        printf("Encrypt or Decrypt?\n");
        fgets(input, 256, stdin);
        sscanf(input, "%s", ED);

        if ( ED == "Encrypt" ) {
            t = 1;
            //break;
        }
        else if ( ED == "Decrypt" ) {
            t = 2;
            //break;
        }
    }*/

    char inputM[256], message[256];
    char inputK[256], key[256];

    printf("Message: \n");
    fgets(inputM, 256, stdin);
    sscanf(inputM, "%s", message);

    printf("Key: \n");
    fgets(inputK, 256, stdin);
    sscanf(inputK, "%s", key);

//    if ( t == 1 ) {
        printf("Encrypted Message: %s\r\n", encryptMessage(message, key));
//    }

//    if ( t == 2 ) {
        printf("Decyrpted Message: %s\r\n", decryptMessage(message, key));
//    }

    return 0;
}


