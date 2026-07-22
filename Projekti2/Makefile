CC = gcc
CFLAGS = -Wall -Werror -std=c99

all: my-cat my-grep my-zip my-unzip

my-cat: src/my-cat.c
	$(CC) $(CFLAGS) src/my-cat.c -o my-cat

my-grep: src/my-grep.c
	$(CC) $(CFLAGS) src/my-grep.c -o my-grep

my-zip: src/my-zip.c
	$(CC) $(CFLAGS) src/my-zip.c -o my-zip

my-unzip: src/my-unzip.c
	$(CC) $(CFLAGS) src/my-unzip.c -o my-unzip

clean:
	rm -f my-cat my-grep my-zip my-unzip