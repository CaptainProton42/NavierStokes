/**
 * @file integration.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Stencils.
 */

/**
* @brief Donor-Cell stencil for del u^2/del x
*/
extern double du2_dx(double** u, double** v, int i, int j, double delta_x, double gamma;

extern double duv_dy(double** u, double** v, int i, int j, double delta_y, double gamma);

extern double dv2_dy(double** u, double** v, int i, int j, double delta_y, double gamma);

extern double duv_dx(double** u, double** v, int i, int j, double delta_x, double gamma);

/**
* @brief Central differences for second derivatives.
*/
extern double d2u_dx2(double** u, int i, int j, double delta_x);

extern double d2u_dy2(double** u, int i, int j, double delta_y);

extern double d2v_dx2(double** v, int i, int j, double delta_x);

extern double d2v_dy2(double** v, int i, int j, double delta_y);

extern double F(double** u, double** v, int i, int j, double Re, double g_x, double delta_t, double delta_x, double delta_y, double gamma);

extern double G(double** u, double** v, int i, int j, double Re, double g_y, double delta_t, double delta_x, double delta_y, double gamma);