A simple program to alternate blink 2 LEDs for 300mS.

O{12,13}
J1
O=1,HT{300 m},O=2,HT{300 m}
E


This is the program shown in Demo.avi.  
For small Pic processors use 'Send file line by line' option in 'MySerial' to give them time to write rows to Flash.
For processors with File System set use command W"main.ml" to upload example as execute ml.
