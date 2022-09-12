#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_GuZC7YYZUOK5mseIsYVPMB" , 14 ,
96 } , { "struct_JZ1eVVxGVSeatpw2GnpmYC" , 15 , 1272 } , { "int64_T" , 16 , 8
} , { "int64_T" , 17 , 8 } , { "uint64_T" , 18 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_GuZC7YYZUOK5mseIsYVPMB ) , sizeof
( struct_JZ1eVVxGVSeatpw2GnpmYC ) , sizeof ( int64_T ) , sizeof ( int64_T ) ,
sizeof ( uint64_T ) } ; static const char_T * rtDataTypeNames [ ] = {
"real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_GuZC7YYZUOK5mseIsYVPMB" ,
"struct_JZ1eVVxGVSeatpw2GnpmYC" , "int64_T" , "int64_T" , "uint64_T" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
eoykqgypkt ) , 0 , 0 , 37 } , { ( char_T * ) ( & rtB . k5qby3mrmb ) , 8 , 0 ,
1 } , { ( char_T * ) ( & rtDW . nceg4tx0wh ) , 0 , 0 , 5 } , { ( char_T * ) (
& rtDW . egeoeejxx2 . AS ) , 11 , 0 , 6 } , { ( char_T * ) ( & rtDW .
oqpntcgch1 [ 0 ] ) , 10 , 0 , 13 } , { ( char_T * ) ( & rtDW . dbxce5ttyk ) ,
8 , 0 , 2 } } ; static DataTypeTransitionTable rtBTransTable = { 6U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . PIDController_I ) , 0 , 0 , 178 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
