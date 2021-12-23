#include <bitset>
#include <iostream>
#include "main.h"


int main(int argc, char **argv)
{    
	bool b = true;
	void *ptr = &b;	
	//print bool
	PrintBinary(ptr, sizeof(b));

	char c = 0xAA;
	ptr = &c;	
	//print char
	PrintBinary(ptr, sizeof(c));

	int a = 255;
	ptr = &a;	
	//print int
	PrintBinary(ptr, sizeof(a));
	
	float f = 34543.9485;
	ptr = &f;
	//print float
	PrintBinary(ptr, sizeof(f));
	
	double d = 34543.9485;
	ptr = &d;
	//print double
	PrintBinary(ptr, sizeof(d));	

	return 0;
}

void PrintBinary(void* ptr, size_t size){
	
	std::cout <<"\n\n\nPrint bits of variable with size:"<< size <<std::endl;
	
	for (int i=(int)(size-1); i >= 0; i--){
		std::cout << std::bitset<BYTE_SIZE>(*(int8_t *)(ptr+i));
		
	}
	
}