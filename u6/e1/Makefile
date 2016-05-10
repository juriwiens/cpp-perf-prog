CXX=clang++
CPPFLAGS=-Wall -std=c++14
OBJECTS=mystr.o
LIBS=

.PHONY: bin_dir clean

default: test

test: bin_dir $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o bin/test test.cpp $(OBJECTS) $(LIBS)
	bin/test

%.o: %.cpp %.hpp
	$(CXX) -c $(CPPFLAGS) $<

bin_dir:
	[ -d bin ] || mkdir bin

clean:
	rm -rf *.o bin/*
