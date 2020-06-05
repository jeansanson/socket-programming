client: client.o clientctrl.o
	gcc -o client clientctrl.o client.o

client.o: client.c
	gcc -c client.c

sum.o: clientctrl.c
	gcc -c clientctrl.c