//
// MATLAB Compiler: 4.18.1 (R2013a)
// Date: Thu Mar 27 00:43:14 2014
// Arguments: "-B" "macro_default" "-W" "cpplib:libReceiver" "-T" "link:lib"
// "-d" "/home/sdruser/git/traviscollins/sdruWiLab/sdruCPP/libReceiver/src"
// "-w" "enable:specified_file_mismatch" "-w" "enable:repeated_file" "-w"
// "enable:switch_ignored" "-w" "enable:missing_lib_sentinel" "-w"
// "enable:demo_license" "-v"
// "/home/sdruser/git/traviscollins/sdruWiLab/sdruCPP/BoardIdCapiEnumT.m"
// "/home/sdruser/git/traviscollins/sdruWiLab/sdruCPP/create_obj.m"
// "/home/sdruser/git/traviscollins/sdruWiLab/sdruCPP/mccTXTest.m" 
//

#include <stdio.h>
#define EXPORTING_libReceiver 1
#include "libReceiver.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libReceiver_C_API
#define LIB_libReceiver_C_API /* No special import/export declaration */
#endif

LIB_libReceiver_C_API 
bool MW_CALL_CONV libReceiverInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(libReceiverInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_libReceiver_C_API 
bool MW_CALL_CONV libReceiverInitialize(void)
{
  return libReceiverInitializeWithHandlers(mclDefaultErrorHandler, 
                                           mclDefaultPrintHandler);
}

LIB_libReceiver_C_API 
void MW_CALL_CONV libReceiverTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_libReceiver_C_API 
void MW_CALL_CONV libReceiverPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libReceiver_C_API 
bool MW_CALL_CONV mlxBoardIdCapiEnumT(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
  return mclFeval(_mcr_inst, "BoardIdCapiEnumT", nlhs, plhs, nrhs, prhs);
}

LIB_libReceiver_C_API 
bool MW_CALL_CONV mlxCreate_obj(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "create_obj", nlhs, plhs, nrhs, prhs);
}

LIB_libReceiver_C_API 
bool MW_CALL_CONV mlxMccTXTest(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "mccTXTest", nlhs, plhs, nrhs, prhs);
}

LIB_libReceiver_CPP_API 
void MW_CALL_CONV BoardIdCapiEnumT(int nargout, mwArray& varargout, const mwArray& 
                                   varargin)
{
  mclcppMlfFeval(_mcr_inst, "BoardIdCapiEnumT", nargout, -1, -1, &varargout, &varargin);
}

LIB_libReceiver_CPP_API 
void MW_CALL_CONV BoardIdCapiEnumT(int nargout, mwArray& varargout)
{
  mclcppMlfFeval(_mcr_inst, "BoardIdCapiEnumT", nargout, -1, 0, &varargout);
}

LIB_libReceiver_CPP_API 
void MW_CALL_CONV BoardIdCapiEnumT(const mwArray& varargin)
{
  mclcppMlfFeval(_mcr_inst, "BoardIdCapiEnumT", 0, 0, -1, &varargin);
}

LIB_libReceiver_CPP_API 
void MW_CALL_CONV BoardIdCapiEnumT()
{
  mclcppMlfFeval(_mcr_inst, "BoardIdCapiEnumT", 0, 0, 0);
}

LIB_libReceiver_CPP_API 
void MW_CALL_CONV create_obj(int nargout, mwArray& ObjSDRuReceiver)
{
  mclcppMlfFeval(_mcr_inst, "create_obj", nargout, 1, 0, &ObjSDRuReceiver);
}

LIB_libReceiver_CPP_API 
void MW_CALL_CONV mccTXTest(int nargout, mwArray& value)
{
  mclcppMlfFeval(_mcr_inst, "mccTXTest", nargout, 1, 0, &value);
}

