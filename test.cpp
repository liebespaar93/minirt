#include <iostream>
#include <iomanip>

#include "test.hpp"

test::test()
{
	
	
	std::cout << std::setw(15) << "[test] " << "create!!" << std::endl;
}



test::test(const test& ref)
{
	
	
	*this=ref;
	std::cout << std::setw(15) << "[test] " << "copy!!" << std::endl;
}



test::~test()
{
	
	
	std::cout << std::setw(15) << "[test] " << "delete!!" << std::endl;
}



test&	test::operator=(const test& ref)
{
	
	
	*this=ref;
	std::cout << std::setw(15) << "[test] " << "operator=!!" << std::endl;
	return (*this);
}


#ifndef TEST_CPP
# define TEST_CPP

class test
{
private:
	/* data */

public:
	test();
	test(const test& ref);
	~test();

	test&	operator=(const test& ref);
};

#endif
