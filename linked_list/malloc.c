#include<stdio.h>
#include<stdlib.h>
int main(){

  int number = 0;


char *grades  = malloc(number*sizeof(char));

printf("请输入你的成绩数:");
   scanf("%d",&number);


if(grades == NULL){
   printf("存储失败");
   return 1;
}


for(int i = 0;i < number;i++) {
   printf("输入成绩#%d",i+1);
  scanf(" %c", &grades[i]);
}


for(int i = 0;i < number;i++) {
    printf(" %c",grades[i]);
}

free(grades);

grades = NULL;
  return 0;

}
