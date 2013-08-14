#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
#include <math.h>

int SIZE = 100000000/8; /* 10^7 bits*/

void 
raw_display(unsigned char *vector)
{
  unsigned char mask;
  int i,j;
  for (i = SIZE-1; i>=0; i--) {
    /* printf("(%d)",i); */
    for (j = 7; j>=0; j--) {
      mask = 1<<j;
      if (vector[i] & mask)
        printf("1");
      else
        printf("0");
    }
    printf(" ");
  }
  printf("\n");
}


void 
display(unsigned char *vector,unsigned int n)
{
  unsigned char mask;
  int i,j;
  int num = 0;
  
  for (i = SIZE-1; i>=0; i--) {
    for (j = 7; j>=0; j--) {
      mask = 1<<j;
	
      if (vector[i] & mask || (i==SIZE-1 && j==7) || (i==SIZE-1 && j==6))
	{}
	else       
	{
	if(num<n) printf("%d\n",num);}
      num ++;
 }
  }
}


void
set(unsigned char *vector, int number)
{
  int byte;
  int bit;
  assert (number < SIZE * 8); /* The number we set shouldn't be more
                                 than the number of bits */
  byte = (SIZE - 1) - (number / 8);
  bit = 7 - number % 8;
  /* printf("Setting bit %d of byte %d to 1\n", bit, byte); */
  
  vector[byte] = vector[byte] | 1<<bit;
}

void
unset(unsigned char *vector, int number)
{
  int byte;
  int bit;
  assert (number < SIZE * 8); /* The number we set shouldn't be more
                                 than the number of bits */
  byte = (SIZE - 1) - (number / 8);
  bit = 7 - number % 8;
  /* printf("Unsetting bit %d of byte %d to 1\n", bit, byte); */
  
  vector[byte] = vector[byte] & (~(1<<bit));
}


int
main(int argc,const char ** argv)
{
  unsigned int n,i;

  
  unsigned char *vector = (unsigned char *)malloc(SIZE); /* SIZE is int 10000000 == 10^7 */
  bzero(vector, SIZE);
    
  
  n=atoi(argv[1]);
     for(i=2;i<n;i++)
	if(vector[i]==0)
		{
		int j=2;
		int k=1;
		while(k<=n)
		{
			set(vector,i*j);
			j=j+1;
			k++;
		}
	}
	
 
  display(vector,n);
  
  free(vector);
  return 0;
}
