#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
  //数据域数组
    ElemType data[MAXSIZE];
    int length;
} SeqList;



//序列为空初始化列表
void initList(SeqList *list){
   list->length = 0;
}


//在尾部添加元素
int appendElem(SeqList *list, ElemType e){
   if(list->length >= MAXSIZE){
     printf("顺序表已满\n");
 return 0;
   }

   list->data[list->length] = e;
   list->length++;

   return 0;
}

//中间插入元素

int insertElem(SeqList * list,int l,ElemType e){

   if(l<=list->length){

       for(int i = list->length - 1;i>= l-1;i--){
     list->data[i+1] = list->data[i];
   }

         list->data[l] = e;
     list->length++;


     return 1;
   }

}


//遍历输出元素
void printList(SeqList *list){

   for(int i =0;i<list->length ; i++ ){
     printf("%d\n",list->data[i]);
   }

    printf("\n");
}


//删除元素;

void deleteElem(SeqList *list, int l,ElemType *e){


   *e = list->data[l-1]; //1.保存要删除的元素;

    if(l<=list->length){

      for(int i = l;i<list->length;i++){
         list->data[i-1] = list->data[i]; //向前赋值
      }

      list->length--;
    }

    return;
}


int findElem(SeqList *list,ElemType e){
    for(int i=0; i<list->length;i++){

      if(list->data[i] == e){
        return i + 1;
       }
    }

    return 0;
}


// 动态分配内存地址初始化

SeqList* initList(SeqList *list){

SeqList* newList = (SeqList*)malloc(sizeof(SeqList));

//根据输入元素类型调整顺序表大小 int->400byte
list->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);

list->length = 0;

return list;
 }


int main(){
  SeqList list;
  ElemType delnum;
  initList(&list);
  printf("list's length-> %d\n", list.length);
  printf("list's size %zu\n",sizeof(list.data));

   appendElem(&list,23);
   appendElem(&list,10);


  insertElem(&list,2,88);
  insertElem(&list,2,66);


   deleteElem(&list,2,&delnum);
  printList(&list);
  return 0;
}
