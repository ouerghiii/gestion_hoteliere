TARGET = gestion_hoteliere
CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRCDIR = src
INCDIR = include
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
