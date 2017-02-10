TARGET   := rgn
SRCS     := rgn.cpp
CXXFLAGS := -Wall
all:
	g++ $(CXXFLAGS) $(SRCS) -o $(TARGET)
clean:
	rm -rf $(TARGET)
