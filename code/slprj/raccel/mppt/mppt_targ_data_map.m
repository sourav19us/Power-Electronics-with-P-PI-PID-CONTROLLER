  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% rtP.PIDController_I
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.PIDController_InitialConditionForIntegrator
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.PIDController_LowerSaturationLimit
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.PVArray_Npar
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.PIDController_P
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.PIDController_UpperSaturationLimit
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Constant_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.UnitDelay_InitialCondition
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.StateSpace_AS_param
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.StateSpace_BS_param
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 24;
	
	  ;% rtP.StateSpace_CS_param
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 48;
	
	  ;% rtP.StateSpace_DS_param
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 84;
	
	  ;% rtP.StateSpace_X0_param
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 138;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 142;
	
	  ;% rtP.donotdeletethisgain_Gain_hjp2jqttbc
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 143;
	
	  ;% rtP.donotdeletethisgain_Gain_fvxcttqcfp
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 144;
	
	  ;% rtP.donotdeletethisgain_Gain_gnwiijihcw
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 145;
	
	  ;% rtP.Gain_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 146;
	
	  ;% rtP.Constant4_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 147;
	
	  ;% rtP.Constant2_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 148;
	
	  ;% rtP.uib2_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 149;
	
	  ;% rtP.donotdeletethisgain_Gain_amefm0x4hn
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 150;
	
	  ;% rtP.donotdeletethisgain_Gain_geemqka3jr
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 151;
	
	  ;% rtP.HitCrossing_Offset
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 152;
	
	  ;% rtP.SwitchCurrents_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 153;
	
	  ;% rtP.Constant_Value_c5r2ow4pnn
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 156;
	
	  ;% rtP.Constant2_Value_j0j5kt5zqt
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 157;
	
	  ;% rtP.u_K_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 158;
	
	  ;% rtP.uSref_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 159;
	
	  ;% rtP.Tref_K_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 160;
	
	  ;% rtP.alpha_Isc_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 161;
	
	  ;% rtP.IL_module_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 162;
	
	  ;% rtP.Rs_array_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 163;
	
	  ;% rtP.one1_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 164;
	
	  ;% rtP.Tref_K1_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 165;
	
	  ;% rtP.dEgdT_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 166;
	
	  ;% rtP.EgRef_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 167;
	
	  ;% rtP.Tref_K2_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 168;
	
	  ;% rtP.I0_array_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 169;
	
	  ;% rtP.EgRef_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 170;
	
	  ;% rtP.k1_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 171;
	
	  ;% rtP.Rsh_array_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 172;
	
	  ;% rtP.Rsh_array_5Sref_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 173;
	
	  ;% rtP.VT_ref_array_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 174;
	
	  ;% rtP.one_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 175;
	
	  ;% rtP.Constant1_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 176;
	
	  ;% rtP.eee_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 177;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% rtB.eoykqgypkt
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jopktmihot
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.n15cgb4yht
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% rtB.bc3skupnjv
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtB.f3yjek5puc
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtB.fperphbavh
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtB.chdpbe0cay
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% rtB.dirh3ywup1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% rtB.lmf3u53ao5
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% rtB.jnk3ibzm4f
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 19;
	
	  ;% rtB.pzedvpmf2h
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% rtB.m4snnhwc45
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 21;
	
	  ;% rtB.gispy1xujc
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% rtB.fjss0ng3xl
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% rtB.jadzw0spnk
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% rtB.pihfv1mtox
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% rtB.hcm5iot1rh
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% rtB.ayriaun35r
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
	  ;% rtB.aidbb0sgmz
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 28;
	
	  ;% rtB.evafcok2q3
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 29;
	
	  ;% rtB.nninjdfplf
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% rtB.p0lbzyb3dc
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% rtB.b3zwkh0dgw
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% rtB.ly5gnycfej
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 33;
	
	  ;% rtB.fblwnhebsb
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% rtB.epnatzrvj4
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 35;
	
	  ;% rtB.johdxn5bii
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.k5qby3mrmb
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.nceg4tx0wh
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ppd4rroocm
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.egeoeejxx2.AS
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.i3d4cnqyko.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.oqpntcgch1
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.kxzljsksxj
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 11;
	
	  ;% rtDW.ixyl3zymd1
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.dbxce5ttyk
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dd11cic03n
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2306984228;
  targMap.checksum1 = 624229789;
  targMap.checksum2 = 2859527761;
  targMap.checksum3 = 1610539028;

