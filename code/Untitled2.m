% System parameters
Pn = 5000; % Inverter power active power
En = 230; %Grid voltage Line to Line voltage
Vdc= 900; %DC link voltage
fn = 50; %Grid frequency
wn = 2*pi*fn;
fsw = 50000; %Switching frequency
wsw = 2*pi*fsw;
% Base values
Zb = (En^2)/Pn
Cb = 1/(wn*Zb)
%Filter parameters
delta_Ilmax=0.1*((Pn*sqrt(2))/En);
Li=Vdc/(16*fsw*delta_Ilmax) %Inverter side inductance
x = 0.05;
Cf = x*Cb %Filter capacitor
%Calculation of the factor,r,between Linv and Lg
r = 0.6;
Lg = r*Li % Grid side inductance
wres = sqrt((Li+Lg)/(Li*Lg*Cf)) % Calculation of wres
fres=wres/(2*pi) %resonance frequency of the filter
Rd = 1/(3*wres*Cf) %Damping resistance
