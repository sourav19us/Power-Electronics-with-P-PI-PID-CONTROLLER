function D = Duty_cycle(V)
Dmax=.0.8307;
Dmim=.3675;
Dinit=.0.8307;
DelD=.0001;
persistent Vold Dold;
datatype='double';

if isempty(Vold)
    Vold = 250;
    Dold = Dinit;
end
dV=V-Vold;
if dv~=0; % dv is not equel to zero
  if dV<0;
     D=Dold-DelD;
  else
      D=Dold+DelD;
  end
else 
    D=Dold;
end
if D>=Dmax || D<Dmim
    D=Dold;
end
Dold=D;
Vold=V;