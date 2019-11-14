

all: src/*.cpp setup.py
	python3 setup.py build_ext --inplace
	cp *.cpython* ./test

test: all
	python3 test/*.py
	
clean:
	rm -rf build
	rm -rf *.cpython*
	rm -rf test/*.cpython*
