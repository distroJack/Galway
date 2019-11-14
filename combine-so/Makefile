
all : exec
default : exec

# 1st : compile and link base lib (ie no deps)
L1 : lib1/helper.cpp
	mkdir -p lib1/obj lib1/lib
	g++ -c $< -o lib1/obj/helper.o
	ar cqT lib1/lib/libhelper.a lib1/obj/helper.o

# 2nd : compile code with include flags to 1st lib and then link 2nd lib O files
L2 : lib2/tester.cpp
	mkdir -p lib2/obj lib2/lib
	g++ -Ilib1 -c $< -o lib2/obj/tester.o
	ar cqT lib2/lib/libtester.a lib1/lib/libhelper.a lib2/obj/tester.o  

# 3rd : compile binary source while including all necessary headers
exec : L1 L2 exec/main.cpp
	mkdir -p exec/bin exec/obj
	g++ -Ilib2 -c exec/main.cpp -o exec/obj/main.o
	g++ -o exec/bin/runner exec/obj/main.o lib2/lib/libtester.a

clean :
	rm -rf lib1/lib
	rm -rf lib1/obj
	rm -rf lib2/lib
	rm -rf lib2/obj
	rm -rf exec/bin
	rm -rf exec/obj
