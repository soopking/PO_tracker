/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rotmat.c
 *
 * Code generation for function 'rotmat'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "kal_tool.h"
#include "rotmat.h"

/* Function Definitions */
void quaternionBase_rotmat(double q_a, double q_b, double q_c, double q_d,
  double r[9])
{
  double n;
  double ac2;
  double ad2;
  double bc2;
  double bd2;
  double cd2;
  double aasq;
  n = sqrt(((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d * q_d);
  q_a /= n;
  q_b /= n;
  q_c /= n;
  q_d /= n;
  n = q_a * q_b * 2.0;
  ac2 = q_a * q_c * 2.0;
  ad2 = q_a * q_d * 2.0;
  bc2 = q_b * q_c * 2.0;
  bd2 = q_b * q_d * 2.0;
  cd2 = q_c * q_d * 2.0;
  aasq = q_a * q_a * 2.0 - 1.0;
  r[0] = aasq + q_b * q_b * 2.0;
  r[3] = bc2 + ad2;
  r[6] = bd2 - ac2;
  r[1] = bc2 - ad2;
  r[4] = aasq + q_c * q_c * 2.0;
  r[7] = cd2 + n;
  r[2] = bd2 + ac2;
  r[5] = cd2 - n;
  r[8] = aasq + q_d * q_d * 2.0;
}

/* End of code generation (rotmat.c) */
