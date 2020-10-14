
CXX=g++
CFLAGS=-I.
ODIR=obj
BDIR=bin
DIRS=$(ODIR) $(BDIR)

$(DIRS):
	mkdir -p $@

$(ODIR)/%.o: %.cpp $(ODIR)
	$(CXX) -c -o $@ $< $(CFLAGS)

problem: $(ODIR)/problem.o $(BDIR)
	$(CXX) -o $(BDIR)/$@ $< $(CFLAGS) $(LIBS)

solution: $(ODIR)/solution.o $(BDIR)
	$(CXX) -o $(BDIR)/$@ $< $(CFLAGS) $(LIBS)

all: problem solution
.DEFAULT_GOAL := all

# Clean target
.PHONY: clean
clean:
	rm -rf $(ODIR) $(BDIR)

