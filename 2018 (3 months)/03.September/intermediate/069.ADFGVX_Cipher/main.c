#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void scramble(char * alphabet, char * substitionKey);
char * encrypt(char * substitionKey, char *transpotionKey, char * cipherText, char * msg, char * encryptedMsg);
char * decrypt(char * substitionKey, char *transpotionKey, char * cipherText, char * encryptedMsg, char * msg);

void main(void)
{
  char alphabet[36] = "ABCDEFGHIKLMNOPQRSTUVWXYZ0123456789 ";
  char cipherText[6] = "ADFGVX";

  char substitionKey[36];
  char transpotionKey[8] = "SCRAMBLE";

  char msg[256];
  char encryptedMsg[256];
  char decryptedMsg[512];

  do {
    printf("Enter the message: ");
    scanf("%s", &msg);

    scramble(alphabet, substitionKey);
    //Create the substitionKey
    //printf("Substition key: %s\n", substitionKey);
    encrypt(substitionKey, transpotionKey, cipherText, msg, encryptedMsg);
    printf("Encrypted message: %s\n", encryptedMsg);

    decrypt(substitionKey, transpotionKey, cipherText, encryptedMsg, msg);
    printf("Decrypted message: %s\n\n", msg);

  } while( strcmp(msg, "EXIT") != 0 );

}

void scramble(char * alphabet, char * substitionKey)
{
  void swap(char *a, char *b)
  {
    char aux;
    aux = *a;
    *a = *b;
    *b = aux;
  }

  int i, x, y;
  srand((unsigned) time(NULL));
  memcpy(substitionKey, alphabet, sizeof(char) *36);

  for(i=0; i<100; i++)
  {
    x = rand() %36;
    y = rand() %36;
    if(x != y)
      swap(&substitionKey[x], &substitionKey[y]);
  }
}

char * encrypt(char * substitionKey, char *transpotionKey, char * cipherText, char * msg, char * encryptedMsg)
{
  int i, j, cipherIndex=0;
  //cipherText 0-7
  //   A D F G V X
  // A substitionKey
  // D substitionKey
  // F substitionKey
  // G substitionKey
  // V substitionKey
  // X substitionKey
  // For each letter in msg
  for(i=0; msg[i] != '\0'; i++ )
  {
    //find msg[i] in substitionKey
    for(j=0; j<36; j++)
    {
      if(substitionKey[j] == msg[i])
      {
        //we add it to the encryptedmsg
        encryptedMsg[cipherIndex] = cipherText[j/6];
        cipherIndex++;
        encryptedMsg[cipherIndex] = cipherText[j%6];
        cipherIndex++;
        break;
      }
    }
  }
  encryptedMsg[cipherIndex] = '\0';

  //reorder the encryptedMsg with the transpotionKey
  }

char * decrypt(char * substitionKey, char *transpotionKey, char * cipherText, char * encryptedMsg, char * msg)
{
  int i, j, x, y, cipherIndex = 0;

  for(i=0; encryptedMsg[i] != '\0'; i=i+2 )
  {
    for(j=0; j<6; j++)
    {
      if(cipherText[j] == encryptedMsg[i]){
        x = j;
      }

      if(cipherText[j] == encryptedMsg[i+1]){
        y = j;
      }
    }
    msg[cipherIndex] = substitionKey[x*6 + y];
    cipherIndex++;
  }
  msg[cipherIndex] = '\0';

}
