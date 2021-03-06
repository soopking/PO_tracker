/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: IMUFusionCommon.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 01-Mar-2019 15:09:29
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "kal_tool.h"
#include "IMUFusionCommon.h"
#include "mtimes.h"
#include "quaternioncg.h"

/* Function Definitions */

/*
 * Arguments    : const double v[3]
 *                double h[9]
 * Return Type  : void
 */
void IMUFusionCommon_buildHPart(const double v[3], double h[9])
{
  int i6;
  double b_h[9];
  int h_tmp;
  memset(&h[0], 0, 9U * sizeof(double));
  h[3] = v[2];
  h[6] = -v[1];
  h[7] = v[0];
  for (i6 = 0; i6 < 3; i6++) {
    b_h[3 * i6] = h[3 * i6] - h[i6];
    h_tmp = 1 + 3 * i6;
    b_h[h_tmp] = h[h_tmp] - h[i6 + 3];
    h_tmp = 2 + 3 * i6;
    b_h[h_tmp] = h[h_tmp] - h[i6 + 6];
  }

  memcpy(&h[0], &b_h[0], 9U * sizeof(double));
}

/*
 * Arguments    : const double gfast[3]
 *                const double offset[3]
 *                double av[3]
 * Return Type  : void
 */
void c_IMUFusionCommon_computeAngula(const double gfast[3], const double offset
  [3], double av[3])
{
  av[0] = gfast[0] - offset[0];
  av[1] = gfast[1] - offset[1];
  av[2] = gfast[2] - offset[2];
}

/*
 * Arguments    : const c_fusion_internal_coder_ahrsfil *obj
 *                const double gfast[3]
 *                const double offset[3]
 *                c_matlabshared_rotations_intern *qorient
 * Return Type  : void
 */
void c_IMUFusionCommon_predictOrient(const c_fusion_internal_coder_ahrsfil *obj,
  const double gfast[3], const double offset[3], c_matlabshared_rotations_intern
  *qorient)
{
  double c[3];
  double t0_a;
  double t0_b;
  double t0_c;
  double t0_d;
  double d4;
  double d5;
  double d6;
  double d7;
  c[0] = (gfast[0] - offset[0]) * obj->pSensorPeriod;
  c[1] = (gfast[1] - offset[1]) * obj->pSensorPeriod;
  c[2] = (gfast[2] - offset[2]) * obj->pSensorPeriod;
  b_quaternioncg_quaternioncg(c, &t0_a, &t0_b, &t0_c, &t0_d);
  quaternionBase_mtimes(qorient->a, qorient->b, qorient->c, qorient->d, t0_a,
                        t0_b, t0_c, t0_d, &d4, &d5, &d6, &d7);
  qorient->d = d7;
  qorient->c = d6;
  qorient->b = d5;
  qorient->a = d4;
  if (qorient->a < 0.0) {
    qorient->a = -qorient->a;
    qorient->b = -qorient->b;
    qorient->c = -qorient->c;
    qorient->d = -qorient->d;
  }
}

/*
 * File trailer for IMUFusionCommon.c
 *
 * [EOF]
 */
