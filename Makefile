C := g++
CLFAGS := -std=c++11

SRCDIR := ./src
BUILDDIR := ./build

ej1FILES := $(SRCDIR)/ej1/main.cc
ej2FILES := $(SRCDIR)/ej2/main.cc
ej3FILES := $(SRCDIR)/ej3/main.cc

default: all
.PHONY: clean

all: clean builddir ej1 ej2 ej3

builddir:
	mkdir build

ej%: 
	$(C) $(CFLAGS) $($@FILES) -o $(BUILDDIR)/$@
	$(C) $(CFLAGS) -D debug $($@FILES) -o $(BUILDDIR)/$@_debug

clean:
	rm -rf build 
