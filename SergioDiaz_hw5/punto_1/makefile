scatter.pdf mapa.pdf : datos.dat
	python grafica.py

datos.dat : a.out
	./a.out > datos.dat

a.out : sismos.c
	gcc sismos.c -lm
