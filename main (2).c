
#include <stdio.h>


int main ()
{
    int count = 0;
    int n;
    scanf ("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int x4 = 0;
    for(int i = 0; i< n ;i++){
        if(a[i] == 1){
            x1++;
        }
        else if(a[i] == 2){
            x2++;
        }
        else if(a[i] == 3){
            x3++;
        }
        else{
            x4++;
        }
    }
    //printf("%d-%d-%d-%d\n",x1,x2,x3,x4);
    count = x4;
    if(x3 == x1 ){
        count = count + x3;
        x3 = 0;
        x1 = 0;
    }
    else if(x3 > x1){
        count = count + x3;
        x1 = 0;
    }
    else if(x3 < x1){
        count = count + x3;
        x1 = x1 - x3;
    }
    //printf("%d-%d-%d\n",x1,x3,count);
    count = count + (x2 /2);
    x2 = x2 %2;
    if(x2 > 0 ){
        if(x1 > 2){
            x1 = x1 - 2;
            count++;
        }
        else if(x1 >=0){
            x1 = 0;
            count++;
        }
    }
    //printf("%d-%d-%d\n",x1,x2,count);
    count = count + (x1 / 4);
    if(x1 % 4 > 0){
        count++;
    }
    
//18                                                                                                                                            
//2 3 4 2 2 1 4 2 4 1 2 3 2 1 1 2 3 4  
    printf ("%d", count);
    return 0;
}
