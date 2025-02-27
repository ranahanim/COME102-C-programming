#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT_REBOUNCE_HEIGHT 1.0


int RNG_firstHeight();
double RNG_ratio();
double calculate_the_new_height(double ratio, double first_height);
double calculate_the_vertical_distance(double next_height);
int count_the_number();
void report();

int main()
{
    double ratio;
    double first_height;
    double next_height;
    int counter;
    double vertical_distance;
    
    
 ratio=RNG_ratio();
 first_height=RNG_firstHeight();
 vertical_distance=first_height;
 
 
 printf("Ratio = %.2lf\n", ratio);            
 counter=1;
  printf("%d\t", counter);
 
 printf("%.2lf\t", first_height);
 printf("%.2lf\n", vertical_distance);
 
 next_height=ratio*first_height;
 while(next_height>=LIMIT_REBOUNCE_HEIGHT)
 {
  counter=count_the_number(counter);
  printf("%d\t", counter);
  printf("%.2lf\t", next_height);
  vertical_distance+=calculate_the_vertical_distance(next_height);
  printf("%.2lf\n", vertical_distance);
  next_height=calculate_the_new_height(ratio, first_height);
}
 
 
 report(first_height,ratio);
 system("PAUSE");
  return 0;
}

void report(double first_height, double ratio)
{
   FILE*output;
   output=fopen("C://Users//Rana//Desktop//ResultTable.txt", "w");
    
   double next_height;
   int counter;
   double vertical_distance;      
                             
   vertical_distance=first_height;
   
   fprintf(output, "No - The Rebouncing Height - The Total Vertical Distance\n" );
   counter=1;
   fprintf(output, "%d/t/t", counter);
   fprintf(output, "%.2lf/t/t/t/t", first_height);
   fprintf(output, "%.2lf/n",vertical_distance);
   
   next_height=ratio*first_height;
   while(next_height>=LIMIT_REBOUNCE_HEIGHT)
   {
    counter=count_the_number(counter);
    fprintf(output,"%d/t/t",counter);
    fprintf(output,"%.2lf/t/t/t/t",next_height);
    
    vertical_distance+=calculate_the_vertical_distance(next_height);
    fprintf(output,"%.2lf/n",vertical_distance);
    next_height=calculate_the_new_height(next_height,ratio);
          }
     fprintf(output,"Program finished.");
     fclose(output);
     
      system("PAUSE");
     
}



double calculate_the_vertical_distance(double next_height)
{
       double vertical_distance=0;
       vertical_distance=(next_height*2);
       return vertical_distance;
}



double calculate_the_new_height(double ratio, double first_height)
{
       double next_height;
       next_height=ratio*first_height;
       return next_height;
}


int count_the_number(int counter)
{
    counter++;
    return counter;
}


int RNG_firstHeight()
{
    int firstHeight;
    srand(time(NULL));
    firstHeight=(rand()%31)+10;
    return firstHeight;
}

double RNG_ratio()
{
       double ratio;
       srand(time(NULL));
       ratio=((rand()%41)+40.)/100;
       return ratio;
}
