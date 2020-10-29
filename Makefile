CXX := clang++
DEBUG_LEVEL := -g
CXXFLAGS := $(DEBUG_LEVEL) -std=c++17 -ftrapv -Weverything -Wno-exit-time-destructors -Wno-global-constructors -Wno-c++98-c++11-compat-binary-literal -Wno-c++98-compat -Wno-c++98-compat-pedantic

SRCS := $(wildcard *.cpp)
OBJS := AndRange.o Basket.o BinaryRange.o Blob.o Bulk_quote.o ByKeyRange.o ConstStrBlobPtr.o Date.o Disc_quote.o Folder.o HasPtr.o Limit_quote.o LineNumberRange.o Message.o NotRange.o OrRange.o Query.o QueryResult.o Quote.o Sales_data.o Screen.o StrBlob.o StrBlobPtr.o String.o StrVec.o TextQuery.o Vec.o Window_mgr.o

OBJDIR := obj
DEPDIR := $(OBJDIR)/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

COMPILE.cpp = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

%.out: $(OBJDIR)/%.o $(OBJS:%.o=$(OBJDIR)/%.o)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(OBJDIR)/%.o : %.cpp $(DEPDIR)/%.d | $(DEPDIR)
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRCS:%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))

.PRECIOUS: $(OBJDIR)/%.o

.PHONY: clean

clean:
	rm -r obj; rm *.out
