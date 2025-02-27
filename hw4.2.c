/*************************************************************
 *                                                           *
 * HW04 Q2                                                   *
 * Student Name: ......                                      *
 * Student ID  : ......                                      *
 * Date        : ......                                      *
 * Points      : Write points what you believe to deserve    *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "C:/Users/Rana/Desktop/RecievedMessage.txt"
#define ENCODEDFILE "C:/Users/Rana/Desktop/EncodedInput.txt"
#define CRYPTEDINPUT "C:/Users/Rana/Desktop/CryptedInput.txt"

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads encrypted text and creates encoded and              *
 * plain text files                                          *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	FILE *f_plain_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if encrypted text file could not be opened to read */

	/* exit program and print error if encoded text file could not be opened to write */
    f_crypted_ptr=fopen(CRYPTEDINPUT, "r");
    f_encoded_ptr=fopen(ENCODEDFILE, "w");
    
    if(f_crypted_ptr == NULL)
    {
         printf("ERROR, ENCRYPTED TEXT COULD NOT BE OPENED.");
         
         }
    if(f_encoded_ptr == NULL)
    {
         printf("ERROR, ENCODED TEXT FILE COULD NOT BE OPENED TO WRITE.");
         
         }
    
	decrypt_message(f_crypted_ptr, f_encoded_ptr);

	/* close encrypted and encoded files */

	/* exit program and print error if plain text file could not be opened to write */

	/* exit program and print error if encoded text file could not be opened to read */
     fclose(f_crypted_ptr);
     fclose(f_encoded_ptr);
     
     f_encoded_ptr=fopen(ENCODEDFILE, "r");
     f_plain_ptr=fopen(PLAINTEXTFILE, "w");
     
     if(f_encoded_ptr == NULL )
     {
          printf("ERROR, ENCODED TEXT FILE COULD NOT BE OPENED TO READ.");
          
          }
     if(f_plain_ptr == NULL)
     {
          printf("ERROR, PLAIN TEXT FILE COULD NOT BE OPENED TO WRITE.");

          }
    
    
	decode_message(f_encoded_ptr, f_plain_ptr);

	fclose(f_encoded_ptr);
    fclose(f_plain_ptr);


    system("PAUSE");
	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{

	/* Hint: Use switch case while encoding character 
	 *		 According to number_of_ones write character 
	 *		 to file
	 */
	char character;
	switch(number_of_ones)
	{
        case 0: character = 'E';
        break;
        case 1: character = 'I';
        break;
        case 2: character = ' ';
        break;
        case 3: character = 'T';
        break;
        case 4: character = 'C';
        break;
        case 5: character = 'N';
        break;
        case 6: character = 'A';
        break;
        case 7: character = 'G';
        break;
        case 8: character = 'B';
        break;
        case 9: character = 'Z';
        break;
        case 10: character = 'H';
        break;
        case 11: character = 'L';
        break;
        case 12: character = 'U';
        break;
        case 13: character = 'V';
        break;
        case 14: character = 'R';
        break;
        case 15: character = 'S';
        break;
        case 16: character = 'Y';
        break;
        }
        fprintf(f_out_ptr, "%c", character);                   
                          

}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: While reading from encoded text file keep reading 
	 *		 character by character. Use ASCII difference from 0
	 *		 to determine number is 0 or 1. If we try reading it
	 *		 as integer, it overflows. Overflow is bad if you are 
	 *		 not hacker and do not want to crash system deliberately.
	 *		 Call decode_and_write_to_file function when you detect 0.
	 *
	 */
	
	int counter = 0;
    char character;
                
    while(fscanf(f_in_ptr, "%c", &character)!= EOF)  /* fscanf fonksiyonu eof ile kontrol edilmeli!!!! */
    {
            if(character == '1')
            {
                 counter++;
                 }
            else if(character == '0')
            {
                 decode_and_write_to_file(f_out_ptr, counter);  /* burda çaððrýyý hatalý yapmýþtým, düzelttim , parametreler eksikti */
                 counter=0;
                 }
            }
 

	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: While reading from encrypted text file check if character 
	 *		 equals to '*' or '_' and write to file 1 or 0
	 *
	 */

	int counter = 0;
	char character;
	
	while(fscanf(f_in_ptr,"%c",&character)!= EOF)
    {
          if(character == '*')
          {
               fprintf(f_out_ptr,"1");
               }
          else if( character == '_')
          {
               fprintf(f_out_ptr, "0");
               }  
            counter++;
            }

	return counter;
}
