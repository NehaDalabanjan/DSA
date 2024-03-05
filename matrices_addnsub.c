#include<stdio.h>
int main()
{
  int row,column, a[100][100],b[100][100],sum[100][100],i,j,sub[100][100];
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
 //for adding n subtracting

 for(i=0;i<row;++i)
  {
      for(j=0;j<column;++j){
            sum[i][j]=a[i][j]+b[i][j];
            sub[i][j]=a[i][j]-b[i][j];
    }
  }

  //result printing
  printf("sum of matrices is:  \n");
  for(i=0;i<row;++i)
  {
      for(j=0;j<column;++j){
            printf("%d",sum[i][j]);
            if(j==column-1){
            printf("\n\n");
            }
      }
  }

    printf("subtraction of matrices is:  \n");
  for(i=0;i<row;++i)
  {
      for(j=0;j<column;++j){
            printf("%d",sub[i][j]);
            if(j==column-1){
            printf("\n\n");
            }
      }
  }
  return 0;
}
