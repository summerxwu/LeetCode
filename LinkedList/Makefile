CXX := g++
CXXFLAGS := -ggdb3
SRCS := $(wildcard *.cc)
OBJS := $(patsubst %cc,%o,$(SRCS))
TARGET := $(patsubst %.cc, ./%, $(SRCS))
all:$(TARGET)
%.o:%.cc
	$(CXX) $(CXXFLAGS) -c $<
%:%.o
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -rf $(TARGET) *.o
