CXX=clang++
CPPFLAGS=-Wall -std=c++14
OBJECTS=rational.o gcd.o
LIBS=

all: test

test: bin_dir $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o bin/test test.cc $(OBJECTS) $(LIBS)
	bin/test

%.o: %.cc %.hh
	$(CXX) -c $(CPPFLAGS) $<

bin_dir:
	[ -d bin ] || mkdir bin

clean:
	rm -rf *.o bin/*
