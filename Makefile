CFLAGS=-Wall -g




run:
	./a.out
	#./pegasusGuess

all:
	#gcc pegasusGuess.cpp
	g++ pegasusGuess.cpp
	make pegasusGuess


clean:
	rm -rf a.out
	rm -f pegasusGuess

