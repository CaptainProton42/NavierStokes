import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import matplotlib.collections as clt
import matplotlib.patches as ptc
import numpy as np

#constants
FRAMENUM = 100	# number of files/frames to animate
RENDERVID = 1 	# set to 1 for video render (needs ffmpeg and can also take a while)

p = np.genfromtxt("out/0_v.txt")

fig = plt.figure(1, [plt.rcParams["figure.figsize"][0], 3*plt.rcParams["figure.figsize"][1]])


ax1 = fig.add_subplot(121)
heat = ax1.imshow(p)

def animate(n):
    p = np.genfromtxt('out/'+str(n)+'_u.txt')
    heat.set_data(p)
    print(n)

    
    return heat,

animation = anim.FuncAnimation(fig, animate, frames=FRAMENUM+1, interval = 16, blit=True)

if (RENDERVID == 1):
	plt.rcParams['animation.ffmpeg_path'] = 'C:/FFmpeg/bin/ffmpeg.exe'	
	mywriter = anim.FFMpegWriter(fps=20)
	animation.save('anim.mp4')