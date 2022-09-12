%BOOST CONVERTER
Vin=100
Vout=230
D=1-(Vin/Vout)
f=50e3
Po=300
R=(Vout^2)/Po
dV=.01*Vout;
Io=Po/Vout;
dI=.2*Io*Vout/Vin;
L=Vin*D/(dI*f)
C=Io*D/(f*dV)