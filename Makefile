all: plugin main

main:
	c++ --std=c++14 main.cc -o engine

plugin:
	c++ --std=c++14 -shared -fPIC plug.cc -o plugin.so
