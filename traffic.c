#include <lpc214x.h>
unsigned int delay;
void dcr();
void buzzr();
void buzz();
void green(int,int,int,int,int,int,int,int,int,int,int,int);
void yellow(int,int,int,int,int,int,int,int,int,int,int,int);
int x;



int main(void)
{
 dcr();
	
while(1)
		{
 green(6,7,9,10,12,13,14,15,5,8,11,16);
 yellow(5,7,9,10,12,13,14,15,8,11,6,16);
 green(5,6,9,10,12,13,15,16,8,11,14,7);
 yellow(5,6,8,10,12,13,15,16,11,14,7,9);
 green(6,7,8,9,12,13,15,16,5,11,14,10);
 yellow(6,7,8,9,11,13,15,16,5,14,10,12);
 green(6,7,9,10,11,12,15,16,5,8,14,13);
 yellow(6,7,9,10,11,12,14,16,5,8,13,15);
 buzzr();
 
	}
} 




 void green(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l)
 {
  
 IO0DIR |= (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7) | (1<<8) | (1<<9) | (1<<10) | (1<<11) | (1<<12) | (1<<13) | (1<<14) | (1<<15) | (1<<16) | (1<<19);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<19); 
 IO0SET = (1<<i) | (1<<j) | (1<<k) | (1<<19);
	 
  for(x=1;x<=10;x++)
  {
  IO0CLR = (1<<a) | (1<<b) | (1<<c) | (1<<d) | (1<<e) | (1<<f) | (1<<g) | (1<<h); 
  IO0SET = (1<<l) | (1<<19);
  for(delay=0; delay<1000000; delay++);
  IO0CLR = (1<<l) | (1<<19);
  for(delay=0; delay<1000000; delay++);
		
  }
	
 }
 
  
 void yellow(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l)
 {
  
 IO0DIR |= (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7) | (1<<8) | (1<<9) | (1<<10) | (1<<11) | (1<<12) | (1<<13) | (1<<14) | (1<<15) | (1<<16) | (1<<20);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<20); 
 IO0SET = (1<<i) | (1<<j) | (1<<20);
	 
  for(x=1;x<=2;x++)
  {
  IO0CLR = (1<<a) | (1<<b) | (1<<c) | (1<<d) | (1<<e) | (1<<f) | (1<<g) | (1<<h); 
    IO0SET = (1<<k) | (1<<l) | (1<<20);
  for(delay=0; delay<1000000; delay++);
    IO0CLR = (1<<k) | (1<<l) | (1<<20);
  for(delay=0; delay<1000000; delay++);
		
  }
	
 }
 
 
 
  void dcr()
 {
	int i=0;
	int r=7;
	int s=8;
	int p=0;
	int k=15;
	int m,n;
	 
	IO0DIR |= (1<<4) | (1<<10) | (1<<1) | (1<<8) | (1<<3) | (1<<9) | (1<<2) | (1<<7) | (1<<0) | (1<<6) | (1<<5) | (1<<11) | (1<<12) | (1<<13) | (1<<14) | (1<<15);
  
	 for(m=0;m<8;m++)
	 {
		 
		 IO0CLR |= (1<<i) | (1<<k);
		 for(delay=0; delay<500000; delay++);
		 IO0SET |= (1<<i) | (1<<k);
		 for(delay=0; delay<500000; delay++);
		 i=++i;
		 k=--k;
	 }
	 
	 buzz();
	 IO0DIR |= (1<<4) | (1<<10) | (1<<1) | (1<<8) | (1<<3) | (1<<9) | (1<<2) | (1<<7) | (1<<0) | (1<<6) | (1<<5) | (1<<11) | (1<<12) | (1<<13) | (1<<14) | (1<<15);

	 for(n=0;n<8;n++)
	 {
		 IO0CLR |= (1<<r) | (1<<s);
		 for(delay=0; delay<500000; delay++);
		 IO0CLR |= (0<<r) | (0<<s);
		 for(delay=0; delay<500000; delay++);
     r=--r;
		 s=++s;
	 }
	 
	 buzz();
 }
	 
 
 
 void buzz(){
 IO0DIR = (1<<20);
  IO0CLR = (1<<20);
  for(delay=0; delay<500000; delay++);
  IO0SET = (1<<20);
  for(delay=0; delay<500000; delay++);
	IO0CLR = (1<<20);
	IO0SET = (0<<20);
	IO0DIR = (0<<20);
  }
 
	
	
  void buzzr(){
 IO0DIR = (1<<20);
  IO0CLR = (1<<20);
  for(delay=0; delay<5000000; delay++);
  IO0SET = (1<<20);
  for(delay=0; delay<5000000; delay++);
	IO0CLR = (1<<20);
	IO0SET = (0<<20);
	IO0DIR = (0<<20);
  }
