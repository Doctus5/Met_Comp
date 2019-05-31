import numpy as np
import matplotlib.pyplot as plt
import corner

marcha=np.loadtxt('datos.dat')

statx=[3, 4, 5, 3, 4, 5]
staty=[15, 15, 15, 16, 16, 16]

plt.scatter(marcha[:,0],marcha[:,1],c='blue')
plt.scatter(statx,staty,c='red')
plt.savefig('scatter.pdf')

corner.corner(marcha)
plt.savefig('mapa.pdf')
