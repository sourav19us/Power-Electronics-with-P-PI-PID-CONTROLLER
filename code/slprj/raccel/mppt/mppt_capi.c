#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "mppt_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#ifndef SS_INT64
#define SS_INT64  17
#endif
#ifndef SS_UINT64
#define SS_UINT64  18
#endif
#else
#include "builtin_typeid_types.h"
#include "mppt.h"
#include "mppt_capi.h"
#include "mppt_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"mppt/Constant" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "mppt/Constant2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 2 , 0 , TARGET_STRING (
"mppt/Current Measurement/do not delete this gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"mppt/Current Measurement1/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Data Type Conversion" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 5 , 0 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3
} , { 6 , 0 , TARGET_STRING (
"mppt/Voltage Measurement/do not delete this gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"mppt/Voltage Measurement1/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/VT_ref_array" ) , TARGET_STRING ( "VT" ) , 0 , 0 , 0
, 0 , 0 } , { 9 , 0 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/Product" ) ,
TARGET_STRING ( "Idiode" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/Product4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 11 , 0 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/Unit Delay" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 13 , 0 , TARGET_STRING ( "mppt/PV Array/IL ctrl/1//Sref" ) ,
TARGET_STRING ( "S/Sref" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"mppt/PV Array/IL ctrl/Product1" ) , TARGET_STRING ( "IL" ) , 0 , 0 , 0 , 0 ,
0 } , { 15 , 0 , TARGET_STRING ( "mppt/PV Array/I_PV/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"mppt/PV Array/V_PV/do not delete this gain" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 1 , 0
, 2 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"mppt/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"mppt/PID Controller/Integrator/Continuous/Integrator" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 3 } , { 21 , 0 , TARGET_STRING (
"mppt/PID Controller/Parallel P Gain/Internal Parameters/Proportional Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"mppt/PID Controller/Saturation/Enabled/Saturation" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 23 , 0 , TARGET_STRING (
"mppt/PID Controller/Sum/Sum_PI/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 3 } , { 24 , 0 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 25 , 0 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 26 , 0 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/1\\ib2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 27 , 0 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 28 , TARGET_STRING ( "mppt/PID Controller" ) ,
TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"mppt/PID Controller" ) , TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 30 ,
TARGET_STRING ( "mppt/PID Controller" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"mppt/PID Controller" ) , TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 ,
0 } , { 32 , TARGET_STRING ( "mppt/PID Controller" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING (
"mppt/PV Array" ) , TARGET_STRING ( "Npar" ) , 0 , 0 , 0 } , { 34 ,
TARGET_STRING ( "mppt/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 35 , TARGET_STRING ( "mppt/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 36 , TARGET_STRING ( "mppt/Constant2" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 37 , TARGET_STRING ( "mppt/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"mppt/Current Measurement/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"mppt/Current Measurement1/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"mppt/Voltage Measurement/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"mppt/Voltage Measurement1/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING ( "mppt/Diode/Model/eee" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/Rsh_array" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 44 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/Rsh_array_5%Sref" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/Tref_K1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 46 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/Tref_K2" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/one" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
48 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/one1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/EgRef" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 50 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/I0_array" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/VT_ref_array" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 52 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/dEgdT" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/Unit Delay" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 54 , TARGET_STRING ( "mppt/PV Array/IL ctrl/0_K" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
"mppt/PV Array/IL ctrl/IL_module" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 56 , TARGET_STRING ( "mppt/PV Array/IL ctrl/Tref_K" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"mppt/PV Array/IL ctrl/1//Sref" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 58 , TARGET_STRING ( "mppt/PV Array/IL ctrl/alpha_Isc" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"mppt/PV Array/I_PV/do not delete this gain" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 60 , TARGET_STRING (
"mppt/PV Array/V_PV/do not delete this gain" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 61 , TARGET_STRING ( "mppt/PV Array/Vdiode/Rs_array_" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Compare To Zero/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "AS_param" )
, 0 , 3 , 0 } , { 64 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "BS_param" )
, 0 , 4 , 0 } , { 65 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "CS_param" )
, 0 , 5 , 0 } , { 66 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "DS_param" )
, 0 , 6 , 0 } , { 67 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "X0_param" )
, 0 , 7 , 0 } , { 68 , TARGET_STRING (
"mppt/PV Array/Diode Rsh/Subsystem/EgRef" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 69 , TARGET_STRING ( "mppt/PV Array/Diode Rsh/Subsystem/k1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/1\\ib2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"mppt/powergui/EquivalentModel1/Sources/SwitchCurrents" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 ,
0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . p0lbzyb3dc , & rtB . b3zwkh0dgw ,
& rtB . dirh3ywup1 , & rtB . aidbb0sgmz , & rtB . ayriaun35r , & rtB .
hcm5iot1rh , & rtB . lmf3u53ao5 , & rtB . evafcok2q3 , & rtB . johdxn5bii , &
rtB . fperphbavh , & rtB . epnatzrvj4 , & rtB . chdpbe0cay , & rtB .
eoykqgypkt , & rtB . ly5gnycfej , & rtB . fblwnhebsb , & rtB . f3yjek5puc , &
rtB . bc3skupnjv , & rtB . jopktmihot [ 0 ] , & rtB . n15cgb4yht [ 0 ] , &
rtB . nninjdfplf , & rtB . pzedvpmf2h , & rtB . jnk3ibzm4f , & rtB .
gispy1xujc , & rtB . m4snnhwc45 , & rtB . jadzw0spnk , & rtB . fjss0ng3xl , &
rtB . pihfv1mtox , & rtB . k5qby3mrmb , & rtP . PIDController_P , & rtP .
PIDController_I , & rtP . PIDController_InitialConditionForIntegrator , & rtP
. PIDController_UpperSaturationLimit , & rtP .
PIDController_LowerSaturationLimit , & rtP . PVArray_Npar , & rtP .
Constant_Value_c5r2ow4pnn , & rtP . Constant1_Value , & rtP .
Constant2_Value_j0j5kt5zqt , & rtP . Gain_Gain , & rtP .
donotdeletethisgain_Gain_fvxcttqcfp , & rtP .
donotdeletethisgain_Gain_amefm0x4hn , & rtP .
donotdeletethisgain_Gain_gnwiijihcw , & rtP .
donotdeletethisgain_Gain_geemqka3jr , & rtP . eee_Value , & rtP .
Rsh_array_Value , & rtP . Rsh_array_5Sref_Value , & rtP . Tref_K1_Value , &
rtP . Tref_K2_Value , & rtP . one_Value , & rtP . one1_Value , & rtP .
EgRef_Gain , & rtP . I0_array_Gain , & rtP . VT_ref_array_Gain , & rtP .
dEgdT_Gain , & rtP . UnitDelay_InitialCondition , & rtP . u_K_Value , & rtP .
IL_module_Value , & rtP . Tref_K_Value , & rtP . uSref_Gain , & rtP .
alpha_Isc_Gain , & rtP . donotdeletethisgain_Gain_hjp2jqttbc , & rtP .
donotdeletethisgain_Gain , & rtP . Rs_array_Value , & rtP . Constant_Value ,
& rtP . StateSpace_AS_param [ 0 ] , & rtP . StateSpace_BS_param [ 0 ] , & rtP
. StateSpace_CS_param [ 0 ] , & rtP . StateSpace_DS_param [ 0 ] , & rtP .
StateSpace_X0_param [ 0 ] , & rtP . EgRef_Value , & rtP . k1_Gain , & rtP .
Constant2_Value , & rtP . Constant4_Value , & rtP . uib2_Gain , & rtP .
HitCrossing_Offset , & rtP . SwitchCurrents_Value [ 0 ] , } ; static int32_T
* rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 9 , 1 , 3 , 1
, 4 , 4 , 4 , 6 , 9 , 4 , 9 , 6 , 4 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 5.0E-6 , 0.0 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 5 , 0 } , { ( const void * )
& rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 2
, 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 2 ] , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 28 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 47 , rtModelParameters , 0 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 2306984228U , 624229789U
, 2859527761U , 1610539028U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * mppt_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void mppt_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void mppt_host_InitializeDataMapInfo ( mppt_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
