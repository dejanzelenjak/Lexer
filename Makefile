CC = gcc
INCLUDES = -Iinclude -I..\tools\mingw64\x86_64-w64-mingw32\include
CFLAGS = $(INCLUDES) -Wall -Wextra -std=c11 -O2 -g

TARGET = build\lexer.exe
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src\%.c=build\%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q build\*.o $(TARGET)