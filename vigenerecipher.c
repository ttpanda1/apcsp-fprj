#include <stdio.h>
#include <string.h>

char keystring[200];
int k;
char output[200];
char charstring[200];

int main(int argc, char* argv[]) {

if (argc >= 4) {
  for ( int i = 2; argc > i; i++) {
    strcat(charstring, argv[i]);
    strcat(charstring, " ");
  }
  printf("%s\n", charstring);
}
else {
  char* charstring = argv[2];
}

char* key = argv[1];

  for ( int i = 0; strlen(charstring) > i; i++) {
    k = i % strlen(key);
    keystring[i] = key[k];
  }
  printf("%s\n", keystring);

  for ( int i = 0; strlen(keystring) > i; i++) {
    if (charstring[i] == ' ') {
      for ( int b = strlen(keystring); b == i++; b - 1) {
        int a = b - 1;
        keystring[b] = keystring[a];
      }
      int t = i - 1;
      keystring[t] = ' ';
      printf("%s\n", keystring);
    }
  }
  printf("%s\n", keystring);

  for ( int i = 0; strlen(charstring) > i; i++) {
     if (charstring[i] != ' ') {
      char tm = charstring[i] + keystring[i] - 194;
      int tmp = tm % 26;
      output[i] = 'a' + tmp;
      printf("%c", output[i]);
    }

  }
  printf("\n");
}
