/**
 * @file boundaries.h
 * @author Hollweck, Wigg
 * @date 11 April 2019
 * @brief Implements boundary conditions.
 */

#ifndef _BOUNDARIES_H
#define _BOUNDARIES_H

/**
 * @brief Defines the sides of the box.
 */

extern enum {
    TOP = 0,
    BOTTOM = 1,
    LEFT = 2,
    RIGHT = 3
};

/**
 * @brief Set no-slip boundary conditions at the indicated side.
 * 
 * @param u Velocity lattice (x-direction). Expects a two-dimensional array.
 * @param v Velocity lattice (y-direction). Expects a two-dimensional array.
 * @param side Which side to apply the boundary condition to. Should either be \p TOP, \p BOTTOM, \p LEFT, or \p RIGHT.
 * 
 * @return 0 on success.
 */

extern int set_noslip(double** u, double** v, int side);

/**
 * @brief Set inflow boundary conditions at the indicated side.
 * 
 * @param u Velocity lattice (x-direction). Expects a two-dimensional array.
 * @param v Velocity lattice (y-direction). Expects a two-dimensional array.
 * @param side Which side to apply the boundary condition to. Should either be \p TOP, \p BOTTOM, \p LEFT, or \p RIGHT.
 * @param u_fix x-component of the fixed velocity.
 * @param v_fix y-component of the fixed velocity.
 * 
 * @return 0 on success.
 */

extern int set_inflow(double** u, double** v, double u_fix, double v_fix, int side);

#endif