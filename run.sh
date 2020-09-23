gcc -c example.c -o example.o
gcc -c linkedlist.c -o linkedlist.o
gcc linkedlist.o example.o -o compiled
./compiled
