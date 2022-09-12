#ifndef RTW_HEADER_mppt_types_h_
#define RTW_HEADER_mppt_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_GuZC7YYZUOK5mseIsYVPMB_
#define DEFINED_TYPEDEF_FOR_struct_GuZC7YYZUOK5mseIsYVPMB_
typedef struct { real_T time [ 3 ] ; real_T Out [ 3 ] ; real_T phase ; real_T
Period ; real_T Freq ; real_T Delay ; real_T TimeStepZ [ 2 ] ; }
struct_GuZC7YYZUOK5mseIsYVPMB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_JZ1eVVxGVSeatpw2GnpmYC_
#define DEFINED_TYPEDEF_FOR_struct_JZ1eVVxGVSeatpw2GnpmYC_
typedef struct { real_T SwitchResistance [ 3 ] ; real_T SwitchVf [ 6 ] ;
real_T SwitchType [ 3 ] ; real_T SwitchGateInitialValue [ 3 ] ; real_T
EnableUseOfTLC ; real_T OutputsToResetToZero [ 3 ] ; real_T
NoErrorOnMaxIteration ; real_T Ts ; real_T Interpolate ; real_T SaveMatrices
; real_T BufferSize ; boolean_T TBEON ; uint8_T sl_padding0 [ 7 ] ; real_T A
[ 16 ] ; real_T B [ 24 ] ; real_T C [ 36 ] ; real_T D [ 54 ] ; real_T x0 [ 4
] ; } struct_JZ1eVVxGVSeatpw2GnpmYC ;
#endif
#ifndef SS_INT64
#define SS_INT64  17
#endif
#ifndef SS_UINT64
#define SS_UINT64  18
#endif
typedef struct P_ P ;
#endif
