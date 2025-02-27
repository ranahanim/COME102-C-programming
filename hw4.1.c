
#include <stdio.h>

#define PLAINTEXTFILE "C:/Users/Rana/Desktop/PlainMessagesToSent.txt"
#define ENCODEDFILE "C:/Users/Rana/Desktop/EncodedMessages.txt"
#define CRYPTEDFILE "C:/Users/Rana/Desktop/CryptedMessages.txt"

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void encode_and_write_to_file(FILE *f_out_ptr, char character);

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return encoded character number                           *
 *************************************************************/
int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads plane text, creates encoded and crypted text files  *
 *************************************************************/
int main(int argc, char* argv[])
{
	FILE *f_plain_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if plain text file could not be opened to read */

	/* exit program and print error if encoded text file could not be opened to write */
    f_plain_ptr=fopen(PLAINTEXTFILE, "r");
    f_encoded_ptr=fopen(ENCODEDFILE, "w");
    
   
    if(f_plain_ptr == NULL)
    {
       printf("ERROR, PLAIN TEXT FILE COULD NOT BE OPENED.");
       return 1; /* hata return deðeri */
      }
    
    if(f_encoded_ptr == NULL)
    {
       printf("ERROR, ENCODED TEXT FILE COULD NOT BE CREATED.");  
      return 1;  /* hata return deðeri */
      }
  
	encode_message(f_plain_ptr, f_encoded_ptr);

	/* close plain and encoded files */

	/* exit program and print error if crypted text file could not be opened to write */

	/* exit program and print error if encoded text file could not be opened to read */

     fclose(f_plain_ptr);
     fclose(f_encoded_ptr);
     
     f_crypted_ptr=fopen(CRYPTEDFILE, "w");
     f_encoded_ptr=fopen(ENCODEDFILE, "r");
     
     if(f_crypted_ptr == NULL)
     {
          printf("ERROR, CRYPTED TEXT FILE COULD NOT BE OPENED.");
          return 1;
       }
 
     if(f_encoded_ptr == NULL)
     {
          printf("ERROR, ENCODED TEXT FILE COULD NOT BE CREATED.");
          return 1;
          }


	crypt_message(f_encoded_ptr, f_crypted_ptr);
    fclose(f_crypted_ptr);
    fclose(f_encoded_ptr);
    
	/* close crypted and encoded files */
    system("PAUSE");
	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void encode_and_write_to_file(FILE *f_out_ptr, char character)
{

	/* Hint: Use switch case while encoding character 
	 *		 Keep number of 1s and use it in a loop to
	 *		 write to file encoded value. You are going to
	 *		 call fprintf in the loop just number of 1s times
	 *		 Do not forget adding 0 at the end of value
	 */
	int numberOfOnes;
	int i;
	switch(character)
	{
     case 'E' : 
          numberOfOnes=0; break;
     case 'I' : 
          numberOfOnes=1; break;
     case ' ' : 
          numberOfOnes=2; break;
     case 'T' : 
          numberOfOnes=3; break;
     case 'C' : 
          numberOfOnes=4; break;
     case 'N' : 
          numberOfOnes=5; break;
     case 'A' : 
          numberOfOnes=6; break;
     case 'G' : 
          numberOfOnes=7; break;
     case 'B' : 
          numberOfOnes=8; break;
     case 'Z' : 
          numberOfOnes=9; break;
     case 'H' : 
          numberOfOnes=10; break;
     case 'L' : 
          numberOfOnes=11; break;
     case 'U' : 
          numberOfOnes=12; break;
     case 'V' : 
          numberOfOnes=13; break;
     case 'R' : 
          numberOfOnes=14; break;
     case 'S' : 
          numberOfOnes=15; break;
     case 'Y' : 
          numberOfOnes=16; break;
     
          default: printf("*** %c is CAN'T be used ***" , character);
                    
                     }
          for(i=1;i<numberOfOnes;i++) 
          {
                fprintf(f_out_ptr, "1");
                }
          fprintf(f_out_ptr, "0");      

}

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: Keep reading from plain text until end of file
	 *		 while reading per character call encode_and_write_to_file
	 *		 function.
	 */
	 int counter = 0;
	 char character;
	 
	 while(fscanf(f_in_ptr,"%c",&character)!= EOF)
	 {
           encode_and_write_to_file(f_out_ptr,character);
           counter++;
            }

	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/
int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: Keep reading from encoded text until end of file
	 *		 while reading per character check if it is equal 
	 *		 to 1 or 0 and according to character write file '*'
	 *		 '_'
	 *		 Do not forget adding '-' character to proper places
	 *       Check sample encrypted messages and read objective 3
	 *
	 */
	int counter = 0;
	
	char number;
	int i=0;
	int n=5;
	
	while(fscanf(f_in_ptr,"%c",&number)!= EOF)  /*bunu anlamadým EOF nedir? */  
    {
                                         
          if(number == '1')
          {
               fprintf(f_out_ptr,"%c",'*');
               }
          else if(number == '0')
          {
               fprintf(f_out_ptr, "_");
               }   
          counter++;
          
          
          if(counter == n)
          {
            fprintf(f_out_ptr,"-");
            counter=0;
            n--;
            i=0;
            if(n<5){
            n=5;
            
            }
          }  
        }
	


	return counter;
}
