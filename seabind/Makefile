
.PHONY: all default exec test clean
all : exec test
default : exec test

exec : 

test : 
	mkdir -p ./obj/test
	mkdir -p ./bin
	gcc -std=c99 -masm=intel ./src/Assembly.s ./test/TestMain.c -o ./bin/seabind

clean :
	rm -rf obj
	rm -rf bin
