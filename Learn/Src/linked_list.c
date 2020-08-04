#include "linked_list.h"


struct Node
{
  ElementType Element;
  Position Next;
};



int IsEmpty(List L)
{
  return L->Next == NULL;
}

int IsLast(Position P, List L)
{
  return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
  Position P;

  P = L->Next;

  while((P != NULL)&&(P->Element != X))
        P = P->Next;

  return P;
}

void Delete(ElementType X, List L)
{
  Position P,temp;

  P = FindPrevious(X,L);

  if (!IsLast(P,L))
  {
      temp = P->Next;
      P->Next = temp->Next;
      free(temp);
  }
}

Position FindPrevious(ElementType X, List L)
{
  Position P;

  P = L;

  while((P->Next != NULL)&&(P->Next->Element != X))
        P = P->Next;

  return P;
}

void Insert(ElementType X, List L, Position P)
{
  Position temp;

  temp = malloc (sizeof(struct Node));

  if (temp == NULL)
  {
    printf("Out Of Space!\r\n");
  }

  temp->Element = X;
  temp->Next = P->Next;
  P->Next = temp;
}

void DeleteList(List L)
{
  Position P,temp;

  P = L->Next;
  L->Next = NULL;

  while (P != NULL)
  {
      temp = P->Next;
      free(P);
      P = temp;
  }

}


