# Project: Blockchain
# Makefile created by Dev-C++ 5.11

CPP      = g++ -D__DEBUG__
CC       = gcc -D__DEBUG__
WINDRES  = windres.exe
OBJ      = main.o Block.o Transaction.o md5.o
LINKOBJ  = main.o Block.o Transaction.o md5.o
# LIBS     = -L"G:/Dev-Cpp/MinGW64/lib" -L"G:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc -g3
# INCS     = -I"G:/Dev-Cpp/MinGW64/include" -I"G:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"G:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
# CXXINCS  = -I"G:/Dev-Cpp/MinGW64/include" -I"G:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"G:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"G:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = blockchain
CXXFLAGS = $(CXXINCS) -g3
CFLAGS   = $(INCS) -g3
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

Block.o: Block.cpp
	$(CPP) -c Block.cpp -o Block.o $(CXXFLAGS)

Transaction.o: Transaction.cpp
	$(CPP) -c Transaction.cpp -o Transaction.o $(CXXFLAGS)

md5.o: Transaction.cpp
	$(CPP) -c md5.cpp -o md5.o $(CXXFLAGS)
