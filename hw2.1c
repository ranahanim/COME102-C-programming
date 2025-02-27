#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int x;
int y;

int CalculateTheDifference(int x,int y);
int RNG();
void WarnThePlayer(int x,int y);

int main()
{
  int number;
  int guess;
  
  printf("----Welcome to Guessing Game----\n Let's try your first chance with a number between 1 to 10!\n");
  scanf("%d", &guess);
  
  
  number=RNG();
  
  WarnThePlayer(guess,number);
  
  if(CalculateTheDifference(guess,number)!= 0)
  {
  printf("Please try again.\n");
  scanf("%d", &guess);
  
  WarnThePlayer(guess,number);
}

  if(CalculateTheDifference(guess,number)!= 0)
  {
     printf("You couldn't find the number. The number was: %d\n", number);
}         
   while(1);                                   
   return 0;
}


int RNG()
{
    int number;
    srand(time(NULL));
    number=(rand()%10)+1;
    return number;
}


int CalculateTheDifference(int x,int y)
{
    int temp;
    temp=abs(x-y);
    return temp;
}


void WarnThePlayer(int x,int y)
{
     if(CalculateTheDifference(x,y)>=5)
     {
     printf("You're too far from the number\n");
     }
     
     else if(CalculateTheDifference(x,y)>=3 && CalculateTheDifference(x,y)<5)
     {
     printf("You're far from the number\n");
     }   
     
     else if(CalculateTheDifference(x,y)<=2 && CalculateTheDifference(x,y)>0)
     {
     printf("You're close to the number\n");
     }
     

     else if(CalculateTheDifference(x,y)==0)
     {
     printf("Congrats, you  found the number!");
    }
     return ;
}

     


