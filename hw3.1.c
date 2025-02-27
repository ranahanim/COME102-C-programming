#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int RNG();
int WarnThePlayer();
int CalculateTheDifference();


int main()
{
  char choice;
  printf("---Welcome to the Guessing An Integer Game---\n ---Press p to play or press e to exit:\n");
  scanf("%c",&choice);
  while(choice!='e')
  {
  if(choice=='p')
  {
    WarnThePlayer();
    printf(" Press 'p' to play, or for exit press 'e'\n");
    scanf("%c",&choice);
 }  
  else{
    printf("Try again.\n");
    printf(" Press 'p' to play, or for exit press 'e'\n");
    scanf("%c",&choice);
       }
    printf("Program was ended\n");

  system("PAUSE");	
  return 0;
}

int WarnThePlayer()
{
  int guess;
  int number;
  number=RNG();
  
  while(1)
  {
  printf("Enter your guess\n");
  scanf("%d",&guess);
  
  
  
   if(CalculateTheDifference(guess,number)>=5)
     printf("You're too far from the number\n");
   
     
     else if(CalculateTheDifference(guess,number)>=3 && CalculateTheDifference(guess,number)<5)
     printf("You're far from the number\n");
   
     
     else if(CalculateTheDifference(guess,number)<=2 && CalculateTheDifference(guess,number)>0)
     printf("You're close to the number\n");
     
     

     else if(CalculateTheDifference(guess,number)==0)  
     {
     printf("Congrats, you  found the number!");
    return 0;
   }   
  }
}
    
    
int RNG()
{
    int number;
    srand(time(NULL));
    number=(rand()%10)+1;
    return number;
} 

int CalculateTheDifference(int guess, int number)
{
    int temp;
    temp=abs(guess-number);
    return temp;
    }



