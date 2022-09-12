#include "rt_logging_mmi.h"
#include "mppt_capi.h"
#include <math.h>
#include "mppt.h"
#include "mppt_private.h"
#include "mppt_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 5 , & stopRequested ) ; }
rtExtModeShutdown ( 5 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 6 ; const char_T
* gbl_raccel_Version = "9.3 (R2020a) 18-Nov-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\mppt\\mppt_Jpattern.mat" ; const int_T gblNumRootInportBlks =
0 ; const int_T gblNumModelInputs = 0 ; extern rtInportTUtable *
gblInportTUtables ; extern const char * gblInportFileName ; extern void *
gblAperiodicPartitionHitTimes ; const int_T gblInportDataTypeIdx [ ] = { - 1
} ; const int_T gblInportDims [ ] = { - 1 } ; const int_T gblInportComplex [
] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1 } ; const int_T
gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1
, 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( const
char * inportFileName , int * matFileFormat ) { return
rt_RapidReadInportsMatFile ( inportFileName , matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; void MdlInitialize ( void ) { rtDW .
nceg4tx0wh = rtP . UnitDelay_InitialCondition ; { int32_T i , j ; real_T * As
= ( real_T * ) rtDW . egeoeejxx2 . AS ; real_T * Bs = ( real_T * ) rtDW .
egeoeejxx2 . BS ; real_T * Cs = ( real_T * ) rtDW . egeoeejxx2 . CS ; real_T
* Ds = ( real_T * ) rtDW . egeoeejxx2 . DS ; real_T * X0 = ( real_T * ) &
rtDW . ppd4rroocm [ 0 ] ; for ( i = 0 ; i < 4 ; i ++ ) { X0 [ i ] = ( rtP .
StateSpace_X0_param [ i ] ) ; } for ( i = 0 ; i < 4 ; i ++ ) { for ( j = 0 ;
j < 4 ; j ++ ) As [ i * 4 + j ] = ( rtP . StateSpace_AS_param [ i + j * 4 ] )
; for ( j = 0 ; j < 6 ; j ++ ) Bs [ i * 6 + j ] = ( rtP . StateSpace_BS_param
[ i + j * 4 ] ) ; } for ( i = 0 ; i < 9 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++
) Cs [ i * 4 + j ] = ( rtP . StateSpace_CS_param [ i + j * 9 ] ) ; } for ( i
= 0 ; i < 9 ; i ++ ) { for ( j = 0 ; j < 6 ; j ++ ) Ds [ i * 6 + j ] = ( rtP
. StateSpace_DS_param [ i + j * 9 ] ) ; } { int_T * switch_status = ( int_T *
) rtDW . egeoeejxx2 . SWITCH_STATUS ; int_T * gState = ( int_T * ) rtDW .
egeoeejxx2 . G_STATE ; real_T * yswitch = ( real_T * ) rtDW . egeoeejxx2 .
Y_SWITCH ; int_T * switchTypes = ( int_T * ) rtDW . egeoeejxx2 . SWITCH_TYPES
; int_T * idxOutSw = ( int_T * ) rtDW . egeoeejxx2 . IDX_OUT_SW ; int_T *
switch_status_init = ( int_T * ) rtDW . egeoeejxx2 . SWITCH_STATUS_INIT ;
switch_status [ 0 ] = 0 ; switch_status_init [ 0 ] = 0 ; gState [ 0 ] = (
int_T ) 0.0 ; yswitch [ 0 ] = 1 / 0.1 ; switchTypes [ 0 ] = ( int_T ) 1.0 ;
idxOutSw [ 0 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 1 ] = 0 ;
switch_status_init [ 1 ] = 0 ; gState [ 1 ] = ( int_T ) 0.0 ; yswitch [ 1 ] =
1 / 0.001 ; switchTypes [ 1 ] = ( int_T ) 3.0 ; idxOutSw [ 1 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 2 ] = 0 ; switch_status_init [ 2 ] = 0 ; gState [
2 ] = ( int_T ) 0.0 ; yswitch [ 2 ] = 1 / 0.01 ; switchTypes [ 2 ] = ( int_T
) 3.0 ; idxOutSw [ 2 ] = ( ( int_T ) 0.0 ) - 1 ; } } rtX . odij3xombl = rtP .
PIDController_InitialConditionForIntegrator ; } void MdlStart ( void ) { {
void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL )
; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize =
16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { rtDW . egeoeejxx2 . AS = ( real_T *
) calloc ( 4 * 4 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . BS = ( real_T *
) calloc ( 4 * 6 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . CS = ( real_T *
) calloc ( 9 * 4 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . DS = ( real_T *
) calloc ( 9 * 6 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . DX_COL = (
real_T * ) calloc ( 9 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . TMP2 = (
real_T * ) calloc ( 6 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . BD_COL = (
real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . TMP1 = (
real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 . XTMP = (
real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW . egeoeejxx2 .
SWITCH_STATUS = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ; rtDW .
egeoeejxx2 . SW_CHG = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ; rtDW .
egeoeejxx2 . G_STATE = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ; rtDW .
egeoeejxx2 . Y_SWITCH = ( real_T * ) calloc ( 3 , sizeof ( real_T ) ) ; rtDW
. egeoeejxx2 . SWITCH_TYPES = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ;
rtDW . egeoeejxx2 . IDX_OUT_SW = ( int_T * ) calloc ( 3 , sizeof ( int_T ) )
; rtDW . egeoeejxx2 . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 3 , sizeof (
int_T ) ) ; rtDW . egeoeejxx2 . USWLAST = ( real_T * ) calloc ( 3 , sizeof (
real_T ) ) ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) {
ZCEventType zcEvent ; real_T j1tuicgszr ; boolean_T bfhlbi3nnh ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . eoykqgypkt = rtDW . nceg4tx0wh ; {
real_T accum ; int_T * switch_status = ( int_T * ) rtDW . egeoeejxx2 .
SWITCH_STATUS ; int_T * switch_status_init = ( int_T * ) rtDW . egeoeejxx2 .
SWITCH_STATUS_INIT ; int_T * SwitchChange = ( int_T * ) rtDW . egeoeejxx2 .
SW_CHG ; int_T * gState = ( int_T * ) rtDW . egeoeejxx2 . G_STATE ; real_T *
yswitch = ( real_T * ) rtDW . egeoeejxx2 . Y_SWITCH ; int_T * switchTypes = (
int_T * ) rtDW . egeoeejxx2 . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * )
rtDW . egeoeejxx2 . IDX_OUT_SW ; real_T * DxCol = ( real_T * ) rtDW .
egeoeejxx2 . DX_COL ; real_T * tmp2 = ( real_T * ) rtDW . egeoeejxx2 . TMP2 ;
real_T * BDcol = ( real_T * ) rtDW . egeoeejxx2 . BD_COL ; real_T * tmp1 = (
real_T * ) rtDW . egeoeejxx2 . TMP1 ; real_T * uswlast = ( real_T * ) rtDW .
egeoeejxx2 . USWLAST ; int_T newState ; int_T swChanged = 0 ; int loopsToDo =
20 ; real_T temp ; memcpy ( switch_status_init , switch_status , 3 * sizeof (
int_T ) ) ; memcpy ( uswlast , & rtB . jopktmihot [ 0 ] , 3 * sizeof ( real_T
) ) ; do { if ( loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0
; i1 < 3 ; i1 ++ ) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init
[ i1 ] - switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ]
= switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
egeoeejxx2 . CS ; real_T * Ds = ( real_T * ) rtDW . egeoeejxx2 . DS ; { int_T
i1 ; real_T * y0 = & rtB . jopktmihot [ 0 ] ; for ( i1 = 0 ; i1 < 9 ; i1 ++ )
{ accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . ppd4rroocm [ 0 ] ; accum += * (
Cs ++ ) * rtDW . ppd4rroocm [ 1 ] ; accum += * ( Cs ++ ) * rtDW . ppd4rroocm
[ 2 ] ; accum += * ( Cs ++ ) * rtDW . ppd4rroocm [ 3 ] ; accum += * ( Ds ++ )
* rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Ds ++ ) * rtB . fblwnhebsb ; accum
+= * ( Ds ++ ) * rtB . eoykqgypkt ; accum += * ( Ds ++ ) * rtP . eee_Value ;
y0 [ i1 ] = accum ; } } swChanged = 0 ; newState = gState [ 0 ] > 0 ? 1 : 0 ;
swChanged = ( ( SwitchChange [ 0 ] = newState - switch_status [ 0 ] ) != 0 )
? 1 : swChanged ; switch_status [ 0 ] = newState ; newState = rtB .
jopktmihot [ 1 ] > 0.0 ? 1 : ( ( rtB . jopktmihot [ 1 ] < 0.0 ) ? 0 :
switch_status [ 1 ] ) ; swChanged = ( ( SwitchChange [ 1 ] = newState -
switch_status [ 1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ 1 ] = newState
; newState = rtB . jopktmihot [ 2 ] > 0.0 ? 1 : ( ( rtB . jopktmihot [ 2 ] <
0.0 ) ? 0 : switch_status [ 2 ] ) ; swChanged = ( ( SwitchChange [ 2 ] =
newState - switch_status [ 2 ] ) != 0 ) ? 1 : swChanged ; switch_status [ 2 ]
= newState ; } if ( swChanged ) { real_T * As = ( real_T * ) rtDW .
egeoeejxx2 . AS ; real_T * Cs = ( real_T * ) rtDW . egeoeejxx2 . CS ; real_T
* Bs = ( real_T * ) rtDW . egeoeejxx2 . BS ; real_T * Ds = ( real_T * ) rtDW
. egeoeejxx2 . DS ; real_T a1 ; { int_T i1 ; for ( i1 = 0 ; i1 < 3 ; i1 ++ )
{ if ( SwitchChange [ i1 ] != 0 ) { a1 = yswitch [ i1 ] * SwitchChange [ i1 ]
; temp = 1 / ( 1 - Ds [ i1 * 7 ] * a1 ) ; { int_T i2 ; for ( i2 = 0 ; i2 < 9
; i2 ++ ) { DxCol [ i2 ] = Ds [ i2 * 6 + i1 ] * temp * a1 ; } } DxCol [ i1 ]
= temp ; BDcol [ 0 ] = Bs [ 0 + i1 ] * a1 ; BDcol [ 1 ] = Bs [ 6 + i1 ] * a1
; BDcol [ 2 ] = Bs [ 12 + i1 ] * a1 ; BDcol [ 3 ] = Bs [ 18 + i1 ] * a1 ;
memcpy ( tmp1 , & Cs [ i1 * 4 ] , 4 * sizeof ( real_T ) ) ; memset ( & Cs [
i1 * 4 ] , '\0' , 4 * sizeof ( real_T ) ) ; memcpy ( tmp2 , & Ds [ i1 * 6 ] ,
6 * sizeof ( real_T ) ) ; memset ( & Ds [ i1 * 6 ] , '\0' , 6 * sizeof (
real_T ) ) ; { int_T i2 ; for ( i2 = 0 ; i2 < 9 ; i2 ++ ) { a1 = DxCol [ i2 ]
; Cs [ i2 * 4 + 0 ] += a1 * tmp1 [ 0 ] ; Cs [ i2 * 4 + 1 ] += a1 * tmp1 [ 1 ]
; Cs [ i2 * 4 + 2 ] += a1 * tmp1 [ 2 ] ; Cs [ i2 * 4 + 3 ] += a1 * tmp1 [ 3 ]
; { int_T i3 ; for ( i3 = 0 ; i3 < 6 ; i3 ++ ) { Ds [ i2 * 6 + i3 ] += a1 *
tmp2 [ i3 ] ; } } } } a1 = BDcol [ 0 ] ; As [ 0 + 0 ] += a1 * Cs [ i1 * 4 + 0
] ; As [ 0 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 0 + 2 ] += a1 * Cs [ i1 * 4
+ 2 ] ; As [ 0 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ;
i2 < 6 ; i2 ++ ) { Bs [ 0 + i2 ] += a1 * Ds [ i1 * 6 + i2 ] ; } } a1 = BDcol
[ 1 ] ; As [ 4 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 4 + 1 ] += a1 * Cs [ i1
* 4 + 1 ] ; As [ 4 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 4 + 3 ] += a1 * Cs
[ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { Bs [ 6 + i2 ]
+= a1 * Ds [ i1 * 6 + i2 ] ; } } a1 = BDcol [ 2 ] ; As [ 8 + 0 ] += a1 * Cs [
i1 * 4 + 0 ] ; As [ 8 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 8 + 2 ] += a1 *
Cs [ i1 * 4 + 2 ] ; As [ 8 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for
( i2 = 0 ; i2 < 6 ; i2 ++ ) { Bs [ 12 + i2 ] += a1 * Ds [ i1 * 6 + i2 ] ; } }
a1 = BDcol [ 3 ] ; As [ 12 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 12 + 1 ] +=
a1 * Cs [ i1 * 4 + 1 ] ; As [ 12 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 12 +
3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ )
{ Bs [ 18 + i2 ] += a1 * Ds [ i1 * 6 + i2 ] ; } } } } } } } while ( swChanged
> 0 && -- loopsToDo > 0 ) ; if ( loopsToDo == 0 ) { real_T * Cs = ( real_T *
) rtDW . egeoeejxx2 . CS ; real_T * Ds = ( real_T * ) rtDW . egeoeejxx2 . DS
; { int_T i1 ; real_T * y0 = & rtB . jopktmihot [ 0 ] ; for ( i1 = 0 ; i1 < 9
; i1 ++ ) { accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . ppd4rroocm [ 0 ] ;
accum += * ( Cs ++ ) * rtDW . ppd4rroocm [ 1 ] ; accum += * ( Cs ++ ) * rtDW
. ppd4rroocm [ 2 ] ; accum += * ( Cs ++ ) * rtDW . ppd4rroocm [ 3 ] ; accum
+= * ( Ds ++ ) * rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) *
rtP . SwitchCurrents_Value [ 1 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Ds ++ ) * rtB . fblwnhebsb ; accum
+= * ( Ds ++ ) * rtB . eoykqgypkt ; accum += * ( Ds ++ ) * rtP . eee_Value ;
y0 [ i1 ] = accum ; } } } rtB . n15cgb4yht [ 0 ] = ( real_T ) switch_status [
0 ] ; rtB . n15cgb4yht [ 1 ] = ( real_T ) switch_status [ 1 ] ; rtB .
n15cgb4yht [ 2 ] = ( real_T ) switch_status [ 2 ] ; } rtB . bc3skupnjv = rtP
. donotdeletethisgain_Gain * rtB . jopktmihot [ 5 ] ; rtB . f3yjek5puc = rtP
. donotdeletethisgain_Gain_hjp2jqttbc * rtB . jopktmihot [ 8 ] ; j1tuicgszr =
rtB . f3yjek5puc * rtP . Rs_array_Value + rtB . bc3skupnjv ; rtB . fperphbavh
= ( muDoubleScalarExp ( 1.0 / rtB . johdxn5bii * j1tuicgszr ) - rtP .
one_Value ) * rtB . epnatzrvj4 ; rtB . chdpbe0cay = ( j1tuicgszr / rtP .
Rsh_array_Value * rtB . ly5gnycfej + rtB . fperphbavh ) - j1tuicgszr / rtP .
Rsh_array_5Sref_Value ; rtB . dirh3ywup1 = rtP .
donotdeletethisgain_Gain_fvxcttqcfp * rtB . jopktmihot [ 7 ] ; rtB .
lmf3u53ao5 = rtP . donotdeletethisgain_Gain_gnwiijihcw * rtB . jopktmihot [ 4
] ; j1tuicgszr = ( rtP . Constant1_Value - rtB . lmf3u53ao5 ) * rtP .
Gain_Gain ; rtB . jnk3ibzm4f = rtP . PIDController_P * j1tuicgszr ; } rtB .
pzedvpmf2h = rtX . odij3xombl ; rtB . m4snnhwc45 = rtB . jnk3ibzm4f + rtB .
pzedvpmf2h ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . kxzljsksxj = rtB .
m4snnhwc45 >= rtP . PIDController_UpperSaturationLimit ? 1 : rtB . m4snnhwc45
> rtP . PIDController_LowerSaturationLimit ? 0 : - 1 ; } rtB . gispy1xujc =
rtDW . kxzljsksxj == 1 ? rtP . PIDController_UpperSaturationLimit : rtDW .
kxzljsksxj == - 1 ? rtP . PIDController_LowerSaturationLimit : rtB .
m4snnhwc45 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . dbxce5ttyk = ( rtB . gispy1xujc != rtP . Constant_Value ) ;
} bfhlbi3nnh = rtDW . dbxce5ttyk ; rtB . fjss0ng3xl = rtP . Constant4_Value ;
rtB . jadzw0spnk = rtP . Constant2_Value ; } rtB . pihfv1mtox =
muDoubleScalarRem ( ssGetT ( rtS ) + rtB . fjss0ng3xl , rtB . jadzw0spnk ) *
rtP . uib2_Gain ; rtB . hcm5iot1rh = ( ( 2.0 * rtB . pihfv1mtox - 1.0 ) + 1.0
) * 0.5 ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . aidbb0sgmz = rtP .
donotdeletethisgain_Gain_amefm0x4hn * rtB . jopktmihot [ 6 ] ; rtB .
evafcok2q3 = rtP . donotdeletethisgain_Gain_geemqka3jr * rtB . jopktmihot [ 3
] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . dd11cic03n = ( rtB . gispy1xujc >= rtB . hcm5iot1rh ) ; } rtB .
ayriaun35r = ( bfhlbi3nnh && rtDW . dd11cic03n ) ; } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { rtB . nninjdfplf = rtP . PIDController_I * j1tuicgszr ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { zcEvent = rt_ZCFcn ( ANY_ZERO_CROSSING , &
rtPrevZCX . eh5sfnx2ar , ( rtB . pihfv1mtox - rtP . HitCrossing_Offset ) ) ;
if ( rtDW . ixyl3zymd1 == 0 ) { if ( zcEvent != NO_ZCEVENT ) { rtB .
k5qby3mrmb = ! rtB . k5qby3mrmb ; rtDW . ixyl3zymd1 = 1 ; } else if ( rtB .
k5qby3mrmb ) { rtB . k5qby3mrmb = ( ( ! ( rtB . pihfv1mtox != rtP .
HitCrossing_Offset ) ) && rtB . k5qby3mrmb ) ; } else { rtB . k5qby3mrmb = (
( rtB . pihfv1mtox == rtP . HitCrossing_Offset ) || rtB . k5qby3mrmb ) ; } }
else { rtB . k5qby3mrmb = ( ( ! ( rtB . pihfv1mtox != rtP .
HitCrossing_Offset ) ) && rtB . k5qby3mrmb ) ; rtDW . ixyl3zymd1 = 0 ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID5 ( int_T tid ) { real_T
fbcaovypsv ; real_T jtutr0iajt ; rtB . p0lbzyb3dc = rtP .
Constant_Value_c5r2ow4pnn ; rtB . b3zwkh0dgw = rtP .
Constant2_Value_j0j5kt5zqt ; rtB . ly5gnycfej = rtP . uSref_Gain * rtB .
p0lbzyb3dc ; fbcaovypsv = rtB . b3zwkh0dgw + rtP . u_K_Value ; rtB .
fblwnhebsb = ( ( fbcaovypsv - rtP . Tref_K_Value ) * rtP . alpha_Isc_Gain +
rtP . IL_module_Value ) * rtP . PVArray_Npar * rtB . ly5gnycfej ; jtutr0iajt
= fbcaovypsv / rtP . Tref_K2_Value ; rtB . epnatzrvj4 = muDoubleScalarExp (
rtP . EgRef_Value - ( ( fbcaovypsv - rtP . Tref_K1_Value ) * rtP . dEgdT_Gain
+ rtP . one1_Value ) * rtP . EgRef_Gain / ( rtP . k1_Gain * fbcaovypsv ) ) *
( rtP . I0_array_Gain * muDoubleScalarPower ( jtutr0iajt , 3.0 ) ) ; rtB .
johdxn5bii = rtP . VT_ref_array_Gain * jtutr0iajt ; UNUSED_PARAMETER ( tid )
; } void MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
rtDW . nceg4tx0wh = rtB . chdpbe0cay ; { const real_T * As = ( real_T * )
rtDW . egeoeejxx2 . AS ; const real_T * Bs = ( real_T * ) rtDW . egeoeejxx2 .
BS ; real_T * xtmp = ( real_T * ) rtDW . egeoeejxx2 . XTMP ; real_T accum ;
accum = 0.0 ; accum += * ( As ++ ) * rtDW . ppd4rroocm [ 0 ] ; accum += * (
As ++ ) * rtDW . ppd4rroocm [ 1 ] ; accum += * ( As ++ ) * rtDW . ppd4rroocm
[ 2 ] ; accum += * ( As ++ ) * rtDW . ppd4rroocm [ 3 ] ; accum += * ( Bs ++ )
* ( rtP . SwitchCurrents_Value [ 0 ] ) ; accum += * ( Bs ++ ) * ( rtP .
SwitchCurrents_Value [ 1 ] ) ; accum += * ( Bs ++ ) * ( rtP .
SwitchCurrents_Value [ 2 ] ) ; accum += * ( Bs ++ ) * rtB . fblwnhebsb ;
accum += * ( Bs ++ ) * rtB . eoykqgypkt ; accum += * ( Bs ++ ) * rtP .
eee_Value ; xtmp [ 0 ] = accum ; accum = 0.0 ; accum += * ( As ++ ) * rtDW .
ppd4rroocm [ 0 ] ; accum += * ( As ++ ) * rtDW . ppd4rroocm [ 1 ] ; accum +=
* ( As ++ ) * rtDW . ppd4rroocm [ 2 ] ; accum += * ( As ++ ) * rtDW .
ppd4rroocm [ 3 ] ; accum += * ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 0 ]
) ; accum += * ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 1 ] ) ; accum += *
( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 2 ] ) ; accum += * ( Bs ++ ) * rtB
. fblwnhebsb ; accum += * ( Bs ++ ) * rtB . eoykqgypkt ; accum += * ( Bs ++ )
* rtP . eee_Value ; xtmp [ 1 ] = accum ; accum = 0.0 ; accum += * ( As ++ ) *
rtDW . ppd4rroocm [ 0 ] ; accum += * ( As ++ ) * rtDW . ppd4rroocm [ 1 ] ;
accum += * ( As ++ ) * rtDW . ppd4rroocm [ 2 ] ; accum += * ( As ++ ) * rtDW
. ppd4rroocm [ 3 ] ; accum += * ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 0
] ) ; accum += * ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 1 ] ) ; accum +=
* ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 2 ] ) ; accum += * ( Bs ++ ) *
rtB . fblwnhebsb ; accum += * ( Bs ++ ) * rtB . eoykqgypkt ; accum += * ( Bs
++ ) * rtP . eee_Value ; xtmp [ 2 ] = accum ; accum = 0.0 ; accum += * ( As
++ ) * rtDW . ppd4rroocm [ 0 ] ; accum += * ( As ++ ) * rtDW . ppd4rroocm [ 1
] ; accum += * ( As ++ ) * rtDW . ppd4rroocm [ 2 ] ; accum += * ( As ++ ) *
rtDW . ppd4rroocm [ 3 ] ; accum += * ( Bs ++ ) * ( rtP . SwitchCurrents_Value
[ 0 ] ) ; accum += * ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 1 ] ) ; accum
+= * ( Bs ++ ) * ( rtP . SwitchCurrents_Value [ 2 ] ) ; accum += * ( Bs ++ )
* rtB . fblwnhebsb ; accum += * ( Bs ++ ) * rtB . eoykqgypkt ; accum += * (
Bs ++ ) * rtP . eee_Value ; xtmp [ 3 ] = accum ; rtDW . ppd4rroocm [ 0 ] =
xtmp [ 0 ] ; rtDW . ppd4rroocm [ 1 ] = xtmp [ 1 ] ; rtDW . ppd4rroocm [ 2 ] =
xtmp [ 2 ] ; rtDW . ppd4rroocm [ 3 ] = xtmp [ 3 ] ; { int_T * gState = (
int_T * ) rtDW . egeoeejxx2 . G_STATE ; * ( gState ++ ) = ( int_T ) rtB .
ayriaun35r ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState ++ ) = ( int_T )
0.0 ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID5 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> odij3xombl = rtB .
nninjdfplf ; } void MdlProjection ( void ) { } void MdlZeroCrossings ( void )
{ ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ;
_rtZCSV -> dzm42p1kvw = rtB . m4snnhwc45 - rtP .
PIDController_UpperSaturationLimit ; _rtZCSV -> pqgfckdco2 = rtB . m4snnhwc45
- rtP . PIDController_LowerSaturationLimit ; _rtZCSV -> km3v55ivyx = rtB .
gispy1xujc - rtP . Constant_Value ; _rtZCSV -> icmemvdiuq = rtB . gispy1xujc
- rtB . hcm5iot1rh ; _rtZCSV -> gp4u5mcpqd = rtB . pihfv1mtox - rtP .
HitCrossing_Offset ; if ( rtDW . ixyl3zymd1 == 0 ) { _rtZCSV -> fnsmg4qlwu =
( ( rtB . pihfv1mtox - rtP . HitCrossing_Offset ) * ( real_T ) rtB .
k5qby3mrmb != 0.0 ) ; } else { _rtZCSV -> fnsmg4qlwu = ssGetT ( rtS ) -
ssGetTimeOfLastOutput ( rtS ) ; } } void MdlTerminate ( void ) { { free (
rtDW . egeoeejxx2 . AS ) ; free ( rtDW . egeoeejxx2 . BS ) ; free ( rtDW .
egeoeejxx2 . CS ) ; free ( rtDW . egeoeejxx2 . DS ) ; free ( rtDW .
egeoeejxx2 . DX_COL ) ; free ( rtDW . egeoeejxx2 . TMP2 ) ; free ( rtDW .
egeoeejxx2 . BD_COL ) ; free ( rtDW . egeoeejxx2 . TMP1 ) ; free ( rtDW .
egeoeejxx2 . XTMP ) ; free ( rtDW . egeoeejxx2 . G_STATE ) ; free ( rtDW .
egeoeejxx2 . SWITCH_STATUS ) ; free ( rtDW . egeoeejxx2 . SW_CHG ) ; free (
rtDW . egeoeejxx2 . SWITCH_STATUS_INIT ) ; } if ( rt_slioCatalogue ( ) != (
NULL ) ) { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 1 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
5 ) ; ssSetNumBlocks ( rtS , 122 ) ; ssSetNumBlockIO ( rtS , 28 ) ;
ssSetNumBlockParams ( rtS , 178 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 5.0E-6 ) ; ssSetSampleTime ( rtS , 3 , 2.0E-5 ) ;
ssSetSampleTime ( rtS , 4 , - 2.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2306984228U ) ;
ssSetChecksumVal ( rtS , 1 , 624229789U ) ; ssSetChecksumVal ( rtS , 2 ,
2859527761U ) ; ssSetChecksumVal ( rtS , 3 , 1610539028U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 19 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
mppt_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS , true )
; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 )
; ssSetModelName ( rtS , "mppt" ) ; ssSetPath ( rtS , "mppt" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 1.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 4 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 4 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"mppt/PID Controller/Integrator/Continuous/Integrator" ,
"mppt/PV Array/Diode Rsh/Unit Delay" ,
"mppt/powergui/EquivalentModel1/State-Space" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "DSTATE" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . odij3xombl ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . nceg4tx0wh ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . ppd4rroocm ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 1 ] ;
static real_T absTol [ 1 ] = { 1.0E-6 } ; static uint8_T absTolControl [ 1 ]
= { 0U } ; static real_T contStateJacPerturbBoundMinVec [ 1 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 1 ] ; static uint8_T zcAttributes [ 6 ] = {
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
0x80 | ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 1 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
nninjdfplf ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 1 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 5.0E-6
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 1 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 6 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 6 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . eh5sfnx2ar = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal
( rtS , 0 , 2306984228U ) ; ssSetChecksumVal ( rtS , 1 , 624229789U ) ;
ssSetChecksumVal ( rtS , 2 , 2859527761U ) ; ssSetChecksumVal ( rtS , 3 ,
1610539028U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 5 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID5 ( tid ) ; }
