default:
	make clean
	gcc *.c *.h

clean:
	rm -f *.gch a.out
run:
	make
	./a.out test.txt > output.txt
