#include <stdio.h>
#include <stdlib.h>

#define ROADLENGTH 50

typedef enum STATE  
{
        PLAY,
        CRASH,
        END
} object_state ;



void make_move(char *object1, double *position1, double *speed1, int weight1,char *object2, double *position2, double *speed2, int weight2, object_state *game_state);
                
double car_crash_time(double position1, double position2, double speed1, double speed2);        

void print_game_state(char object1, double position1, char object2, double position2, object_state game_state); 




int main()
{
  char name1,name2;
  double speed1,speed2;
  int weight1,weight2;
  double position1=1; /* en basta ilk arac */
  double position2=ROADLENGTH;  /* en sonda diger arac */
  object_state state=PLAY;
  
   printf("Please enter first car name/speed/weight \n");
   scanf(" %c ", &name1);
   scanf("%lf %d", &speed1,&weight1); 
    
   printf("Please enter second car name/speed/weight \n");
   scanf(" %c ", &name2);
   scanf("%lf %d", &speed2,&weight2);
  
  printf("Car 1: %c %.1lf %d \n", name1, speed1, weight1);
  printf("Car 2: %c %.1lf %d \n", name2, speed2, weight2);
  
  make_move(&name1,&position1,&speed1,weight1,&name2,&position2,&speed2,weight2,&state);
  
  
  system("PAUSE");	
  return 0;
}



void make_move(char *object1, double *position1, double *speed1, int weight1,
                char *object2, double *position2, double *speed2, int weight2, object_state*game_state)
{
                
      int i,time; /* carpisacaklari zaman*/      
      double new_speed; /* yeni hizlari ortak kutlenin */
      
      time=car_crash_time(*position1,*position2,*speed1,*speed2);
                
      for(i=0;i<=time;i++)          
      {
            print_game_state(*object1,*object2,*position1,*position2,*game_state);
            
            if(*position2-*position1 > 1)  /*aradaki mesafe 1 olana kadar */
            {
                *position1=*position1+*speed1;
                *position2=*position2+*speed2;                          
            }                 
      }          
             new_speed=((*speed1)*weight1+(*speed2)*weight2)/(double)(weight1+weight2); /*type casting */
             
      
      
                   *game_state=CRASH;                                                                    
                   *object1='X'; /* yeni ortak cisim ismi */
                   
                   
                    
                    do{
                    print_game_state(*object1,*object2,*position1,*position2,*game_state);                                                                 
                    *position1=*position1+new_speed;                                                                   
                    } while(*position1<ROADLENGTH && *position1>0);
               
                
                
                
              *game_state=END;
              *object1='X';
               print_game_state(*object1,*object2,*position1,*position2,*game_state);  
                       
}





double car_crash_time(double position1, double position2, double speed1, double speed2) /* bu fonksiyon carpisacaklari sureyi hesaplar*/
{
       if(speed1=speed2)
         return ROADLENGTH; 
      double temp;
      temp=(position2-position1)/(speed2-speed1);
      return temp;       
}



void print_game_state(char object1, double position1, char object2, double position2, object_state game_state)
{
    int i, j, t, k;     /* dongulerde kullanacagim variablelar*/
    
    int interval=(int)position2-position1-1;   /* aradaki mesafe*/
    
    if(game_state == PLAY)
    {
        for(i=1;i<(int)position1;i++){
            printf("_");
        }
        printf("%c", object1);
        for(j=1;j<interval;j++){
            printf("_");
            }
        printf("%c", object2);
        
        
        for(t=(int)position2; t<ROADLENGTH; t++)
            printf("_");
            
            
        }
    
    else if(game_state == CRASH)
     {
       for(i=1;i<=(int)position1;i++) {          
           printf("_");   
        printf("%c", object1); 
        }         
                      
       for(j=1;j<ROADLENGTH-(int)position1;j++)           
         printf("_");   
       
               
     }
    
    else if(game_state == END)
    {
        for(i=1;i<(int)position1;i++)
        { 
         printf("_");
       } 
       printf("%c", object1);
       for(j=1;j<ROADLENGTH-(int)position1;j++) 
       { 
         printf("_");
         }
    }
    printf("\n");      /* ekrana sayilari bastiracak dongu */
    for(k=1; k<=ROADLENGTH; k++)
    { 
     printf("%d", k%10);
     }        
    printf("\n");
     
}





