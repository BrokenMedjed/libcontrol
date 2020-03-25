gcc control.c -Wall -std=gnu99 -c -o control.o
ar -r libcontrol.a control.o
rm control.o
