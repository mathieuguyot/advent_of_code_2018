CC=g++
CC_SUFFIX=
C++17=-std=gnu++17

VPATH =	src/ test/

DEFINE_DEBUG=-w -g -fpic -DUNIX_GNU -D_DEBUG
DEFINE_RELEASE=-w -fpic -DUNIX_GNU -DNDEBUG -O3

OBJECTS_DEBUG=	debug/aoc_test_main.o \
				debug/aoc_1.o \
				debug/aoc_1_test.o \

OBJECTS_RELEASE=release/aoc_test_main.o \
				release/aoc_1.o \
				release/aoc_1_test.o \

OUTPUT_PATH_DEBUG=../build/debug/
OUTPUT_NAME_DEBUG=aoc_2018

OUTPUT_PATH_RELEASE=../build/release/
OUTPUT_NAME_RELEASE=aoc_2018

LINK_PATH_DEBUG=-L../build/debug/ -L/usr/lib/
LINK_FILE_DEBUG=
LINK_PATH_RELEASE=-L../build/release/ -L/usr/lib/
LINK_FILE_RELEASE=
INCLUDE_PATH=-Iinclude/  -I/usr/include/
prepared:
	mkdir -p ../build/
	mkdir -p ../build/debug/
	mkdir -p debug/
	
preparer:
	mkdir -p ../build/
	mkdir -p ../build/release/
	mkdir -p release/
	
prepare: preparer prepared
	
all: prepare clean debug release

debug: $(OUTPUT_PATH_DEBUG)$(OUTPUT_NAME_DEBUG)
$(OUTPUT_PATH_DEBUG)$(OUTPUT_NAME_DEBUG):$(OBJECTS_DEBUG)
	@echo $@
	$(CC) $(DEFINE_DEBUG) $(C++17) $(LINK_PATH_DEBUG) $(LINK_FILE_DEBUG) -o $@ $(OBJECTS_DEBUG) $(CC_SUFFIX)

.debug.%.d: %.cpp Makefile
	$(CC) $(DEFINE_DEBUG) $(C++17) $(INCLUDE_PATH) -c -o $@ $< $(DEP_INCLUDE) $(CC_SUFFIX)

debug/%.o: %.cpp Makefile
	@echo $@
	$(CC) $(DEFINE_DEBUG) $(C++17) $(INCLUDE_PATH) -c -o $@ $< $(CC_SUFFIX)

release: $(OUTPUT_PATH_RELEASE)$(OUTPUT_NAME_RELEASE)
$(OUTPUT_PATH_RELEASE)$(OUTPUT_NAME_RELEASE):$(OBJECTS_RELEASE)
	@echo $@
	$(CC) $(DEFINE_DEBUG) $(C++17) $(LINK_PATH_RELEASE) $(LINK_FILE_RELEASE) -o $@ $(OBJECTS_RELEASE) $(CC_SUFFIX)

.release.%.d: %.cpp Makefile
	$(CC) $(DEFINE_RELEASE) $(C++17) $(INCLUDE_PATH) -c -o $@ $< $(DEP_INCLUDE) $(CC_SUFFIX)

release/%.o: %.cpp Makefile
	@echo $@
	$(CC) $(DEFINE_RELEASE) $(C++17) $(INCLUDE_PATH) -c -o $@ $< $(CC_SUFFIX)
	
rund:
	./$(OUTPUT_PATH_DEBUG)$(OUTPUT_NAME_DEBUG) ${ARGS}
	
run:
	./$(OUTPUT_PATH_DEBUG)$(OUTPUT_NAME_DEBUG) ${ARGS}
	
cleand:
	rm -rf ./debug/*.o || true
	rm -rf ./$(OUTPUT_PATH_DEBUG)$(OUTPUT_NAME_DEBUG) || true
	
cleanr:
	rm -rf ./release/*.o || true
	rm -rf ./$(OUTPUT_PATH_RELEASE)$(OUTPUT_NAME_RELEASE) || true
	
clean: cleand cleanr
