client: client.o clientCtrl.o
	gcc -o client clientCtrl.o client.o

client.o: client.c
	gcc -c client.c

sum.o: clientCtrl.c
	gcc -c clientCtrl.c