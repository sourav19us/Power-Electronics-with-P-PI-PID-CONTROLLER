% BUCK - BOOST CONVERTER
Vin=100
Vout=150
D=-Vout/(Vin-Vout)
f=25e3
Po=300
R=(Vout^2)/Po
Io=Po/Vout;
IL=Io/(1-D);
dI=.02*IL;
dV=.02*Vout;
L=Vin*D/(dI*f)
C=Io*D/(dV*f)
