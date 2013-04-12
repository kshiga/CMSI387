dp: dp-harness.o dp-sync.o dp-cs.o philosopher.o utility.o
	gcc -o dp *.o -lpthread

dp-harness.o: dp-sync.h

dp-cs.o: dp-cs.h chopstick.h

dp-sync.o: dp-sync.h chopstick.h

philosopher.o: dp-cs.h dp-sync.h chopstick.h utility.h

utility.o: utility.h

clean:
	rm dp *.o
