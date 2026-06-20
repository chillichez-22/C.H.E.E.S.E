#include "math.hpp"
#include "shape.hpp"

// Tests
#include "vector_test.hpp"

// External
#include <iostream>
#include <SDL3/SDL.h>


// Testing

int HandleTest( bool testCase ){

	if ( testCase ){
		std::cout << "PASSED \n";
	}
	else{
		std::cout << "FAILED \n";
		throw std::logic_error("TEST FAILED");
	}

	return 0;
}

int TestVector2(){

	std::cout << "test Vector2 Adding ";
	HandleTest( testVector2Adding() );

	std::cout << "test Vector2 Subbing ";
	HandleTest( testVector2Subbing() );

	std::cout << "test Vector2 Multiplying ";
	HandleTest( testVector2Multiplying() );

	std::cout << "test Vector2 Division ";
	HandleTest( testVector2Dividing() );

	return 0;
}


int Testing(){

	std::cout << "Testing Started \n\n";

	TestVector2();

	std::cout << "Testing Ended \n";
	return 0;
}

int main() {

	std::cout << "Testing Loaded \n";
	std::cout << "CPP version: " << __cplusplus << "\n";

	Testing();

	std::getchar(); 
	return 0;
}