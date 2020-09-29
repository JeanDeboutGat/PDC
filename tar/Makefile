CFLAGS= -Wall
TARGET= test_arrondi
SRCS  = arrondi.c test_arrondi.c
OBJS  = $(SRCS:.c=.o)
DEPS  = arrondi.h

TARGET2 = lstar
SRCS2   = arrondi.c lstar.c
OBJS2   = $(SRCS2:.c=.o)

all: $(TARGET) $(TARGET2)

$(TARGET): $(OBJS)
	gcc $^ -o $@

$(TARGET2): $(OBJS2)
	gcc $^ -o $@

%.o : %.c $(DEPS)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(TARGET)
	rm -f $(OBJS)