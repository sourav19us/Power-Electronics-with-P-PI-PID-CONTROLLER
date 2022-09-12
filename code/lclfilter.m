% LCL Filater for 1 phase inerter
Vdc=900;
Vg=230;
fg=50;
p=4452.525;
fs=50;
dI=.2;
i=4.95;
dIp=i*.2*1.414;
c=.05*p/(Vg*Vg*2*pi*fg)
Li=Vdc/(4*fs*dIp)
Lg=(.1*Vg*Vg/(p*2*pi*fg))-Li
fr=(1/2*pi)*sqrt(-(Li-Lg)/Li*Lg*c)
Rd=1/(3*2*pi*fr*c)
