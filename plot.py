import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import matplotlib.collections as clt
import matplotlib.patches as ptc
import numpy as np
from mpl_toolkits.axes_grid1 import make_axes_locatable
from matplotlib.colors import LogNorm
import skimage.transform
#constants
FRAMENUM = 50	# number of files/frames to animate
RENDERVID = 1 	# set to 1 for video render (needs ffmpeg and can also take a while)
FPS = 60

p = np.genfromtxt("out/0_p.txt", skip_header=3)[1:500, 1:500]
u = np.genfromtxt("out/0_u.txt", skip_header=3)[1:500, 1:500]
v = np.genfromtxt("out/0_v.txt", skip_header=3)[1:500, 1:500]
s = np.sqrt(np.power(u, 2) + np.power(v, 2))

fig = plt.figure(1, [15, 3])

x = np.arange(0, 10.0, 500)
y = np.arange(0, 10.0, 500)


ax1 = fig.add_subplot(151)
heat = ax1.imshow(p)
divider = make_axes_locatable(ax1)
cax = divider.append_axes('right', size='5%', pad=0.05)
fig.colorbar(heat, cax=cax, orientation='vertical')

ax2 = fig.add_subplot(152)
flow_u = ax2.imshow(u)
divider = make_axes_locatable(ax2)
cax = divider.append_axes('right', size='5%', pad=0.05)
fig.colorbar(flow_u, cax=cax, orientation='vertical')

ax3 = fig.add_subplot(153)
flow_v = ax3.imshow(v)
divider = make_axes_locatable(ax3)
cax = divider.append_axes('right', size='5%', pad=0.05)
fig.colorbar(flow_v, cax=cax, orientation='vertical')

ax4 = fig.add_subplot(154)
speed = ax4.imshow(s, norm = LogNorm(0.00001, 1))
conts = ax4.contour(s, levels=np.logspace(-5, 0, 12), colors='white', alpha=0.5)
divider = make_axes_locatable(ax4)
cax = divider.append_axes('right', size='5%', pad=0.05)
fig.colorbar(speed, cax=cax, orientation='vertical')

ax5 = fig.add_subplot(155)
u_red = skimage.transform.resize(u, (10, 10))
v_red = skimage.transform.resize(v, (10, 10))
X, Y = np.mgrid[0:500:10j, 0:500:10j]
vec = ax4.quiver(Y, X, u_red, -v_red, scale=0.1, color="white")

plt.tight_layout()

N = 0
t_next = float(open('out/1_p.txt', "r").readline())
def animate(n):
    global N
    global t_next
    global conts
    t = n * 1/FPS
    new_frame = False
    while (t >= t_next):
        t_next = float(open('out/'+str(N+1)+'_p.txt', "r").readline())
        N += 1
        new_frame = True
    if (new_frame):
        print("new frame")
        p = np.genfromtxt('out/'+str(N)+'_p.txt', skip_header=3)[1:500, 1:500]
        u = np.genfromtxt('out/'+str(N)+'_u.txt', skip_header=3)[1:500, 1:500]
        v = np.genfromtxt('out/'+str(N)+'_v.txt', skip_header=3)[1:500, 1:500]
        s = np.sqrt(np.power(u, 2) + np.power(v, 2))
        heat.set_data(p)
        flow_u.set_data(u)
        flow_v.set_data(v)
        speed.set_data(s)
        for coll in conts.collections:
            coll.remove()
        conts = ax4.contour(s, levels=np.logspace(-5, 0, 12), colors='white', alpha=0.5)
        u_red = skimage.transform.resize(u, (10, 10))
        v_red = skimage.transform.resize(v, (10, 10))
        vec.set_UVC(u_red, -v_red)
        new_frame = False
    print(N)

    return heat, flow_u, flow_v, speed, vec

animation = anim.FuncAnimation(fig, animate, frames=10, interval = 16, blit=True)
plt.show()

if (RENDERVID == 1):
	plt.rcParams['animation.ffmpeg_path'] = 'C:/FFmpeg/bin/ffmpeg.exe'	
	mywriter = anim.FFMpegWriter(fps=FPS)
	animation.save('anim.mp4')