CFLAGS = -Wall -Wextra -Werror -O3
CC = gcc

run: temperaturUmrechner
	./temperaturUmrechner

temperaturUmrechner: temperaturUmrechner.o
	$(CC) $(CFLAGS) -o $@ $^

temperaturUmrechner.o: temperaturUmrechner.c
	$(CC) $(CFLAGS) -c temperaturUmrechner.c


clean:
	rm -f *.o temperaturUmrechner