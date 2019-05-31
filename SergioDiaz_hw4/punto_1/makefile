grafica.pdf : potencial.dat campo.dat grafica.py
	python grafica.py

potencial.dat campo.dat : a.out
	./a.out

a.out : placas.c
	gcc placas.c -lm

clean : a.out  campo.dat potencial.dat ~
	rm a.out campo.dat potencial.dat *~*
