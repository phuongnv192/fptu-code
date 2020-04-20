#include <stdio.h>
int main()
 {char s[80];
  printf("Enter a string: ");
  fgets(s, 80, stdin);
  printf("Here is your string: %s", s);
  printf("Enter another string: ");
  gets(s);
  printf("Here is your other string: %s", s);
  return(0);
}
/*
The advantage of using fgets( ) over gets( ) is that you can prevent the input array from
being overrun. However, the array may contain the newline character.
*/
