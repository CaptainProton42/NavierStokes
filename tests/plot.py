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

u = np.genfromtxt("u.txt")
v = np.genfromtxt("v.txt")

plt.quiver(u, v)