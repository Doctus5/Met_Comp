import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anime


datos=np.loadtxt('datos.dat')
datos=np.array(datos)

L=100.0
x=np.linspace(0.0,L,len(datos[0]))


def animacion(n):
    plt.cla()
    plt.plot(x,datos[n,:],'o-')
    plt.xlim(0,x[-1])
    plt.ylim(-3*max(datos[0,:]),3*max(datos[0,:]))

fig=plt.figure(figsize=(6,5))

anim=anime.FuncAnimation(fig,animacion,frames=len(datos))
anim.save('cuerda.gif',writer='imagemagick',fps=5)
