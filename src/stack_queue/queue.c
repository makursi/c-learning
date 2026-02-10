#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 100

typedef int ElemType;
//新建循环队列结构体
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

  if(q==NULL){
      return NULL;
  }
q->front = 0;
q->rear = 0;
q->size = 0;
   return q; 
}

//判断队列状态

//1.判断队列是否为空

bool isEmpty(Queue* q){
    return q->size == 0;
}


//2.判断队列是否为空
bool isFull(Queue* q){
   return q->size  == MAXSIZE;
}


//3.判断队列当前大小
int  wahtSize(Queue* q)
{
   return q->size;
}

//入队操作
bool enqueue(Queue* q,ElemType value){
   if(q==NULL) return false;
    

  if(isFull(q)){
     printf("队列已满, 无法入队! \n");
     return false;
  }
     
  p->data[q->rear] = value;
  p->rear = (q->rear + 1 ) % MAXSIZE;

  p->size++;

  return true;

}

//出队操作
bool dequeue(Queue* q,ElemType* value){
   
  if(q==NULL || value == NULL){
     return false;
  }

  if(isEmpty(q)){
     printf("队列为空,无法出队 \n");
     return false;

  }

  *value = q->data[q->front];
  q->front = (q->front + 1) % MAXSIZE;

  q-size--;

  return true;
}

//销毁队列,释放内存
void destroyQueue(Queue* q){
   if(q != NULL){
     free(q);
   }
}





int main(){
   

  return 0;
}