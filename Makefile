CXX := g++
CFLAGS := -std=c++11 -lm -lcrypt -O2 -pipe

SRCDIR := ./src
BUILDDIR := ./build

ej1DIR := $(SRCDIR)/ej1
ej2DIR := $(SRCDIR)/ej2
ej3DIR := $(SRCDIR)/ej3

default: all
.PHONY: clean

all: clean builddir ej1 ej2 ej3

entrega: clean
	zip entrega.zip Makefile README.md src -r9
	
builddir:
	mkdir build

ej%: ej%_submit
	$(CXX) $(CFLAGS) $($@DIR)/*.cc -o $(BUILDDIR)/$@
	$(CXX) $(CFLAGS) -g -D DEBUG $($@DIR)/*.cc -o $(BUILDDIR)/$@_debug

ej1_submit:
	@echo "To submit EJ1 do: cat $(ej1DIR)/{utils.h,coord.h,map.h,tourCounter.h,*.cc} >> $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed '/#include \"/d' -i $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@"

ej2_submit:
	@echo "To submit EJ2 do: cat $(ej2DIR)/{utils.h,sprinkler.h,*.cc} >> $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed '/#include \"/d' -i $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@"

ej3_submit:
	@echo TODO: ej3_submit

clean:
	rm -rf build entrega.zip
