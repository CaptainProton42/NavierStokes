import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as anim
from mpl_toolkits.axes_grid1 import make_axes_locatable
from matplotlib.colors import BoundaryNorm
import numpy as np
from skimage.transform import resize

# Enable looped gif by overwriting the PillowWriter class and adding loop=0
class myPillow(anim.PillowWriter):
    def finish(self):
        self._frames[0].save(
            self._outfile, save_all=True, append_images=self._frames[1:],
            duration=int(1000 / self.fps), loop=0)

#constants
FRAMENUM = 900	# number of files/frames to animate
FPS = 30

OUT_DIR = "out"

u = np.genfromtxt(OUT_DIR + "/0_u.txt", skip_header=3)[1:200, 1:200]
v = np.genfromtxt(OUT_DIR + "/0_v.txt", skip_header=3)[1:200, 1:200]
s = np.sqrt(np.power(u, 2) + np.power(v, 2))

u_red = resize(u, (11, 11))
v_red = resize(v, (11, 11))

fig = plt.figure(1, [5, 5])
ax = fig.gca()

# Plot colormap.
cmap = mpl.cm.get_cmap('viridis')
norm = BoundaryNorm(np.linspace(0.0, 1.0, 21), cmap.N)
speed = ax.imshow(s, norm = norm, cmap=cmap, origin = "lower", extent = (0, 1, 0, 1))

# Plot colorbar.
divider = make_axes_locatable(ax)
cax = divider.append_axes('right', size='5%', pad=0.05)
bar = fig.colorbar(speed, cax=cax, orientation='vertical')
loc = mpl.ticker.MultipleLocator(0.2)
bar.locator = loc
bar.update_ticks()

# Plot vector field.
X, Y = np.mgrid[0:1:11j, 0:1:11j]
vec = ax.quiver(Y, X, u_red, v_red, scale=2.0, color="white")

plt.tight_layout()

N = 0
t_next = float(open(OUT_DIR + '/1_p.txt', "r").readline())
def animate(n):
    global N
    global t_next
    t = n * 1/FPS
    new_frame = False
    while (t >= t_next):
        t_next = float(open(OUT_DIR + '/'+ str(N+1)+'_p.txt', "r").readline())
        N += 1
        new_frame = True
    if (new_frame):
        u = np.genfromtxt(OUT_DIR + '/'+ str(N)+'_u.txt', skip_header=3)[1:200, 1:200]
        v = np.genfromtxt(OUT_DIR + '/'+ str(N)+'_v.txt', skip_header=3)[1:200, 1:200]
        s = np.sqrt(np.power(u, 2) + np.power(v, 2))
        speed.set_data(s)

        u_red = resize(u, (11, 11))
        v_red = resize(v, (11, 11))
        vec.set_UVC(u_red, v_red)
        new_frame = False
    print("Frame "  + str(n) + " / " + str(FRAMENUM))
    return speed, vec

writer = myPillow()
writer.fps = FPS
animation = anim.FuncAnimation(fig, animate, frames=FRAMENUM, interval = 16, blit=True)
animation.save('flow.gif', writer=writer)

plt.savefig("flow.pdf")