import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as anim
from mpl_toolkits.axes_grid1 import make_axes_locatable
from matplotlib.colors import BoundaryNorm
import numpy as np

# Enable looped gif by overwriting the PillowWriter class and adding loop=0
class myPillow(anim.PillowWriter):
    def finish(self):
        self._frames[0].save(
            self._outfile, save_all=True, append_images=self._frames[1:],
            duration=int(1000 / self.fps), loop=0)

#constants
FRAMENUM = 900	# number of files/frames to animate
FPS = 30

OUT_DIR = "out_Re_10000_f_1"

p = np.genfromtxt(OUT_DIR + "/0_p.txt", skip_header=3)[1:200, 1:200]

fig = plt.figure(1, [5, 5])
ax = fig.gca()

# Plot colormap.
cmap = mpl.cm.get_cmap('viridis')
norm = BoundaryNorm(np.linspace(-0.1, 0.1, 21), cmap.N);
speed = ax.imshow(p, norm = norm, origin = "lower", cmap=cmap, extent = (0, 1, 0, 1))

# Plot colorbar.
divider = make_axes_locatable(ax)
cax = divider.append_axes('right', size='5%', pad=0.05)
bar = fig.colorbar(speed, cax=cax, orientation='vertical')
bar.locator = mpl.ticker.MultipleLocator(0.02)
bar.update_ticks()

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
        p = np.genfromtxt(OUT_DIR + '/'+ str(N)+'_p.txt', skip_header=3)[1:200, 1:200]
        speed.set_data(p)
        new_frame = False
    print("Frame "  + str(n) + " / " + str(FRAMENUM))
    return speed,

writer = myPillow()
writer.fps = FPS
animation = anim.FuncAnimation(fig, animate, frames=FRAMENUM, interval = 16, blit=True)
animation.save('pressure.gif', writer=writer)

plt.savefig("pressure.pdf")