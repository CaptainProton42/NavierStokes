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

du2_dx = np.genfromtxt("der.txt")
dv2_dy = np.genfromtxt("der2.txt")
duv_dx = np.genfromtxt("der3.txt")
duv_dy = np.genfromtxt("der4.txt")

dx = 0.1
dy = 0.1

du2_dx_ana = np.fromfunction(lambda j, i: 2 * np.sin(dx*i) * np.cos(dx*i), (100, 100))
dv2_dy_ana = np.fromfunction(lambda j, i: -2 * np.sin(dy*j) * np.cos(dy*j), (100, 100))
duv_dx_ana = np.fromfunction(lambda j, i: np.cos(dx*i) * np.cos(dy*j), (100, 100))
duv_dy_ana = np.fromfunction(lambda j, i: -np.sin(dx*i) * np.sin(dy*j) , (100, 100))

plt.figure(1)
plt.subplot(121)
plt.imshow(du2_dx)
plt.subplot(122)
plt.imshow(du2_dx_ana)

plt.figure(2)
plt.subplot(121)
plt.imshow(dv2_dy)
plt.subplot(122)
plt.imshow(dv2_dy_ana)

plt.figure(3)
plt.subplot(121)
plt.imshow(duv_dx)
plt.subplot(122)
plt.imshow(duv_dx_ana)

plt.figure(4)
plt.subplot(121)
plt.imshow(duv_dy)
plt.subplot(122)
plt.imshow(duv_dy_ana)