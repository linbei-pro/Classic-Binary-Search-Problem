#include <stdio.h>
#include <stdlib.h>
#define N 100010
int num[N][2];
/*
不一定要将巧克力分完

每一块巧克力最多能分成数量 = (H / 正方形边长) * (W / 正方形边长)
*/
int main(int argc, char *argv[])
{
  int max = 0;                          //最大边长数
  int count = 0;                        //能够分的巧克力份数
  int n = 0,k = 0;                      //巧克力块数、小朋友数
  int i = 0,j = 0;
  int flag = 0;                         //标志位
  
  scanf("%d %d",&n,&k);
  

  for(i = 0;i < n;i ++)
    scanf("%d %d",&num[i][0],&num[i][1]);//获取巧克力边长  

  for(i = 1;i < 100000;i ++){
    for(j = 0;j < n;j ++){

      count += (num[j][0] / i) *(num[j][1] / i);
      if(count >= k){
        max = i;
        flag = 1;                         //如果flag等于1说明还有可能有更大的边长
        break;
      }
      
    }

    if(flag == 0)break;                   //flag等于0说明最大边长已找到
    flag = 0;
    count = 0;
  }

  printf("%d",max);

  return 0;
}
