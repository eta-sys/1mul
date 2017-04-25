An other blinker with control input.

    O=3,O{12,13},I{15}
    F1=1
    J1
    ?I1*F1 F1=0,O1=0,O2=1,T1{2 s}
    ?T1 T1=0,O1=1,O2=0,T2{2 s}
    ?T2 T2=0,O=3,F1=1
    E
    '0x1a'
    

See recommendations from Example1.
