#include <stdio.h>

char table[26][26];

void createTable()
{
  int c = 0;
  int tmp = 0;
  int b = 0;
  int c2 = 0;
  int num = 0;
  int t = 0;

  for ( int i = 0; i < 26; i++ )
  {
    tmp = c % 26;
    b = tmp + 65;

    for ( int a = 0; a < 26; a++ )
    {
      if ( t == 0 ) {
        num = b + c2;
      }

      if ( num > 90 ) {
        num = 65;
        if ( t == 0 ) {
          c2 = 0;
        }
        else {
          num = num + 65;
        }
        t = 1;
      }

      table[a][i] = num;
      printf("%c", table[a][i]);
      c2++;
    }
    printf("\n");
    c2 = 0;
    c = c + 1;
    t = 0;
  }
}

int main()
{
  printf("Hello world\n");

  createTable();
}
