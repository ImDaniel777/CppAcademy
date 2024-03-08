#define BOOST_TEST_MODULE ExampleTestModule
#include <boost/test/unit_test.hpp> 
#include <boost/test/included/unit_test.hpp>
#include "EEPROM.hpp"

BOOST_AUTO_TEST_SUITE(ExampleTestModule)

    Eeprom eeprom;

BOOST_AUTO_TEST_CASE(EEPROM_ALLOCATE_TEST)
{

}

BOOST_AUTO_TEST_SUITE_END() 