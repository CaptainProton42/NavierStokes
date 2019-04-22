import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

pgf_with_latex = {                      # setup matplotlib to use latex for output# {{{
    "pgf.texsystem": "pdflatex",        # change this if using xetex or lautex
    "text.usetex": True,                # use latex to write all text
    "font.family": "serif",
    "pgf.preamble": [
        r"\usepackage[utf8x]{inputenc}",    # use utf8 fonts
        r"\usepackage[T1]{fontenc}",
        r"\usepackage[ngerman]{babel}",
        r"\usepackage{amsmath}"
        ]                                   # using this preamble
    }

mpl.rcParams.update(pgf_with_latex)

DIM = 129

u = np.genfromtxt("out_Re_100/2399_u.txt", skip_header=3)[1:DIM+1, int(DIM/2)]   # u at x = 0.5
v = np.genfromtxt("out_Re_100/2399_v.txt", skip_header=3)[int(DIM/2), 1:DIM+1]   # v at y = 0.5
x = np.linspace(0.0, 1.0, DIM)
y = np.linspace(0.0, 1.0, DIM)

# Re 10000
#u_ghia = [1.00000, 0.47221, 0.47783, 0.48070, 0.47804, 0.34635, 0.20673, 0.08344, 0.03111, -0.07540, -0.23186, -0.32709, -0.38000, -0.41657, -0.42537, -0.42735, 0.00000]
#y_ghia = [1.00000, 0.9766, 0.9688, 0.9609, 0.9531, 0.8516, 0.7344, 0.6172, 0.5000, 0.4531, 0.2813, 0.1719, 0.1016, 0.0703, 0.0625, 0.0547, 0.0000]

#v_ghia = [0.00000, -0.54302, -0.52987, -0.49099, -0.45863, -0.41496, -0.36737, -0.30719, 0.00831, 0.27224, 0.28003, 0.35070, 0.41487, 0.43124, 0.43733, 0.43983, 0.0000]
#x_ghia = [1.000, 0.9688, 0.9609, 0.9531, 0.9453, 0.9063, 0.8594, 0.8074, 0.5000, 0.2344, 0.2266, 0.1563, 0.0938, 0.0781, 0.0703, 0.0625, 0.0000]

# Re 1000
#u_ghia = [1.0000, 0.47221, 0.47783, 0.48070, 0.4780, 0.34635, 0.20673, 0.08344, 0.03111, -0.07540, -0.23186, -0.32709, -0.38000, -0.41657, -0.42537, -0.42735, 0.00000]
#y_ghia = [1.0000, 0.9766, 0.9688, 0.9609, 0.9531, 0.8516, 0.7344, 0.6172, 0.5000, 0.4531, 0.2813, 0.1719, 0.1016, 0.0703, 0.0625, 0.0547, 0.000]

#v_ghia = [0.00000, -0.54302, -0.52987, -0.49099, -0.45863, -0.41496, -0.36737, -0.30719, 0.00831, 0.27224, 0.28003, 0.35070, 0.41487, 0.43124, 0.43733, 0.43983, 0.0000]
#x_ghia = [1.0000, 0.9688, 0.9609, 0.9531, 0.9453, 0.9063, 0.8594, 0.8047, 0.5000, 0.2344, 0.2266, 0.1563, 0.0938, 0.0781, 0.0703, 0.0625, 0.0000]

# Re 100
u_ghia = [1.0000, 0.84123, 0.78871, 0.73722, 0.68717, 0.23151, 0.00332, -0.13641, -0.20581, -0.21090, -0.15662, -0.10150, -0.06434, -0.04775, -0.04192, -0.03717, 0.00000]
y_ghia = [1.0000, 0.9766, 0.9688, 0.9609, 0.9531, 0.8516, 0.7344, 0.6172, 0.5000, 0.4531, 0.2813, 0.1719, 0.1016, 0.0703, 0.0625, 0.0547, 0.0000]

v_ghia = [0.00000, -0.05906, -0.07391, -0.08864, -0.10313, -0.16914, -0.22445, -0.24533, 0.05454, 0.17527, 0.17507, 0.16077, 0.12317, 0.10890, 0.10091, 0.09233, 0.00000]
x_ghia = [1.0000, 0.9688, 0.9609, 0.9531, 0.9453, 0.9063, 0.8594, 0.8047, 0.5000, 0.2344, 0.2266, 0.1563, 0.0938, 0.0781, 0.0703, 0.0625, 0.0000]


plt.figure(1)
plt.grid(linestyle='dashed', color='gray')
plt.plot(y, u, color='red', label='Solution')
plt.plot(y_ghia, u_ghia, 'x', color='black', label='Ghia et al.')
plt.xlim(0.0, 1.0)
plt.xlabel('$y$')
plt.ylabel('$u$')
plt.legend()
plt.savefig('ghia_u.pdf')

plt.figure(2)
plt.grid(linestyle='dashed', color='gray')
plt.plot(x, v, color='red', label='Solution')
plt.plot(x_ghia, v_ghia, 'x', color='black', label='Ghia et al.')
plt.xlim(0.0, 1.0)
plt.xlabel('$x$')
plt.ylabel('$v$')
plt.legend()
plt.savefig('ghia_v.pdf')