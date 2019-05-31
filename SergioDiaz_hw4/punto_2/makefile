

cuerda.gif : animacion.py datos.dat
	python animacion.py

datos.dat : a.out
	./a.out > datos.dat

a.out : cuerda.c
	gcc cuerda.c -lm

clean : a.out datos.dat ~
	rm a.out datos.dat *~*
