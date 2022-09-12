% PV Array Boost Converter
% 1. PV Array Specification at STCs
% At 1000W/m^2 & 25C
Pmp1=5040.0672
Vmp1=150.36
Imp1=33.52
f=50e3 % Switching freq
Vr=.02; % Volt Ripple Factor
Ir=.2; % Current Ripple Factor
% At 50W/m^2 & 25C
Pmp2=.05*Pmp1;
Vmp2=.9*Vmp1;
Imp2=Pmp2/Vmp2;
% 2. Internal Resistance of PV Array at MMP
Rmp1=Vmp1/Imp1;  % for 1000W/m^2
Rmp2=Vmp2/Imp2;  % for 50W/m^2
% 3. Load Resistance RL
RL=2.5*Rmp2
% 4. Value of D at MMP
Dmp1=1-sqrt(Rmp1/RL) % for 1000W/m^2
Dmp2=1-sqrt(Rmp2/RL) % for 50W/m^2
% 5. Value of Vo and Io
Vo1=Vmp1/(1-Dmp1) % for 1000W/m^2
Io1=Vo1/RL;        % for 1000W/m^2
Vo2=Vmp2/(1-Dmp2) % for 50W/m^2
Io2=Vo2/RL;        % for 50W/m^2
% 6. Value of Vr and Ir
Vrin=.01*Vmp1; % Input saide ripple volt value
Vrout=.01*Vo1; % Output saide ripple volt value
Irout=.2*Io2;
% 7. Reflected input resistance at input of PV Array;
Ri=RL*(1-(Dmp1)^2);
% Calculation of Cin , Co , L
Cin=4*Vmp1*Dmp1/(Vrin*Ri*f)
Co=2*Vo1*Dmp1/(Vrout*RL*f)
L=Vmp2*Dmp2/(2*Irout*f)

