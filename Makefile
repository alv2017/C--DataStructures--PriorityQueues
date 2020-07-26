build:
	gcc -Wall -std=c99 main.c menu/*.c src/*.c -o main
run:
	./main
clean:
	rm main