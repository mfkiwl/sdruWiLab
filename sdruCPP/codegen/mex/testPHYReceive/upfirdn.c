/*
 * upfirdn.c
 *
 * Code generation for function 'upfirdn'
 *
 * C source code generated on: Thu Feb 27 11:53:20 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testPHYReceive.h"
#include "upfirdn.h"
#include "FIRRateConverter.h"
#include "setup.h"
#include "SystemCore.h"

/* Variable Definitions */
static emlrtRSInfo dt_emlrtRSI = { 147, "upfirdn",
  "/Applications/MATLAB_R2013b.app/toolbox/signal/eml/upfirdn.m" };

static emlrtRSInfo et_emlrtRSI = { 150, "upfirdn",
  "/Applications/MATLAB_R2013b.app/toolbox/signal/eml/upfirdn.m" };

static emlrtRSInfo ft_emlrtRSI = { 151, "upfirdn",
  "/Applications/MATLAB_R2013b.app/toolbox/signal/eml/upfirdn.m" };

/* Function Definitions */
void upfirdn(testPHYReceiveStackData *SD, const emlrtStack *sp, const creal_T
             x_in[48], creal_T y_out[3336])
{
  dspcodegen_FIRRateConverter s;
  creal_T b_x_in[288];
  int32_T i24;
  int32_T i25;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dt_emlrtRSI;
  c_FIRRateConverter_FIRRateConve(&s);
  for (i24 = 0; i24 < 12; i24++) {
    memcpy(&b_x_in[24 * i24], &x_in[i24 << 2], sizeof(creal_T) << 2);
    for (i25 = 0; i25 < 20; i25++) {
      b_x_in[(i25 + 24 * i24) + 4].re = 0.0;
      b_x_in[(i25 + 24 * i24) + 4].im = 0.0;
    }
  }

  st.site = &et_emlrtRSI;
  h_SystemCore_step(&st, &s, b_x_in, SD->u1.f0.y);
  st.site = &ft_emlrtRSI;
  SystemCore_reset(&st, &s);
  for (i24 = 0; i24 < 12; i24++) {
    memcpy(&y_out[278 * i24], &SD->u1.f0.y[288 * i24], 278U * sizeof(creal_T));
  }

  st.site = NULL;
  c_Destructor(&s.cSFunObject);
}

/* End of code generation (upfirdn.c) */
