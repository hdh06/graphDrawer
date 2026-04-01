test: test.c clean
	 clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a \
		 	test.c -o test

clean: test  
	rm test
