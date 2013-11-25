<CsoundSynthesizer>
<CsOptions>
	-odac -d 
</CsOptions>
<CsInstruments>

sr = 44100
ksmps = 128
nchnls = 2
0dbfs = 1

;1) Set the OSC port in Csound FIRST (ex. 6500)
;2) Use this same port in MaxMSP and initialize the connection
;  If this process is done in reverse (MaxMSP first), Csound will run
;  this instrument and it will say the selected port is already in use.

giport1 	OSCinit 8001
gisine 		ftgen 	0, 0, 4096, 10, 1
   
	instr 1

gkSource1   init 	0

					 	; port #   	|| 	OSC name    ||  data type	||	incoming data 	
kOSC1      	OSClisten 	giport1, 		"/Source1", 	"f", 			gkSource1

;gkSource1 = gkSource1/1024.0
gkSource1 portk gkSource1, 0.1

  ; Prints values of each light source.
;  printks "A = %f, B = %f, C = %f, D = %f\\n", .09, gkSource1, gkSource2, gkSource3, gkSource4
;printk2 gkSource1

    	endin
alwayson 2
instr 2
a1 oscili 0.5,  60 + (2000 * gkSource1), gisine
aout sum a1, a2, a3
outs aout, aout
endin

</CsInstruments>
<CsScore>
f 1 0 16384 10 1   
i 1 0 30000

</CsScore>
</CsoundSynthesizer>
