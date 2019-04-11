/**
 * @file globals.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Global variables that are shared by many components of the programm.
 */

/*Lattice Paramters--------------------------------------------------------------------------------------------------*/

extern int i_max; ///< Lattice dimension in x-direction.
extern int j_max; ///< Lattice dimension in y-direction.

extern double a; ///< Length of grid in x-direction.
extern double b; ///< Length of grid in y-direction.

extern double delx; ///< Length of a cell in x-direction.
extern double dely; ///< Length of a cell in y-direction.
extern double delt; ///< Size of timestep, regulted by stability conditions.

extern double cells_number; ///< Number of cells

/*Physical Parameters-------------------------------------------------------------------------------------------------*/

extern double Re; ///< Reynolds number.
extern double T; /// Overall time.

/*Numerical Paramters-------------------------------------------------------------------------------------------------*/

extern double gamma; ///< Weight for differences.
extern double tau; ///< Security-parameter for adaptive step size, element (0,1].
/* Should probably be both in main.c */

