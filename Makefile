CCFLAGS = -Wall

tester: tester.o babysitter.o
	gcc $(CCFLAGS) -o tester tester.o babysitter.o

tester.o: tester.c babysitter.o
	gcc $(CCFLAGS) -c tester.c

babysitter.o: babysitter.c
	gcc $(CCFLAGS) -c babysitter.c

test: tester
	./tester

clean:
	-rm -rf tester *.o
