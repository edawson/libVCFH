CXX:=g++
CXXFLAGS:=-O3
EXE:=example.exe

$(EXE): main.o vcfheader.o
	$(CXX) $(CXXFLAGS) -o $@ $<

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

vcfheader.o: vcfheader.hpp vcfheader.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) $(EXE)
