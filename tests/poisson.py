from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np


fig = plt.figure()
ax = fig.gca(projection='3d')

N = 200

p = np.genfromtxt("poisson_p.txt")[1:N+1, 1:N+1]

X = np.arange(0, 1, 1/N)
Y = np.arange(0, 1, 1/N)

X, Y = np.meshgrid(X, Y)

surf = ax.plot_surface(X, Y, p, cmap=cm.coolwarm,
                       linewidth=0, antialiased=False)

# Customize the z axis.
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

# Add a color bar which maps values to colors.
fig.colorbar(surf, shrink=0.5, aspect=5)

plt.show()