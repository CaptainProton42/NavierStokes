/**
 * @file integration.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Stencils.
 */

/**
* @brief Donor-Cell stencil for del u^2/del x
*/
double du2_dx(double** u, double** v, int i, int j, double delta_x, double gamma);

double duv_dy(double** u, double** v, int i, int j, double delta_y, double gamma);

double dv2_dy(double** u, double** v, int i, int j, double delta_y, double gamma);

double duv_dx(double** u, double** v, int i, int j, double delta_x, double gamma);

/**
* @brief Central differences for second derivatives.
*/
double d2u_dx2(double** u, int i, int j, double delta_x);

double d2u_dy2(double** u, int i, int j, double delta_y);

double d2v_dx2(double** v, int i, int j, double delta_x);

double d2v_dy2(double** v, int i, int j, double delta_y);

double F(double** u, double** v, int i, int j, double Re, double g_x, double delta_t, double delta_x, double delta_y, double gamma);

double G(double** u, double** v, int i, int j, double Re, double g_y, double delta_t, double delta_x, double delta_y, double gamma);

/**
 * @brief Forward difference stencil for dp/dx.
 */
double dp_dx(double** p, int i, int j, double delta_x);

/**
 * @brief Forward difference stencil for dp/dy.
 */
double dp_dy(double** p, int i, int j, double delta_y);

/**
 * @brief SOR.
 */
int SOR(double** u, double** v, double** p, int i_max, int j_max, double delta_x, double delta_y, double** RHS, double omega, double eps);