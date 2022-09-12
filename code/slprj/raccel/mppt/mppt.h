#ifndef RTW_HEADER_mppt_h_
#define RTW_HEADER_mppt_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef mppt_COMMON_INCLUDES_
#define mppt_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "mppt_types.h"
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME mppt
#define NSAMPLE_TIMES (6) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (28) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (1)   
#elif NCSTATES != 1
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T eoykqgypkt ; real_T jopktmihot [ 9 ] ; real_T
n15cgb4yht [ 3 ] ; real_T bc3skupnjv ; real_T f3yjek5puc ; real_T fperphbavh
; real_T chdpbe0cay ; real_T dirh3ywup1 ; real_T lmf3u53ao5 ; real_T
jnk3ibzm4f ; real_T pzedvpmf2h ; real_T m4snnhwc45 ; real_T gispy1xujc ;
real_T fjss0ng3xl ; real_T jadzw0spnk ; real_T pihfv1mtox ; real_T hcm5iot1rh
; real_T ayriaun35r ; real_T aidbb0sgmz ; real_T evafcok2q3 ; real_T
nninjdfplf ; real_T p0lbzyb3dc ; real_T b3zwkh0dgw ; real_T ly5gnycfej ;
real_T fblwnhebsb ; real_T epnatzrvj4 ; real_T johdxn5bii ; boolean_T
k5qby3mrmb ; } B ; typedef struct { real_T nceg4tx0wh ; real_T ppd4rroocm [ 4
] ; struct { void * AS ; void * BS ; void * CS ; void * DS ; void * DX_COL ;
void * BD_COL ; void * TMP1 ; void * TMP2 ; void * XTMP ; void *
SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ;
void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ;
void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW
; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } egeoeejxx2 ; struct {
void * LoggedData [ 5 ] ; } i3d4cnqyko ; int_T oqpntcgch1 [ 11 ] ; int_T
kxzljsksxj ; int_T ixyl3zymd1 ; boolean_T dbxce5ttyk ; boolean_T dd11cic03n ;
} DW ; typedef struct { real_T odij3xombl ; } X ; typedef struct { real_T
odij3xombl ; } XDot ; typedef struct { boolean_T odij3xombl ; } XDis ;
typedef struct { real_T odij3xombl ; } CStateAbsTol ; typedef struct { real_T
odij3xombl ; } CXPtMin ; typedef struct { real_T odij3xombl ; } CXPtMax ;
typedef struct { real_T dzm42p1kvw ; real_T pqgfckdco2 ; real_T km3v55ivyx ;
real_T icmemvdiuq ; real_T gp4u5mcpqd ; real_T fnsmg4qlwu ; } ZCV ; typedef
struct { ZCSigState eh5sfnx2ar ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
PIDController_I ; real_T PIDController_InitialConditionForIntegrator ; real_T
PIDController_LowerSaturationLimit ; real_T PVArray_Npar ; real_T
PIDController_P ; real_T PIDController_UpperSaturationLimit ; real_T
Constant_Value ; real_T UnitDelay_InitialCondition ; real_T
StateSpace_AS_param [ 16 ] ; real_T StateSpace_BS_param [ 24 ] ; real_T
StateSpace_CS_param [ 36 ] ; real_T StateSpace_DS_param [ 54 ] ; real_T
StateSpace_X0_param [ 4 ] ; real_T donotdeletethisgain_Gain ; real_T
donotdeletethisgain_Gain_hjp2jqttbc ; real_T
donotdeletethisgain_Gain_fvxcttqcfp ; real_T
donotdeletethisgain_Gain_gnwiijihcw ; real_T Gain_Gain ; real_T
Constant4_Value ; real_T Constant2_Value ; real_T uib2_Gain ; real_T
donotdeletethisgain_Gain_amefm0x4hn ; real_T
donotdeletethisgain_Gain_geemqka3jr ; real_T HitCrossing_Offset ; real_T
SwitchCurrents_Value [ 3 ] ; real_T Constant_Value_c5r2ow4pnn ; real_T
Constant2_Value_j0j5kt5zqt ; real_T u_K_Value ; real_T uSref_Gain ; real_T
Tref_K_Value ; real_T alpha_Isc_Gain ; real_T IL_module_Value ; real_T
Rs_array_Value ; real_T one1_Value ; real_T Tref_K1_Value ; real_T dEgdT_Gain
; real_T EgRef_Gain ; real_T Tref_K2_Value ; real_T I0_array_Gain ; real_T
EgRef_Value ; real_T k1_Gain ; real_T Rsh_array_Value ; real_T
Rsh_array_5Sref_Value ; real_T VT_ref_array_Gain ; real_T one_Value ; real_T
Constant1_Value ; real_T eee_Value ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * mppt_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
