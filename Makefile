CXX = clang++
CXXFLAGS = -std=c++17 -Weverything -Wno-c++98-compat -Wno-exit-time-destructors -Wno-global-constructors

%.out: %.cpp
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm *.o *.out
