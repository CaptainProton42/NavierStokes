/**
 * @file integration.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Implements stencils, calculation of F and G as well as the SOR algorithm.
 */


/**
 * @brief Stencil for \f$\frac{du^2}{dx}\f$.
 * 
 * @param u Velocity grid (x components).
 * @param v Velocity grid (y components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_x Stepsize \f$dx\f$in x direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{du^2}{dx}\f$ at \f$u_{i,j}\f$
 */
double du2_dx(double** u, double** v, int i, int j, double delta_x, double gamma);

/**
 * @brief Stencil for \f$\frac{duv}{dy}\f$.
 * 
 * @param u Velocity grid (x components).
 * @param v Velocity grid (y components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_y Stepsize \f$dy\f$in y direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{duv}{dy}\f$ at \f$u_{i,j}\f$, \f$v_{i,j}\f$.
 */
double duv_dy(double** u, double** v, int i, int j, double delta_y, double gamma);

/**
 * @brief Stencil for \f$\frac{dv^2}{dy}\f$.
 * 
 * @param u Velocity grid (x components).
 * @param v Velocity grid (y components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_x Stepsize \f$dy\f$in y direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{dv^2}{dy}\f$ at \f$v_{i,j}\f$.
 */
double dv2_dy(double** u, double** v, int i, int j, double delta_y, double gamma);

/**
 * @brief Stencil for \f$\frac{duv}{dx}\f$.
 * 
 * @param u Velocity grid (x components).
 * @param v Velocity grid (y components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_x Stepsize \f$dx\f$in x direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{duv}{dx}\f$ at \f$u_{i,j}\f$, \f$v_{i,j}\f$.
 */
double duv_dx(double** u, double** v, int i, int j, double delta_x, double gamma);

/**
 * @brief Stencil for \f$\frac{d^2u}{dx^2}\f$.
 * 
 * @param u Velocity grid (x components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_x Stepsize \f$dx\f$in x direction.

 * 
 * @retun \f$\frac{d^2u}{dx^2}\f$ at \f$u_{i,j}\f$.
 */
double d2u_dx2(double** u, int i, int j, double delta_x);

/**
 * @brief Stencil for \f$\frac{d^2u}{dy^2}\f$.
 * 
 * @param u Velocity grid (x components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_y Stepsize \f$dx\f$in y direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{du^2u}{dy^2}\f$ at \f$u_{i,j}\f$.
 */
double d2u_dy2(double** u, int i, int j, double delta_y);

/**
 * @brief Stencil for \f$\frac{d^2u}{dx^2}\f$.
 * 
 * @param v Velocity grid (y components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_x Stepsize \f$dx\f$in x direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{d^2u}{dx^2}\f$ at \f$v_{i,j}\f$.
 */
double d2v_dx2(double** v, int i, int j, double delta_x);

/**
 * @brief Stencil for \f$\frac{d^2v}{dy^2}\f$.
 * 
 * @param v Velocity grid (y components).
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_y Stepsize \f$dy\f$in y direction.
 * @param gamma Weight factor for Donor-Cell stencil.
 * 
 * @retun \f$\frac{d^2v}{dx^2}\f$ at \f$v_{i,j}\f$
 */
double d2v_dy2(double** v, int i, int j, double delta_y);

/**
 * Calculate F and G terms.
 * 
 * @param F Target array for F.
 * @param G target array for G.
 * @param u Velocity grid (x components).
 * @param v Velocity grid (y components).
 * @param i_max Grid size \f$i_{max}\f$ in i direction.
 * @param i_max Grod size \f$j_{max}\f$ in j direction.
 * @param Re Reynolds number.
 * @param g_x x-component \f$g_x\f$ of gravitational acceleration.
 * @param g_y y-component \f$g_y\f$ of gravitational acceleration.
 * @param delta_t Timestep \f$\delta t\f$.
 * @param delta_x Stepsize \f$\delta x\f$in x direction.
 * @param delta_y Stepsize \f$\delta y\f$in y direction.
 * @param gamma Weight factor \f$\gamma\f$ for Donor-Cell stencil.
 * 
 * @return 0 on success.
 */
int FG(double** F, double** G, double** u, double** v, int i_max, int j_max, double Re, double g_x, double g_y, double delta_t, double delta_x, double delta_y, double gamma);

/**
 * @brief Stencil for \f$\frac{dp}{dx}\f$.
 * 
 * @param p Pressure grid.
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_x Stepsize \f$\delta x\f$in x direction.
 * 
 * @retun \f$\frac{dp}{dx}\f$ at \f$p_{i,j}\f$
 */
double dp_dx(double** p, int i, int j, double delta_x);

/**
 * @brief Stencil for \f$\frac{dp}{dy}\f$.
 * 
 * @param p Pressure grid.
 * @param i Index in x direction.
 * @param j Index in y direction.
 * @param delta_y Stepsize \f$\delta y\f$in y direction.
 * 
 * @retun \f$\frac{dp}{dy}\f$ at \f$p_{i,j}\f$
 */
double dp_dy(double** p, int i, int j, double delta_y);

/**
 * @brief Implements the successive overrelaxation algorithm for calculating new pressure grid.
 */
int SOR(double** p, int i_max, int j_max, double delta_x, double delta_y, double** res, double** RHS, double omega, double eps, int max_it);