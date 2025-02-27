#include <stdio.h>
#include <stdlib.h>



typedef enum {
        TRUE=1,
        FALSE=0
        } bool;


int max_array(int array[], int n);
int second_max_array(int array[], int n);
int sum_all_array(int array[], int n);
int count_array(int array[], int n, int value);
bool search_array(int array[], int n, int value);


int main(int argc, char *argv[])
{
    int my_array[]={3,6,4,13,5,6,13,37};
    printf("+++++++++++\n");
    printf("Maximum array is %d\n", max_array(my_array,8));
    printf("+++++++++++\n");
    printf("Second maximum array is %d\n", second_max_array(my_array,8));
    printf("+++++++++++\n");
    printf("Sum of all array is %d\n", sum_all_array(my_array,8));
    printf("+++++++++++\n");
    printf("Count of number 6 is %d\n", count_array(my_array,8,6));
    printf("Count of number 13 is %d\n", count_array(my_array,8,13));
    printf("+++++++++++\n");
    search_array(my_array,8,37);
    search_array(my_array,8,4);
    
  system("PAUSE");	
  return 0;
}





int max_array(int array[], int n)
{
  int i,max=array[0];
  for(i=1;i<n;i++)  
  {
    if(array[i]>=max)                
    max=array[i];
    }
    return max;
}




int second_max_array(int array[], int n)
{
    int second_max=array[0];
    int i,max= max_array(array,n);
    for(i=0;i<n;i++)
    {
       if(array[i]< max_array(array,n) && array[i]>second_max)
       second_max=array[i];             
     }
    
    return second_max;
}


int sum_all_array(int array[], int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum+=array[i];           
    }
    return sum;
    
}


int count_array(int array[], int n, int value)
{
    int i,counter=0;
    for(i=0;i<n;i++)
    {
        if(array[i]== value)
        counter++;           
                     }
    return counter;
}

bool search_array(int array[], int n, int value)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(array[i]== value)
        {
              printf("%d is at [%d]\n", value,i); 
              return TRUE; 
        }            
    } 
   
          printf("%d is not found\n", value);
          return FALSE;

}
