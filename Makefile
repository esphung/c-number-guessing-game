CFLAGS=-Wall -g
run:
	./a.out
	#./pegasusGuess

all:
	#gcc pegasusGuess.cpp
	g++ pegasusGuess.cpp
	#g++ -std=c++0x pegasusGuess.cpp -o pegasusGuess
	#make pegasusGuess


clean:
	rm -rf a.out
	#rm -rf pegasusGuess

