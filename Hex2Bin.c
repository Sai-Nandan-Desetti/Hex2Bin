/* Name:    D.Sai Nandan
   Regd.No: 19006
*/


#include<stdio.h>


//Defining some constants...

//1. Lengths of the instructions in different formats

#define HEX_LEN 6      
#define BIN_LEN 24

//2. Lengts of the various components of an instrucion in binary format

#define OP_LEN 8
#define ADDRESS_LEN 15

//function to convert a decimal to binary...(details are given below)
void Dec2Bin(int,int[],int);


//the 'main' program
void main(){

//Declaring the variables...

     int i;
     unsigned int hex[HEX_LEN],HexOp;
     int BinOp[BIN_LEN];
     int Opcode[OP_LEN];
     int Mode;
     int Address[ADDRESS_LEN];


//Initializing the BinOp and hex arrays...

     for(i=0;i<BIN_LEN;i++)
         BinOp[i]=0;

     for(i=0;i<HEX_LEN;i++)
         hex[i]=0;

//Taking input...

     printf("Enter the hexadecimal instruction: ");
     scanf("%x",&HexOp);


//the 'main' part of the main() function

//loop to obtain the digits of the hexadecimal instruction.
     i=HEX_LEN;
     while(HexOp!=0){

          hex[--i]=HexOp%16;
          HexOp/=16;
     }

//loop to convert the hexadecimal digits to their binary form  
     for(i=0;i<HEX_LEN;i++)
         Dec2Bin((int)hex[i],BinOp,(i+1)*4);   



//Display the output...

//1. Binary form of the instruction.

     printf("Binary representation: ");
     for(i=0;i<BIN_LEN;i++){
         if(i&&i%4==0)
            printf(" ");
         printf("%d",BinOp[i]);
     }
    
     printf("\n");


//2. Opcode.
       
    printf("Opcode: ");
    for(i=0;i<OP_LEN;i++){
        Opcode[i]=BinOp[i];
        printf("%d",Opcode[i]);
    }
    
    printf("\n");


//3. Mode of addressing.
    
    printf("Mode: ");
    Mode=BinOp[OP_LEN];
    if(Mode)
        printf("Indexed\n");
    else
        printf("Not Indexed\n");


//4. The address.
    
    printf("Address: ");
    
    for(i=OP_LEN+1;i<BIN_LEN;i++){
        Address[i-(OP_LEN+1)]=BinOp[i];
        printf("%d",Address[i-(OP_LEN+1)]);
    }

    printf("\n");

} //end of main()



//////////////////////////////////////////////////// FUNCTIONS ////////////////////////////////////////////////////////////////


/*
  Description:

  This function, essentially, converts a decimal number to its binary form.
  But, here, it's written in the context of converting a hexadecimal number to its binary form.
  So each hexadecimal digit is converted to its decimal form and the decimal is then converted to its binary form,
  and the binary forms of successive hexadecimal deigits are appended to the BinOp (or, here, bin) array.


  Pre: dec=decimal number
       bin[]=array to store binary forms
       index=an integer used for appending the resultant binary form (to bin[])

  Post: the function returns void
        bin[] array is updated with the binary form a decimal number
*/

void Dec2Bin(int dec, int bin[], int index){

    while(dec!=0){

         bin[--index]=dec%2;
         dec/=2;
    }
}

