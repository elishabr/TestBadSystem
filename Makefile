all:
	gcc -fPIC -c *.c
	gcc -shared *.o -o libraylinv.so
clear:
	rm -rf *.o