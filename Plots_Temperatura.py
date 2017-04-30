import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
#caso 1
f1c1to = np.loadtxt('f1c1to.txt')
f1c1t100 = np.loadtxt('f1c1t100.txt')
f1c1t2500 = np.loadtxt('f1c1t2500.txt')
a1c1to = np.loadtxt('a1c1to.txt')
a1c1t100 = np.loadtxt('a1c1t100.txt')
a1c1t2500 = np.loadtxt('a1c1t2500.txt')
p1c1to = np.loadtxt('p1c1to.txt')
p1c1t100 = np.loadtxt('p1c1t100.txt')
p1c1t2500 = np.loadtxt('p1c1t2500.txt')

#caso 1 solamente...

f11 = f1c1to.reshape(13,13)
f12 = f1c1t100.reshape(13,13)
f13 = f1c1t2500.reshape(13,13)
a11 = a1c1to.reshape(13,13)
a12 = a1c1t100.reshape(13,13)
a13 = a1c1t2500.reshape(13,13)
p11 = p1c1to.reshape(13,13)
p12 = p1c1t100.reshape(13,13)
p13 = p1c1t2500.reshape(13,13)

x = np.arange(0,1.1,0.1)
y = x.copy()
z11 = f11[1:-1,1:-1]
z12 = f12[1:-1,1:-1]
z13 = f13[1:-1,1:-1]
z14 = a11[1:-1,1:-1]
z15 = a12[1:-1,1:-1]
z16 = a13[1:-1,1:-1]
z17 = p11[1:-1,1:-1]
z18 = p12[1:-1,1:-1]
z19 = p13[1:-1,1:-1]

#caso 2

fc2to = np.loadtxt('fc2to.txt')
fc2t100 = np.loadtxt('fc2t100.txt')
fc2t2500 = np.loadtxt('fc2t2500.txt')
ac2to = np.loadtxt('ac2to.txt')
ac2t100 = np.loadtxt('ac2t100.txt')
ac2t2500 = np.loadtxt('ac2t2500.txt')
pc2to = np.loadtxt('pc2to.txt')
pc2t100 = np.loadtxt('pc2t100.txt')
pc2t2500 = np.loadtxt('pc2t2500.txt')


f21 = fc2to.reshape(13,13)
f22 = fc2t100.reshape(13,13)
f23 = fc2t2500.reshape(13,13)

a21 = ac2to.reshape(13,13)
a22 = ac2t100.reshape(13,13)
a23 = ac2t2500.reshape(13,13)

p21 = pc2to.reshape(13,13)
p22 = pc2t100.reshape(13,13)
p23 = pc2t2500.reshape(13,13)

z21 = f21[1:-1,1:-1]
z22 = f22[1:-1,1:-1]
z23 = f23[1:-1,1:-1]

z24 = a21[1:-1,1:-1]
z25 = a22[1:-1,1:-1]
z26 = a23[1:-1,1:-1]

z27 = p21[1:-1,1:-1]
z28 = p22[1:-1,1:-1]
z29 = p23[1:-1,1:-1]

X, Y = np.meshgrid(x,y)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z11, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones fijas, tiempo 0, caso 1')
plt.show()
plt.savefig('fijastiempo0caso1.png')
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z12, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones fijas, tiempo 100, caso 1')
plt.show()
plt.savefig('fijastiempo100caso1.png')
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z13, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones fijas, tiempo 2500, caso 1')
plt.show()
plt.savefig('fijastiempo2500caso1.png')
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z14, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones abiertas, tiempo 0, caso 1')
plt.savefig('abiertastiempo0caso1.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z15, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones abiertas, tiempo 100, caso 1')
plt.savefig('abiertastiempo100caso1.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z16, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones abiertas, tiempo 2500, caso 1')
plt.savefig('abiertastiempo2500caso1.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z17, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones periodicas, tiempo 0, caso 1')
plt.savefig('periodicastiempo0caso1.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z18, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones periodicas, tiempo 100, caso 1')
plt.savefig('periodicastiempo100caso1.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z19, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones periodicas, tiempo 2500, caso 1')
plt.savefig('periodicastiempo2500caso1.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z21, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones fijas, tiempo 0, caso 2')
plt.savefig('fijastiempo0caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z22, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones fijas, tiempo 100, caso 2')
plt.savefig('fijastiempo100caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z23, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones fijas, tiempo 2500, caso 2')
plt.savefig('fijastiempo2500caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z24, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones abiertas, tiempo 0, caso 2')
plt.savefig('abiertastiempo0caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z25, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones abiertas, tiempo 100, caso 2')
plt.savefig('abiertastiempo100caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z26, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones abiertas, tiempo 2500, caso 2')
plt.savefig('abiertastiempo2500caso2.png')
plt.show()
plt.close()


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z27, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones periodicas, tiempo 0, caso 2')
plt.savefig('periodicastiempo0caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z28, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones periodicas, tiempo 100, caso 2')
plt.savefig('periodicastiempo100caso2.png')
plt.show()
plt.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,Y,z29, cmap=plt.cm.jet, cstride=1, rstride=1)
ax.set_xlabel('X (m)')
ax.set_ylabel('Y (m)')
ax.set_zlabel('Temperatura')
ax.set_title('Condiciones periodicas, tiempo 2500, caso 2')
plt.savefig('periodicastiempo2500caso2.png')
plt.show()
plt.close()

tiempo = np.array([0,100,2500])
t11 = np.loadtxt('avc1f.txt')
t12 = np.loadtxt('avc1a.txt')
t13 = np.loadtxt('avc1p.txt')

plt.plot(tiempo,t11,'bo--', label = 'condiciones fijas')
plt.plot(tiempo,t12,'k', label = 'condiciones abiertas')
plt.plot(tiempo,t13,'co--', label = 'condiciones periodicas')
plt.legend(loc ='lower center', fontsize = 'small')


plt.grid()
plt.xlabel('tiempo (s)')
plt.ylabel('temperatura media')
plt.title('Caso 1')
plt.show()
plt.savefig('tmediacaso1.png')
plt.close()


t14 = np.loadtxt('avc2f.txt')
t15 = np.loadtxt('avc2a.txt')
t16 = np.loadtxt('avc2p.txt')

plt.plot(tiempo,t14,'bo--', label = 'condiciones fijas')
plt.plot(tiempo,t15,'k', label = 'condiciones abiertas')
plt.plot(tiempo,t16,'co--', label = 'condiciones periodicas')
plt.legend(loc ='lower center', fontsize = 'small')


plt.grid()
plt.xlabel('tiempo (s)')
plt.ylabel('temperatura media')
plt.title('Caso 2')
plt.show()
plt.savefig('tmediacaso2.png')
plt.close()

