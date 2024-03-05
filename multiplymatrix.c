#include<stdio.h>
int main()
{
int a[100][100],b[100][100],i,j,mul[100][100],row,column;

  printf("enter the no of rows: ");
  scanf("%d",&row);
   printf("enter the no of column: ");
  scanf("%d",&column);
printf("enter the elements of 1st matrix : \n");
  for(i=0;i<row;++i)
  {
      for(j=0;j<column;++j){
        printf("enter the element in a %d%d: ",i+1,j+1);
        scanf("%d",&a[i][j]);
      }

  }

    printf("enter the elements of 2nd matrix : \n");
  for(i=0;i<row;++i)
  {
      for(j=0;j<column;++j){
        printf("enter the element in b %d%d: ",i+1,j+1);
        scanf("%d",&b[i][j]);
      }

  }
//for multiplying
for (int i=0;i<row;++i)
{
for (int j=0;j<column;++j)
{
   for (int k = 0; k < row; k++){
                mul[i][j] += a[i][k]*b[k][j];
   }
}
}
//displaying of the multiplication result
for(int i=0;i<row;++i)
{
    for(int j=0;j<column;++j)
    {

          printf("%d",mul[i][j]);
            if(j==column-1){
            printf("\n\n");
            }
    }
}
return 0;
}
