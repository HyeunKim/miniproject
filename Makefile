CC = gcc
CFLAGS = -W -Wall
TARGET = product
DTARGET = product_debug
SRCS = main.c product.c manager.c
OBJECTS = $(SRCS:.c=.o)

.SUFFIXES : .c .o

all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(SRCS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

.o : 
	$(CC) $(CFLAGS) -c $<

 clean :
	rm *.o
	rm product product_debug
