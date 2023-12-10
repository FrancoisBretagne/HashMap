
all : exx

File.o : File.c fonction.h
	gcc -c $< -o $@
Arbre.o : Arbre.c fonction.h
	gcc -c $< -o $@
Hashmap.o : Hashmap.c fonction.h
	gcc -c $< -o $@
main.o : main.c fonction.h
	gcc -c $< -o $@

exx : File.o Arbre.o Hashmap.o main.o
		ar -rcs libhashmap.a File.o Arbre.o Hashmap.o
		gcc main.o libhashmap.a -o $@

clean :
	rm *.o -f
	rm exx -f

