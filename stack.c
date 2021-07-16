#include <stdio.h>
#include <stdlib.h>


struct StackItem {
  struct StackItem * Next;
  void * _data;
};


struct StackItem * InitStack(void)
{
  return NULL;
}

void PushOnStack(void * NewData, struct StackItem ** Stack)
{
  if(*Stack == NULL)
    {
      printf("Stack Create\n");
      (*Stack) = (struct StackItem *) malloc(sizeof(struct StackItem));
      (*Stack)->Next = NULL;      
    }
  else
    {
      struct StackItem * TmpStack = (struct StackItem *)malloc(sizeof(struct StackItem));
      TmpStack->Next = (*Stack);
      (*Stack) = TmpStack;      
    }  
  (*Stack)->_data = NewData;
}

void * GetFromStack(struct StackItem ** Stack)
{
  struct StackItem * TmpStack = *Stack;
  if (TmpStack != NULL)
    {
      void * _data = TmpStack->_data;
      struct StackItem * NewStackHead = TmpStack->Next;
      free(*Stack);
      *Stack = NewStackHead;
      return _data;
    }
  return NULL;
}

void PrintIntStack(struct StackItem ** Stack)
{
  struct StackItem * TmpStack = *Stack;
  
  while(TmpStack != NULL)
    {
      printf("Stack data = %d\n" , *(int *)TmpStack->_data);
      TmpStack = TmpStack->Next;
    }    
}

int GetStackSize(struct StackItem ** Stack)
{
  int _size = 0;
  struct StackItem * TmpStack = *Stack;
  while(TmpStack != NULL)
    {
      _size++;
      TmpStack = TmpStack->Next;
    }
  return _size;
}


int main()
{
  struct StackItem * Stack = InitStack(); 

  int a = 1;
  int b = 2;
  int c = 3;

  PushOnStack(&a, &Stack);
  PushOnStack(&b, &Stack);
  PushOnStack(&c, &Stack);

  //printf("Stack data = %d\n" , *(int *)(Stack->Next)->_data);
  PrintIntStack(&Stack);
  printf("Stack size = %d\n", GetStackSize(&Stack));
  int cc = *(int *)GetFromStack(&Stack);
  printf("Digit from stack = %d\n", cc);

  PrintIntStack(&Stack);
  printf("Stack size = %d\n", GetStackSize(&Stack));
  if (Stack != NULL)
    {
      printf("Stack Destroy\n");
      free(Stack);
    }
  printf("Done\n");
  return 0;
}
