

all: src/*.cpp setup.py
	python3 setup.py build_ext --inplace
	cp *.cpython* ./test

test: all
	python3 -m pytest test -v

clean:
	rm -rf build
	rm -rf *.cpython*
	rm -rf test/*.cpython*
	rm -rf test/__pycache__
