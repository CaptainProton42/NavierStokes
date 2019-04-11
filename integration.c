/**
 * @brief Donor-Cell stencil for del u^2/del x.
 */

double du2_dx(double** u, double** v, int i, int j, double delta_x, double gamma) {
    double stencil1 = 0.5 * (u[i][j] + u[i+1][j]);
    double stencil2 = 0.5 * (u[i-1][j] + u[i][j]);

    double stencil3 = abs(stencil1) * 0.5 * (u[i][j] - u[i+1][j]);
    double stencil4 = abs(stencil2) * 0.5 * (u[i-1][j] - u[i][j]);

    return 1/delta_x * (stencil1*stencil1 - stencil2*stencil2) + gamma / delta_x * (stencil3 - stencil4);
}

double duv_dy(double** u, double** v, int i, int j, double delta_y, double gamma) {
    double stencil1 = 0.5 * (v[i][j] + v[i+1][j]);
    double stencil2 = 0.5 * (v[i][j-1] + v[i+1][j-1]);

    double stencil3 = stencil1 * 0.5 * (u[i][j] + u[i][j+1]);
    double stencil4 = stencil2 * 0.5 * (u[i][j-1] + u[i][j]);

    double stencil5 = abs(stencil1) * 0.5 * (u[i][j] - u[i][j+1]);
    double stencil6 = abs(stencil2) * 0.5 * (u[i][j-1] - u[i][j]);

    return 1/delta_y * (stencil3 - stencil4) + gamma / delta_y * (stencil5 - stencil6);
}

double dv2_dy(double** u, double** v, int i, int j, double delta_y, double gamma) {
    double stencil1 = 0.5 * (v[i][j] + v[i][j+1]);
    double stencil2 = 0.5 * (v[i][j-1] + v[i][j]);

    double stencil3 = abs(stencil1) * 0.5 * (v[i][j] - v[i][j+1]);
    double stencil4 = abs(stencil2) * 0.5 * (v[i][j-1] - v[i][j]);

    return 1/delta_y * (stencil1*stencil1 - stencil2*stencil2) + gamma / delta_y * (stencil3 - stencil4);
}

double duv_dx(double** u, double** v, int i, int j, double delta_x, double gamma) {
    double stencil1 = 0.5 * (u[i][j] + u[i][j+1]);
    double stencil2 = 0.5 * (u[i-1][j] + u[i-1][j+1]);

    double stencil3 = stencil1 * 0.5 * (v[i][j] + v[i+1][j]);
    double stencil4 = stencil2 * 0.5 * (v[i-1][j] + v[i][j]);

    double stencil5 = abs(stencil1) * 0.5 * (v[i][j] - v[i+1][j]);
    double stencil6 = abs(stencil2) * 0.5 * (v[-1][j] - v[i][j]);

    return 1/delta_x * (stencil3 - stencil4) + gamma / delta_x * (stencil5 - stencil6);
}

/**
 * @brief Central differences for second derivatives.
 */

double d2u_dx2(double** u, int i, int j, double delta_x) {
    return (u[i+1][j] - 2 * u[i][j] + u[i-1][j]) / (delta_x*delta_x);
}

double d2u_dy2(double** u, int i, int j, double delta_y) {
    return (u[i][j+1] - 2 * u[i][j] + u[i][j-1]) / (delta_y*delta_y);
}

double d2v_dx2(double** v, int i, int j, double delta_x) {
    return (v[i+1][j] - 2 * v[i][j] + v[i-1][j]) / (delta_x*delta_x);
}

double d2v_dy2(double** v, int i, int j, double delta_y) {
    return (v[i][j+1] - 2 * v[i][j] + v[i][j-1]) / (delta_y*delta_y);
}

double F(double** u, double** v, int i, int j, double Re, double g_x, double delta_t, double delta_x, double delta_y, double gamma) {
    return u[i][j] +
            delta_t * (1/Re * (d2u_dx2(u, i, j, delta_x) +
             d2u_dy2(u, i, j, delta_y)) -
             du2_dx(u, v, i, j, delta_x, gamma) -
             duv_dy(u, v, i, j, delta_y, gamma) +
             g_x);
}

double G(double** u, double** v, int i, int j, double Re, double g_y, double delta_t, double delta_x, double delta_y, double gamma) {
    return v[i][j] +
            delta_t * (1/Re * (d2v_dx2(v, i, j, delta_x) +
             d2v_dy2(v, i, j, delta_y)) -
             duv_dx(u, v, i, j, delta_x, gamma) -
             dv2_dy(u, v, i, j, delta_y, gamma) +
             g_y);
}