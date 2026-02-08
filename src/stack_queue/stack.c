#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 

//stack 栈
typedef int Elemtype;

//定义栈结构
typedef struct { 
    Elemtype data[MAXSIZE];
    //栈顶指针的位置(下标)
    int top; 
} Stack;

//栈的顺序结构初始化动态内存分配


// typedef struct {
//    Elemtype *data;
//    int top;
// } Stack;
Stack* initStack(){
    
  //计算整个Stack 结构体所需的字节数:{
  //    sizeof(int) + siezeof(Elemtype*)
  //  }
  Stack* s = (Stack*)malloc(sizeof(Stack));


  //为栈的数据存储区分配内存

  //sizeof(Elemtype) * MAXSIZE：计算能存 MAXSIZE 个元素所需的总字节数
s->data = (Elemtype*)malloc(sizeof(Elemtype) * MAXSIZE);
s->top = -1;


//返回新栈的指针给调用者使用
return s;

}

//初始化栈结构
void initstack(Stack *s){
  s->top = -1;
}

//判断栈是否为空
int isEmpty(Stack *s){
   
  if(s->top ==-1){
       printf("当前栈元素的内容为空\n");
  }

  else {
      return 0;

  }
}

//进行进栈/出栈操作 


int push(Stack *s,Elemtype e ){

  //如果最后一个数据的下标大于等于栈长度-1, 则这个栈标记为满
  if(s->top>=MAXSIZE-1){
     printf("这个栈已满, 无法进行压栈\n");
     return 0;
  }

  //先为下标++, 然后为下标赋值
  s->top++;
  s->data[s->top] = e;

  return 1;
}

int pop(Stack *s,Elemtype *e){
     if(s->top == -1){
        printf("当前栈元素的内容为空\n");

        return 0;

     }
*e = s->data[s->top];

s->top--;
return 1;
}

//获取栈顶元素
int getTop(Stack *s,Elemtype *e){
  

  if(s->top==-1){
     printf("当前栈顶元素为空\n");
    
     return 0;
  }

  *e = s->data[s->top];

  return 1;
}

int main(){ 

   Stack s;

   //初始化栈
 initstack(&s);

 //对栈进行压栈,10<-20<-30;
  push(&s,10);
  push(&s,20);
  push(&s,30);
Elemtype e;
//获取栈顶的元素
//出栈
pop(&s,&e);
printf("%d\n",e);
getTop(&s,&e);
printf("%d\n",e);

pop(&s,&e);
printf("%d\n",e);

getTop(&s,&e);
printf("%d\n",e);
  return 0;
}