import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as anim
from mpl_toolkits.axes_grid1 import make_axes_locatable
from matplotlib.colors import BoundaryNorm
import numpy as np
from skimage.transform import resize
#constants
FRAMENUM = 30	# number of files/frames to animate
RENDERVID = 1 	# set to 1 for video render (needs ffmpeg and can also take a while)
FPS = 30

u = np.genfromtxt("out/0_u.txt", skip_header=3)[1:500, 1:500]
v = np.genfromtxt("out/0_v.txt", skip_header=3)[1:500, 1:500]
s = np.sqrt(np.power(u, 2) + np.power(v, 2))

u_red = resize(u, (11, 11))
v_red = resize(v, (11, 11))

fig = plt.figure(1, [5, 5])
ax = fig.gca()

# Plot colormap.
cmap = mpl.cm.get_cmap('viridis')
norm = BoundaryNorm(np.logspace(-5, 0, 11), cmap.N);
speed = ax.imshow(s, norm = norm, origin = "lower", extent = (0, 10, 0, 10))

# Plot colorbar.
divider = make_axes_locatable(ax)
cax = divider.append_axes('right', size='5%', pad=0.05)
loc = mpl.ticker.LogLocator()
bar = fig.colorbar(speed, cax=cax, orientation='vertical', format=mpl.ticker.LogFormatterSciNotation())

# Plot vector field.
vec = ax.quiver(u_red, v_red, scale=0.5, color="white")

plt.tight_layout()

N = 0
t_next = float(open('out/1_p.txt', "r").readline())
def animate(n):
    global N
    global t_next
    t = n * 1/FPS
    new_frame = False
    while (t >= t_next):
        t_next = float(open('out/'+str(N+1)+'_p.txt', "r").readline())
        N += 1
        new_frame = True
    if (new_frame):
        u = np.genfromtxt('out/'+str(N)+'_u.txt', skip_header=3)[1:500, 1:500]
        v = np.genfromtxt('out/'+str(N)+'_v.txt', skip_header=3)[1:500, 1:500]
        s = np.sqrt(np.power(u, 2) + np.power(v, 2))
        speed.set_data(s)

        u_red = resize(u, (11, 11))
        v_red = resize(v, (11, 11))
        vec.set_UVC(u_red, v_red)
        new_frame = False
    print("Frame:", n)
    return speed, vec

animation = anim.FuncAnimation(fig, animate, frames=FRAMENUM, interval = 16, blit=True)
plt.show()

if (RENDERVID == 1):
	plt.rcParams['animation.ffmpeg_path'] = 'C:/FFmpeg/bin/ffmpeg.exe'	
	#mywriter = anim.FFMpegWriter(fps=FPS)
	animation.save('plot.gif', writer='pillow', fps=FPS)