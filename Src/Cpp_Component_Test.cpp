#define BOOST_TEST_MODULE ExampleTestModule
#include <boost/test/unit_test.hpp> 
#include <boost/test/included/unit_test.hpp>
#include "Cpp_Component.hpp"

BOOST_AUTO_TEST_SUITE(ExampleTestModule)

    auto &db = Database::createInstance();

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

BOOST_AUTO_TEST_CASE(singletone_database)
{
    auto &db2 = Database::createInstance();

    BOOST_CHECK_EQUAL(&db, &db2);
}

BOOST_AUTO_TEST_CASE(add_record_to_database_1)
{
    const int db_records_length = db.getNumberOfRecords();
    const int expected_length = db_records_length + 1;

    db.addRecord(1, "Mihai");
    BOOST_CHECK_EQUAL(expected_length, db.getNumberOfRecords());
}

BOOST_AUTO_TEST_CASE(add_record_to_database_2)
{
    const int db_records_length = db.getNumberOfRecords();
    const int expected_length = db_records_length + 1;
    Record record{10, "Alex"};
    db.addRecord(record);

    Record *result = db.searchRecordById(10);
    BOOST_CHECK(result->_id == record._id && result->_name == record._name);
    BOOST_CHECK_EQUAL(expected_length, db.getNumberOfRecords());
}

BOOST_AUTO_TEST_CASE(search_record_in_database)
{

    Record testRecord{2, "TestRecord"};
    db.addRecord(testRecord);
    Record *result = db.searchRecordById(2);

    BOOST_WARN_MESSAGE(testRecord._id == result->_id, "Ids are not equal");
    BOOST_WARN_MESSAGE(testRecord._name == result->_name, "Names are not equal");

    result = db.searchRecordById(-1);
    BOOST_REQUIRE_MESSAGE(result == nullptr, " ");
}

BOOST_AUTO_TEST_CASE(print_all_records)
{
    db.emptyDatabase();
    db.addRecord(1, "Daniel");
    db.addRecord(2, "Alex");
    db.addRecord(3, "Andrei");
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    db.printAllRecords();
    std::cout.rdbuf(oldCoutStreamBuf);
    // Check if the output contains all the expected records
    std::string expectedOutput =
        "ID: 1, Name: Daniel\n"
        "ID: 2, Name: Alex\n"
        "ID: 3, Name: Andrei\n";
    BOOST_CHECK(output.str() == expectedOutput);
}

BOOST_AUTO_TEST_CASE(demo)
{
    boost::unit_test::unit_test_log.set_threshold_level( boost::unit_test::log_warnings );
    boost::unit_test::expected_failures(0);
    boost::unit_test::tolerance(0.05); /* 0.05 tolerance */
    boost::test_tools::fpc::percent_tolerance(5); /* 5% tolerance */
    boost::unit_test::timeout(5); /* 5s timeout */

    BOOST_WARN_BITWISE_EQUAL(0b11110111, 0b11111111);

    int col1 [] = { 1, 2, 3, 4, 5, 6, 7 };
    int col2 [] = { 1, 2, 4, 4, 5, 7, 7 };
    BOOST_CHECK_EQUAL_COLLECTIONS( col1, col1+7, col2, col2+7 );

    double v1 = 1.12345;
    double v2 = 1.12344;
    BOOST_CHECK_CLOSE_FRACTION(v1, v2, 0.00001);
    // BOOST_CHECK_CLOSE(v1, v2, 0.00001); /* this is percentage  */


    bool expression = (5 >= 10);
    BOOST_WARN_MESSAGE(expression, " 5 is not greater that 10");
}
BOOST_AUTO_TEST_SUITE_END() 
