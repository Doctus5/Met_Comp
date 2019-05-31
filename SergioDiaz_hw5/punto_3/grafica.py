import numpy as np
import matplotlib.pyplot as plt
import corner

datos=np.loadtxt('datos.dat')

a_b=datos[:,:2]
g_d=datos[:,2:]

plt.figure()
corner.corner(a_b)
plt.savefig('alpha_beta.pdf')

plt.figure()
corner.corner(g_d)
plt.savefig('gamma_delta.pdf')
