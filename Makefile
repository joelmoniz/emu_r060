default:
	make clean
	gcc *.c *.h

clean:
	rm -f *.gch a.out
	rm -f ./test_cases/output*.txt
	rm -f ./test_cases/*.lexer
	rm -f ./test_cases/out_compare*.txt
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
