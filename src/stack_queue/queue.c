#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
//新建队列结构体
typedef struct 
{
   ElemType data[MAXSIZE];
   int front;
   int rear;
   int size;
  /* data */
} Queue;



//队列的顺序结构初始化动态内存分配
Queue*  initqueue(){ 
  Queue *q = (Queue* )malloc(sizeof(Queue));
  ElemType* e = (ElemType* )malloc(sizeof(ElemType) * MAXSIZE);
q->front = 0;
q->rear = 0;
q->size = 0;
   return q; 
}




int main(){
   

  return 0;
}