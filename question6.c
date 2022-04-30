#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct CELL
{
  int element;
  struct CELL *next;
};

typedef struct CELL *LIST;

LIST makeList(int arr[], int i, int n);
void printList(LIST w);
int length(LIST w);
bool hasElem(LIST w, int x);
int findMax(LIST w);
int findMin(LIST w);
int range(LIST w);

// MAIN START
int main(void)
{
  int arr[] = {3, 5, 2, 7, 4, 9, 19};
  LIST w = makeList(arr, 0, 7);
  printf("List:");
  printList(w);
  printf("Range of the list is: %d", range(w));
  return 0;
}
// MAIN END

int findMax(LIST w)
{
  if (w == NULL)
  {
    return -1;
  }
  if (w->next == NULL)
  {
    return w->element;
  }
  int v = findMax(w->next);
  return v > w->element ? v : w->element;
}

int findMin(LIST w)
{
  if (w == NULL)
  {
    return -1;
  }
  if (w->next == NULL)
  {
    return w->element;
  }
  int v = findMin(w->next);
  return v < w->element ? v : w->element;
}

int range(LIST w)
{
  int max = findMax(w);
  int min = findMin(w);
  return max - min;
  // return findMax(w) - findMin(w);
}

















LIST makeList(int arr[], int i, int n)
{
  if (i == n) // end of array
    return NULL;
  else
  {
    LIST w = (LIST)malloc(sizeof(struct CELL));
    w->element = arr[i];
    w->next = makeList(arr, i + 1, n);
    return w;
  }
}

void printList(LIST w)
{
  if (w == NULL)
    printf("<null>\n");
  else
  {
    printf("%d --> ", w->element);
    printList(w->next);
  }
}

int length(LIST w)
{
  if (w == NULL)
    return 0;
  else
    return 1 + length(w->next);
}

bool hasElem(LIST w, int x)
{
  if (w == NULL)
    return false;
  else if (w->element == x)
    return true;
  else
    return hasElem(w->next, x);
}