#include <iostream>
#include <cstddef>
#include <cstring>

class Rule_of_three
{
	char* cstring;

	Rule_of_three( const char* s, std::size_t n ) 
		: cstring( new char[n] )
	{
		std::memcpy( cstring, s, n );
	}

public:
	// Ctor
	Rule_of_three( const char* s = "" )
		: Rule_of_three( s, std::strlen(s) + 1)
	{}

	// Copy constructor
	Rule_of_three(const Rule_of_three& i_other)
		: Rule_of_three(i_other.cstring)
	{}

	// Destructor
	~Rule_of_three()
	{
		delete[] cstring;
	}

	// Copy assignment
	Rule_of_three& operator=( const Rule_of_three& i_other )
	{
		if ( this == &i_other )
		{
			return *this;
		}

		std::size_t n{ std::strlen(i_other.cstring) + 1 };

		char* new_cstring = new char[n];

		std::memcpy(new_cstring, i_other.cstring, n);

		delete[] cstring;
		cstring = new_cstring;
		
		return *this;
	}

public:
	operator const char* () const { return cstring; }
};


int main()
{
	Rule_of_three o1( "abc" );
	std::cout << o1 << std::endl;

	auto o2( o1 ); // use copy constructor

	std::cout << o2 << std::endl;

	Rule_of_three o3("def");

	std::cout << o3 << std::endl;

	o3 = o2; // use copy assignment

	std::cout << o3 << std::endl;

	std::cin.get();
}