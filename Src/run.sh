#!/bin/bash -x
function generate_html_raport()
{
    lcov --capture --directory . --output-file ./coverage.info --no-external
    lcov --remove coverage.info -o coverage_filtered.info \
            '/usr/*'
    genhtml --demangle-cpp coverage_filtered.info --output-directory lcov

    # if [ -e "/lcov/index.html" ]
    # then
        firefox lcov/index.html
    # else
        # echo "index.html was not created"
    # fi
}

rm -rf lco
rm -rf lcov
rm -rf *.info *.gcda *.gcno

g++ -fPIC -fprofile-arcs -ftest-coverage Cpp_Component.cpp Cpp_Component_Test.cpp -o test

./test
echo "Generate html raport? [y/n]"
read answer
case "$answer" in
    [yY]|[yY][eE][sS])
        generate_html_raport ;;
    [nN]|[nN][oO])
        echo "Not generating HTML report." ;;
    *)
        echo "Invalid input" ;;
esac
