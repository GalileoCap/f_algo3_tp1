CXX := g++
CFLAGS := -std=c++11 -lm -lcrypt -O2 -pipe

SRCDIR := ./src
BUILDDIR := ./build

ej1FILES := $(SRCDIR)/ej1/*.cc
ej2FILES := $(SRCDIR)/ej2/*.cc
ej3FILES := $(SRCDIR)/ej3/*.cc

default: all
.PHONY: clean

all: clean builddir ej1 ej2 ej3

builddir:
	mkdir build

ej%: 
	$(CXX) $(CFLAGS) $($@FILES) -o $(BUILDDIR)/$@
	$(CXX) $(CFLAGS) -g -D DEBUG $($@FILES) -o $(BUILDDIR)/$@_debug

clean:
	rm -rf build 
