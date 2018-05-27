CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

testHelper.o: testHelper.h testHelper.c dominion.o interface.o rngs.o
	gcc -c testHelper.c -g $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c dominion.o interface.o rngs.o testHelper.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

unittest2: unittest2.c dominion.o interface.o rngs.o testHelper.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

unittest3: unittest3.c dominion.o interface.o rngs.o testHelper.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

unittest4: unittest4.c dominion.o interface.o rngs.o testHelper.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o interface.o rngs.o testHelper.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o interface.o rngs.o testHelper.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o interface.o rngs.o testHelper.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o interface.o rngs.o testHelper.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o testHelper.o $(CFLAGS)

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c 
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o testHelper.o $(CFLAGS)
	
	echo "unittest1.c:" >> unittestresults.out
	./unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	cat unittest1.c.gcov >> unittestresults.out 
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	cat cardtest3.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	cat cardtest4.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o testHelper.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o testHelper.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o testHelper.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o testHelper.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o testHelper.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o testHelper.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out 
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard1.out: randomtestcard1
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard1.c:" >> randomtestcard1.out
	./randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	gcov -b randomtestcard1.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out 
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard2.c:" >> randomtestcard2.out
	./randomtestcard2 >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	gcov -b randomtestcard2.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out 
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer
 
