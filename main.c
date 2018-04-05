/** This Program takes 2 numbers from user
/*  And Return the Result and Remainder from 4 functions implemented with 4 different ways
/*  Then Print the output form each function  */

/* First way is to create Array and return pointer to this array
   Second way is to create dynamic allocated array and return pointer to its location
   Third way is to create structure and return pointer to this structure
   Fourth way is to create structure and return its values and receive it in a new structure
*/

#include <stdio.h>
#include <stdlib.h>

struct num{
    int result,remainder;
};

int* a(int,int); // Function Returns a Pointer to Array of Integers .
int* d(int,int); //Function Returns a pointer to a dynamic allocated array of Integers

struct num *b(int,int); // Function Returns a Pointer to Structure  .
struct num c(int,int); // Function Returns a structure data which has been saved in temp memory .

int main()
{
    int x,y,*ptr,*p;//ptr is a pointer will be used for the normal array
                    //p will be used for the dynamic allocated one 
                    
    struct num *sptr; // sptr is a pointer to structure of size num ;
    
    printf("Enter The Dividend\n");
    scanf("%d",&x);
   
    printf("Enter The Divisor\n");
    scanf("%d",&y);

    ptr=a(x,y); // function returns pointer to array
    printf("Result= %d , Remainder= %d\n",ptr[0],ptr[1]);

    sptr=b(x,y); //function returns pointer to structure
    printf("Result= %d , Remainder= %d\n",sptr->result,sptr->remainder);

    struct num temp;// an Instance from structure num
    temp=c(x,y);// the temp will hold the data received from the function
    printf("Result= %d , Remainder= %d\n",temp.result,temp.remainder);

    p=d(x,y);//pointer to the dynamic allocated array.
    printf("Result= %d , Remainder= %d\n",p[0],p[1]);

    return 0;
}

int* a(int x,int y){
    int arr[2]={x/y,x%y};
    return arr;
}

struct num* b(int x,int y){
    struct num m={x/y,x%y};
    return &m;}

struct num c(int x,int y){
    struct num m={x/y,x%y};
    return m;}

int* d(int x,int y){
    int *p=(int*)malloc(2*sizeof(int));
    p[0]=x/y;
    p[1]=x%y;
    return p;
}
