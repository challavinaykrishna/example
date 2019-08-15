#include	<stdio.h>



#define test_bit(num,pos) (num & 1<<pos)?1:0


void print_bits(int num){

	int i;
int k;

	for(i =sizeof(int)*8 -1 ; i >= 0 ;--i){
		
		(num & 1<<i)?printf("1"):printf("0");
		
		if(i%8 == 0)
			printf(" ");
	}

	printf("\n");
}

//swapping bits in a number
void swap_s_d(int num ,int s,int d){

	if(!(num & 1<< s) != !(num & 1<<d))
		num = (num^(1<<s))^(1<<d); 

	printf("bits swapped\n");
	print_bits(num);
}


//swapping bints bwn 2 nos 
void swap_bwn_2nos(int num1,int num2 ,int s ,int d){

	printf("before\n");

	printf("num1 is\n");
	print_bits(num1);
	printf("num2 is\n");
	print_bits(num2);

	if(!(num1 & 1<<s) != !(num2 & 1<<d)){
	
		num1 = num1^(1 << s);
		num2 = num2^(1 << d);	

	}

	printf("after swapping\n");
	printf("num1 is\n");
	print_bits(num1);
	printf("num2 is\n");
	print_bits(num2);


}


/*
Write a function bit_copy (int snum, int dnum, int n, int s, int d) which copies n bits (right
adjusted) from bit position s in snum to bit position d in dnum.	
*/
void cpy_nbits(unsigned int snum ,unsigned int dnum,int n,int s,int d){

	if(s-n >= -1 && d-n >= -1){
		if(s < d)
			dnum = dnum & ~(~(~0U << n)<< (d+1-n)) | (snum &~(~0U << n)<<(s+1-n))<<(d-s);
		else
			dnum = dnum & ~(~(~0U << n)<< (d+1-n)) | (snum &~(~0U << n)<<(s+1-n))>>(s-d);
			
	}
	else 
		printf("wrong inputs\n");

	print_bits(snum);
	print_bits(dnum);


}

void bits_toggled(int num){

	int mask;
	int i = 0;
	
	for(i = 1; i < sizeof(int)*8 ;i = i+2)
		mask = mask|1<<i;


	printf("number is \n");
	print_bits(num);
	printf("odd bits toggled\n");
	print_bits(num^mask);
	printf("even bits toggled\n");
	print_bits(num^(~mask));


}

void left_rot_n_bits(unsigned int num,int n){

	unsigned int mask ;
	
	mask = ~(~0U <<n) << (sizeof(int)*8-n);
	print_bits(mask);
	num = ((num&mask)>>(sizeof(int)*8 -n))|num<<n;
	
	print_bits(num);
}



void right_rot_n_bits(unsigned int num,int n){

	unsigned int mask = ~(~0U<<n);
	num = (num&mask)<<(sizeof(int)*8 -n) |num >>n;
	print_bits(num);	

}

int  count_bits_set(int num ){

	print_bits(num);


	int i = 0;

	while(num ){
		i++;
		num = num&(num -1);
	}

	printf("num of bits set is = %d \n",i);

	return i;
}


int  count_bits_clear(int num ){

	return sizeof(int)*8 - count_bits_set(num);
}	
	
int main(void){

	int num = 10;

//	print_bits(num);

//	swap_s_d(num,1,12);
/*
	int num1 = 4;
	int num2 = 0;
	
	swap_bwn_2nos(num1,num2,2,3);
*/

//	cpy_nbits(255,0,8,7,10);
//	bits_toggled(12);

//	printf( "res is %d\n",test_bit(num,3));
	
//	print_bits(939293949);

//	left_rot_n_bits(939293949,1);

//	right_rot_n_bits(939293949,4);
	
	count_bits_set(2345234);
	
	printf("%d\n",count_bits_clear(2345234));



	return 0;
}

