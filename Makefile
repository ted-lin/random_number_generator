TARGET   := rgn
SRCS     := rgn.cpp test.cpp
CXXFLAGS := -Wall
all:
	g++ $(CXXFLAGS) $(SRCS) -o $(TARGET)
clean:
	rm -rf $(TARGET)
