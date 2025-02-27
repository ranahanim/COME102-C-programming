#include <stdio.h>
#include <stdlib.h>
#define PERCENTAGE1 0.3
#define PERCENTAGE2 0.3
#define PERCENTAGE3 0.4


int ResultingGrade(int x,int y,int z);
char LetterGrade(int a);
double Contribution(char a);

int main()
{
  
  char Name1,Name2,Name3,Name4,Name5;
  char Surname1,Surname2,Surname3,Surname4,Surname5;
  
  int Midterm1_S1,Midterm1_S2,Midterm1_S3,Midterm1_S4,Midterm1_S5;
  int Midterm2_S1,Midterm2_S2,Midterm2_S3,Midterm2_S4,Midterm2_S5;
  int Final_S1,Final_S2,Final_S3,Final_S4,Final_S5;
  
  int Grade1,Grade2,Grade3,Grade4,Grade5;
  char LetterGrade1,LetterGrade2,LetterGrade3,LetterGrade4,LetterGrade5;
  double Contribution1,Contribution2,Contribution3,Contribution4,Contribution5;
  
  FILE*input;
  FILE*output;
  
  input=fopen("C:/Users/Rana/Desktop/Students.txt","r");
  output=fopen("C:/Users/Rana/Desktop/Grades.txt","w");
  
  fscanf(input,"%c%c %d %d %d \n", &Name1,&Surname1,&Midterm1_S1,&Midterm2_S1,&Final_S1);
  fscanf(input,"%c%c %d %d %d \n", &Name2,&Surname2,&Midterm1_S2,&Midterm2_S2,&Final_S2);
  fscanf(input,"%c%c %d %d %d \n", &Name3,&Surname3,&Midterm1_S3,&Midterm2_S3,&Final_S3);
  fscanf(input,"%c%c %d %d %d \n", &Name4,&Surname4,&Midterm1_S4,&Midterm2_S4,&Final_S4);
  fscanf(input,"%c%c %d %d %d \n", &Name5,&Surname5,&Midterm1_S5,&Midterm2_S5,&Final_S5);
  
  Grade1=ResultingGrade(Midterm1_S1,Midterm2_S1,Final_S1);
  Grade2=ResultingGrade(Midterm1_S2,Midterm2_S2,Final_S2);
  Grade3=ResultingGrade(Midterm1_S3,Midterm2_S3,Final_S3);
  Grade4=ResultingGrade(Midterm1_S4,Midterm2_S4,Final_S4);
  Grade5=ResultingGrade(Midterm1_S5,Midterm2_S5,Final_S5);
  
  LetterGrade1=LetterGrade(Grade1);
  LetterGrade2=LetterGrade(Grade2);
  LetterGrade3=LetterGrade(Grade3);
  LetterGrade4=LetterGrade(Grade4);
  LetterGrade5=LetterGrade(Grade5);
  
  Contribution1=Contribution(LetterGrade1);
  Contribution2=Contribution(LetterGrade2);
  Contribution3=Contribution(LetterGrade3);
  Contribution4=Contribution(LetterGrade4);
  Contribution5=Contribution(LetterGrade5);
  
  
  fprintf(output,"%c%c %d \n", Name1,Surname1,Grade1);
  fprintf(output,"%c%c %d \n", Name2,Surname2,Grade2);
  fprintf(output,"%c%c %d \n", Name3,Surname3,Grade3);
  fprintf(output,"%c%c %d \n", Name4,Surname4,Grade4);
  fprintf(output,"%c%c %d \n", Name5,Surname5,Grade5);
  
  printf("The contribution of %c%c is %.2f \n",Name1,Surname1,Contribution1);
  printf("The contribution of %c%c is %.2f \n",Name2,Surname2,Contribution2);
  printf("The contribution of %c%c is %.2f \n",Name3,Surname3,Contribution3);
  printf("The contribution of %c%c is %.2f \n",Name4,Surname4,Contribution4);
  printf("The contribution of %c%c is %.2f \n",Name5,Surname5,Contribution5);
  
  
  fclose(input);
  fclose(output);

  
  system("PAUSE");	
  return 0;
}


  int ResultingGrade(int a ,int b, int c)
{
   int temp;
   temp=(PERCENTAGE1*a)+(PERCENTAGE2*b)+ (PERCENTAGE3*c);
   return temp;
}

 char LetterGrade(int a)
{
      char temp;
      if(a>=85){
         temp='A'; 
         }
      else if (a<85 && a>=70){
         temp='B';
         }
      else if(a<70 && a>=65){
         temp='C';
         }
      else if(a<65 && a>=40){
         temp='D';
         }
      else{
         temp='F';
         }
 return temp;
}

 double Contribution(char a)
{   
    
    int temp;
    double average;
    
    switch(a){
    case 'A': temp=4;
         break;
    
    case 'B': temp=3;
         break;
    
    case 'C': temp=2;
         break;
    
    case 'D': temp=1;
         break;
         }
         
        
    average=(3.0*temp)/20;
    return average;
    }

   






















