Done as work for university, the aim of this project is to implement a numeric solver for the Navier-Stokes equation for incompresible fluid flow using the method of finite differences. It is based on material handed out by the university which in return is mainly based on Griebel et al., 1998: **Numerical Simulation in Fluid Dynamics**. We implement the lid-driven cavity problem as a benchmark for our code and compare the results to those presented by Ghia et al., 1982: **"High-Re solutions for incompressible flow using the Navier-Stokes equations and a multigrid method**. Lastly, we also experimented with rectangular box shapes and periodically oscillating boundary conditions.

![](media/flow_100.gif)
![](media/pressure_100.gif)

<img width="45%" src="media/ghia_u.png"> <img width="45%" src="media/ghia_v.png">

![](media/flow_10K_vortex.gif)
![](media/pressure_10K_vortex.gif)

# Building

The included makefile should work with gcc out of the box. Simply type `make` to start the build. For other compilers you need to compile by yourself.

# Parameters and Running

`parameters.txt` stores all necessary information to run a simulation. The file is comented so any adjustments you'd want to make should be self-explanatory. A simulation can be run by executing `main`, just type `./main`. Plots can be created via the included `.py` scripts. The scripts might need to be tweaked depending on your simulation parameters but are also commented.
