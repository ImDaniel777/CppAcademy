#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

TEST_GROUP(Group) {};

TEST(Group, Test) {};

int main(int argc, char ** argv)
{
    RUN_ALL_TESTS(argc, argv);
}