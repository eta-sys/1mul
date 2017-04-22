This program ilustrates 'call' to a subroutine. Pic16F628A does not suppotr 'call's, so replace C with G 'goto' for him.  
Program uses strings, so if you don't have them repare last row leaving just '!V1'.

V1=0
J1
V2=10,V1=0,C+3				# set limit to 10, then call count subroutine
V2=20,V1=0,C+2				# set limit to 20, then call count subroutine
J1=0						# kill job 1
?V1<V2 !"V1=%adV1",HT{1,s},V1=V1+1,G+0:E;
