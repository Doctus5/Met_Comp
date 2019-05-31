alpha_beta.pdf gamma_delta.pdf : datos.dat
	python grafica.py

datos.dat : a.out
	./a.out > datos.dat

a.out : poblaciones.c
	gcc poblaciones.c -lm
