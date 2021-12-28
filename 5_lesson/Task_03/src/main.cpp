#include <iostream>


void MyPrintf(const char *symbol){
	while (*symbol){
		if (*symbol == '%'){
			if (*(symbol + 1) == '%'){
				++symbol;
			}
		}
		std::cout << *symbol++;		
	}
	
}
template <typename T, typename... Args>
void MyPrintf(const char *symbol, const T value, Args... args){
	while (*symbol){
		if (*symbol == '%'){
			if (*(symbol + 1) == '%'){
				++symbol;
			}
			else {
				std::cout<<value;
				MyPrintf(symbol + 1, args...);
				return;
			}
		}
		std::cout << *symbol++;
	}
	
}


int main(int argc, char **argv)
{    
	MyPrintf("Year:%, Name:%, Size:%", 1992, "Bob", 123.58);	

	return 0;
}

