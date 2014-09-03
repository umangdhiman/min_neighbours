#include<stdio.h>
#include<math.h>
int main(){
    int n,i,j,i1,j1,diff,diff1,sum=0;
    int **a=NULL,**b=NULL;
    printf("Enter size of matrix\n");
    scanf("%d",&n);
    a = (int *) (malloc((n+1) * sizeof(int *)));//Dynamic Allocation for rows
    b = (int *) (malloc((n+1) * sizeof(int *)));
    printf("Enter the numbers\n");
    for(i=1;i<=n;i++){  //for dynamic allocation & initializing the arrays
        a[i]=(int) malloc((n+1)*sizeof(int));//Dynamic Allocation for columns
        b[i]=(int) malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=0;      //array used to mark as unvisited
        }
    }
    printf("Sequence is -->\n");
    for(i=1,j=1;;){
        diff=32767;         //initialize with max possible difference
        if(i+1<=n&&b[i+1][j]!=1){    //check for next row neighbour
            diff1=a[i][j]-a[i+1][j];
            diff1=abs(diff1);
            if(diff1<diff){         //compare to find minimum difference
                diff=diff1;
                i1=i+1;
                j1=j;
            }
        }
        if(j+1<=n&&b[i][j+1]!=1){    //check for next column neighbour
            diff1=a[i][j]-a[i][j+1];
            diff1=abs(diff1);
            if(diff1<diff){         //compare to find minimum difference
                diff=diff1;
                i1=i;
                j1=j+1;
            }
        }
        if(i-1>0&&b[i-1][j]!=1){   //check for previous row neighbour
            diff1=a[i][j]-a[i-1][j];
            diff1=abs(diff1);
            if(diff1<diff){         //compare to find minimum difference
                diff=diff1;
                i1=i-1;
                j1=j;
            }
        }
        if(j-1>0&&b[i][j-1]!=1){   //check for previous column neighbour
            diff1=a[i][j]-a[i][j-1];
            diff1=abs(diff1);
            if(diff1<diff){         //compare to find minimum difference
                diff=diff1;
                i1=i;
                j1=j-1;
            }
        }
        b[i][j]=1;          //mark the position as visited
        printf("%d\t",a[i][j]);
        i=i1;               //new i corresponding to minimum difference
        j=j1;               //new j corresponding to minimum difference
        sum+=diff;
        if(i==n&&j==n){     //destination position of array
            printf("%d\t",a[i][j]);
            break;
        }
    }
    printf("\nSum is %d\n",sum);
    return 0;
}
