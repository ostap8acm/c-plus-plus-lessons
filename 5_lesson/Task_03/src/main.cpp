#include <iostream>

template <typename T, typename... Args>
void printf(const char *symbol, const T value, Args... args){
	while (*symbol){
		if (*symbol == '%'){
			if (*(symbol + 1) == '%'){
				++symbol;
			}
			else {
				std::cout<<value;
				printf(symbol + 1, args...);
				return;
			}
		}
		std::cout << *symbol++;
	}
	
}


int main(int argc, char **argv)
{    
	printf("Year:%, Name:%, Size:%", 1992, "Bob", 123.58);	

	return 0;
}

