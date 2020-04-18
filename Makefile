CC=gcc
CFLAGS=-Wall -Werror
LFLAGS=-lgtest -lstdc++
TARGET=tests

SOURCES=$(wildcard src/*.cpp) 
OBJECTS=$(patsubst src/%.cpp, obj/%.o, $(SOURCES))

UTS_SOURCES=$(wildcard ut/src/*.cpp)
UTS_OBJECTS=$(patsubst ut/src/%.cpp, ut/obj/%.o, $(UTS_SOURCES))

bin/$(TARGET): ut/sut.cpp $(OBJECTS) $(UTS_OBJECTS)
	$(CC) $+ -o $@ $(CFLAGS) $(LFLAGS)

$(UTS_OBJECTS): ut/obj/%Tests.o: ut/src/%Tests.cpp inc/%.hpp
	$(CC) $< -c -o $@ $(CFLAGS)

$(OBJECTS): obj/%.o: src/%.cpp inc/%.hpp
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm obj/* bin/* ut/obj/*
run: bin/$(TARGET)
	./bin/$(TARGET)


# =========== source of theory about Makefiles ==============
# https://cpp-polska.pl/post/potwor-przeszlosci-makefile-cz-2
# https://cpp-polska.pl/post/potwor-przeszlosci-makefile-cz-1

# ============ upper generic makefile base on below =========
# main:
# 	@echo $(UTS_OBJECTS)
# bin/$(TARGET): ut/sut.cpp obj/FirstTests.o obj/source.o
# 	$(CC) ut/sut.cpp obj/FirstTests.o obj/source.o -o bin/$(TARGET) $(CFLAGS) $(LFLAGS)
#
# obj/FirstTests.o: ut/FirstTests.cpp inc/source.hpp
# 	$(CC) ut/FirstTests.cpp -c -o obj/FirstTests.o $(CFLAGS)