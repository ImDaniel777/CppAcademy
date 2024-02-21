#define BOOST_TEST_MODULE ExampleTestModule
#include <boost/test/unit_test.hpp> 
#include <boost/test/included/unit_test.hpp>
#include "Cpp_Component.hpp"

BOOST_AUTO_TEST_SUITE(ExampleTestModule)

BOOST_AUTO_TEST_CASE(set_name_test)
{
    Record record{0,"Daniel"};
    std::string expected_name = "Daniel";

    BOOST_CHECK(expected_name == record._name);
}

BOOST_AUTO_TEST_CASE(set_id_test)
{
    Record record{0,"Daniel"};
    int expected_id = 0;

    BOOST_CHECK(expected_id == record._id);
}

BOOST_AUTO_TEST_SUITE_END() 
