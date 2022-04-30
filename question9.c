#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkState(int state, char ch)
{
  if (state == 1)
  {
    printf("case for state %d\n", state);
    if (ch == 'a')
    {
      state = 2;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else if (ch == 'b')
    {
      state = 1;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else
    {
      printf("Wrong char \"%c\"\n\n", ch);
    }
  }
  if (state == 2)
  {
    printf("case for state %d\n", state);
    if (ch == 'a')
    {
      state = 4;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else if (ch == 'b')
    {
      state = 2;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else
    {
      printf("Wrong char \"%c\"\n\n", ch);
    }
  }
  if (state == 3)
  {
    printf("case for state %d\n", state);
    if (ch == 'a')
    {
      state = 1;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else if (ch == 'b')
    {
      state = 2;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else
    {
      printf("Wrong char \"%c\"\n\n", ch);
    }
  }
  if (state == 4)
  {
    printf("case for state %d\n", state);
    if (ch == 'a')
    {
      state = 3;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else if (ch == 'b')
    {
      state = 4;
      printf("Char=\"%c\", Going to state %d\n\n", ch, state);
    }
    else
    {
      printf("Wrong char \"%c\"\n\n", ch);
    }
  }
}

int main()
{
  char *string = NULL;
  size_t size = 1;
  string = (char *)malloc(size);
  int state = 1;
  int stringLength = 0;
  int i = 0;

  printf("Enter string to test: ");
  getline(&string, &size, stdin);
  string[strcspn(string, "\r\n")] = 0;
  stringLength = strlen(string);
  printf("You entered %s, %d characters\n\n", string, stringLength);

  for (i = 0; i < stringLength; i++)
  {

    printf("Loop=%d, State=%d, Char=\"%c\"\n", i + 1, state, string[i]);
    checkState(state, string[i]);
  }

  if (state == 1 || state == 2)
  {
    printf("\nACCEPTED State=%d, String=\"%s\"", state, string);
  }
  else
  {
    printf("\nNOT ACCEPTED State=%d, String=\"%s\"", state, string);
  }

  printf("\n");
  return 0;
};