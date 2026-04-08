test: test.c graph.c graph.h
	 clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a \
		 	*.c -g -o test

clean: test  
	rm test
