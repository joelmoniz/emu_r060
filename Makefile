default:
	make clean
	gcc *.c *.h

clean:
	rm -f *.gch a.out
run:
	make
	./a.out test.txt > output.txt
debug:
	make clean
	gcc -g *.c *.h
	gdb -tui ./a.out
comp:
	make
	sh generate_output.sh
