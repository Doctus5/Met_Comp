import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

l=2.0
L=5.0
h=0.02
d=1.0

v=np.loadtxt('potencial.dat')
c=np.loadtxt('campo.dat')

X,Y=np.mgrid[-L/2:L/2:len(c)j, -L/2:L/2:len(c)j]
U=
V=

plt.imshow(v)
plt.colorbar()
plt.streamplot(X,Y,U,V)
plt.savefig('placas.pdf')
plt.close()
