CXX := g++
CFLAGS := -std=c++11 -lm -lcrypt -O2 -pipe

SRCDIR := ./src
BUILDDIR := ./build

ej1DIR := $(SRCDIR)/ej1
ej2DIR := $(SRCDIR)/ej2
ej3DIR := $(SRCDIR)/ej3

ENTREGA := Cappella_Mallol_Teplizky_Stemberg.zip

default: all
.PHONY: clean

all: clean builddir ej1 ej2 ej3

entrega: clean
	zip $(ENTREGA) Makefile README.md src -r9
	
submit: ej1_submit ej2_submit ej3_submit

ej%: builddir ej%_submit
	$(CXX) $(CFLAGS) $($@DIR)/*.cc -o $(BUILDDIR)/$@
	$(CXX) $(CFLAGS) -g -D DEBUG $($@DIR)/*.cc -o $(BUILDDIR)/$@_debug

ej1_submit: builddir
	@echo
	@echo "To submit EJ1 do:"
	@echo "cat $(ej1DIR)/{utils.h,coord.h,map.h,tourCounter.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@"

ej2_submit: builddir
	@echo
	@echo "To submit EJ2 do:"
	@echo "cat $(ej2DIR)/{utils.h,sprinkler.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@"

ej3_submit: builddir
	@echo
	@echo "To submit EJ3 do:"
	@echo "cat $(ej3DIR)/{utils.h,sprinkler.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@"

builddir:
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(ENTREGA)
