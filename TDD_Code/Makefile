# this is set up to by default to make the top level and test with CppUTest
# You need to separately get and build cpputest from cpputest.org
# You must also define CPPUTEST_HOME.  See the README.txt

all: everything
clean: cleaneverything

codeUnity:
	make -i -f MakefileUnity.mk

cleanCodeCppUTest:
	make -i -f MakefileCppUTest.mk clean
	
cleanCodeUnity:
	make -i -f MakefileUnity.mk clean
	
everything: 
	make -i -f MakefileCppUTest.mk 
	make -i -f MakefileUnity.mk

cleaneverything:
	make -i -C SandBox clean
	make -i -f MakefileCppUTest.mk clean
	make -i -f MakefileUnity.mk clean
