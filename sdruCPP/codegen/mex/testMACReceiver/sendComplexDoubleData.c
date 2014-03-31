/*
 * sendComplexDoubleData.c
 *
 * Code generation for function 'sendComplexDoubleData'
 *
 * C source code generated on: Thu Mar  6 18:47:07 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testMACReceiver.h"
#include "sendComplexDoubleData.h"
#include "receiveData.h"
#include "PHYReceive.h"
#include "testMACReceiver_mexutil.h"
#include "testMACReceiver_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo kv_emlrtRSI = { 9, "sendComplexDoubleData",
  "/Users/travis/Documents/sdru/usrp_uhd_mapi/sendComplexDoubleData.m" };

/* Function Definitions */
void sendComplexDoubleData(testMACReceiverStackData *SD, const emlrtStack *sp,
  int32_T driverApiH, const creal_T data[38400], real_T freq, real_T loOffset,
  real_T gain, real_T interp, uint32_T *underflow, UsrpErrorCapiEnumT *errStat,
  char_T errStr_data[1024], int32_T errStr_size[2])
{
  const mxArray *y;
  static const int32_T iv183[2] = { 1, 6 };

  const mxArray *m40;
  char_T cv224[6];
  int32_T i;
  static const char_T cv225[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  const mxArray *b_y;
  int32_T loop_ub;
  char_T b_errStr_data[1024];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  bug: must pass as top-level arg */
  /*  dportDtype = DataPortDataTypeCapiEnumT.DPortDTypeCDouble; */
  /*    Copyright 2011-2012 The MathWorks, Inc. */
  st.site = &kv_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2013 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m40 = mxCreateCharArray(2, iv183);
    for (i = 0; i < 6; i++) {
      cv224[i] = cv225[i];
    }

    emlrtInitCharArrayR2013a(&st, 6, m40, cv224);
    emlrtAssign(&y, m40);
    b_st.site = &uv_emlrtRSI;
    setupsdru(&b_st, sdruroot(&b_st, &p_emlrtMCI), y, &q_emlrtMCI);
    isSetupsdruCalled = TRUE;
  }

  /*  These sizes must match those in C code. */
  /*  Arbitrary max imposed on ML/SL side */
  /*  function is being called in interpreted mode */
  /*  not being found:  */
  /*  eml_allow_enum_inputs; */
  /* errStat_i = int32(0); */
  for (i = 0; i < 1024; i++) {
    errStr_data[i] = '\x00';
  }

  memcpy(&SD->u1.f1.data[0], &data[0], 38400U * sizeof(creal_T));
  sendData_c(driverApiH, SD->u1.f1.data, freq, loOffset, gain, interp, underflow,
             errStat, &errStr_data[0]);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  i = strlen(&errStr_data[0]);
  if (i <= 1024) {
  } else {
    b_y = NULL;
    m40 = mxCreateString("Assertion failed.");
    emlrtAssign(&b_y, m40);
    b_st.site = &nv_emlrtRSI;
    c_error(&b_st, b_y, &o_emlrtMCI);
  }

  if (1 > i) {
    loop_ub = 0;
  } else {
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(i, 1, 1024, &y_emlrtBCI, &st);
  }

  for (i = 0; i < loop_ub; i++) {
    b_errStr_data[i] = errStr_data[i];
  }

  errStr_size[0] = 1;
  errStr_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    errStr_data[i] = b_errStr_data[i];
  }
}

/* End of code generation (sendComplexDoubleData.c) */
