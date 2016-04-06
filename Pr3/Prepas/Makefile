
# ajusta estas dos variable según tu distribución
ALEPH = ~/aleph1.6

CLANGPATH = /usr/bin

CXX = $(CLANGPATH)/clang++-3.7

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses -Wno-invalid-source-encoding

FLAGS = -g -O0 -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread -lc

all: main

clean:
	$(RM) main

main: main.C 
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -g -O0 -o $@ $(LIBS)


