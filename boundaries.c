#include "boundaries.h"

int set_noslip(double** u, double** v, int side) {
    return set_inflow(u, v, side, 0, 0);
}

int set_inflow(double** u, double** v, int side, double u_fox, double v_fix) {
    int i, j;
    switch(side) {
        case TOP:
            for (i = 0; i < i_max+2; i++)
    }
}