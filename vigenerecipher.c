#include <stdio.h>
#include <string.h>

char keystring[] = "encryptencryptencrypt";
char charstring[] = "testingthiscode";
char output[100];

int main() {
  for ( int i = 0; strlen(charstring) > i; i++) {
    char tm = charstring[i] + keystring[i] - 194;
    int tmp = tm % 26;
    output[i] = 'a' + tmp;
    printf("%c", output[i]);
  }
}
