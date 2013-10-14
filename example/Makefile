all: example.hex
example.hex: example-mikroc/Example.hex example-gcc/example.hex
	../mikrostm-link example-mikroc example-gcc > example.hex
clean:
	rm -f example.hex
