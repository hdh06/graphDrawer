test: test.c graph.c graph.h da.h
	 clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a \
		 	test.c graph.c -g -o test

clean: test  
	rm test
