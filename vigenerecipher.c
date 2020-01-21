#include <stdio.h>
#include <string.h>

char key[] = "encrypt";
char keystring[200];
int k;
char charstring[] = "testingthiscode";
char output[200];

int main() {
  for ( int i = 0; strlen(charstring) > i; i++) {
    k = i % strlen(key);
    keystring[i] = key[k];
  }

  for ( int i = 0; strlen(charstring) > i; i++) {
    char tm = charstring[i] + keystring[i] - 194;
    int tmp = tm % 26;
    output[i] = 'a' + tmp;
    printf("%c", output[i]);
  }
  printf("\n");
}
