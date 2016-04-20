CXX=clang++
CPPFLAGS=-Wall -std=c++14
LIBS=

default: sample

sample: 02-5_sample_code.cc bin_dir
	$(CXX) $(CPPFLAGS) -o bin/sample $< $(LIBS)

md2pdf: answers.md
	pandoc --from markdown_github answers.md -o answers.pdf -V geometry:margin=1in

bin_dir:
	[ -d bin ] || mkdir bin

clean:
	rm -rf *.o bin/*
