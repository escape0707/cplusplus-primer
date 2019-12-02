CXX = clang++
CXXFLAGS = -std=c++17 -Weverything -Werror -Wno-c++98-compat

%.out: %.cpp
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm *.out