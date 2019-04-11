/**
 * @file boundaries.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Implements boundary conditions.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
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
 * @brief Set no-slip boundary condition at the indicated side.
 * 
 * @param u Velocity lattice (x-direction). Expects a two-dimensional array.
 * @param v Velocity lattice (y-direction). Expects a two-dimensional array.
 * @param side Which side to apply the boundary condition to. Should either be \p TOP, \p BOTTOM, \p LEFT, or \p RIGHT.
 * 
 * @return 0 on success.
 */
extern int set_noslip(double** u, double**v, int side);

#endif