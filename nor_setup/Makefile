D ?= 0
ifeq ($(D), 1)
	CXXFLAGS=-std=c++17 -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -fsanitize-address-use-after-scope
else
	CXXFLAGS=-O2 -std=c++17
endif

clean:
	find . -maxdepth 1 -type f -executable -delete
