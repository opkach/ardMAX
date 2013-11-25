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
   
alwayson 2

	instr 1

gkSource1   init 	0

					 	; port #   	|| 	OSC name    ||  data type	||	incoming data 	
kOSC1      	OSClisten 	giport1, 		"/Source1", 	"f", 			gkSource1

gkSource1 	portk 		gkSource1, 0.1

  	; print source values coming from MaxMSP via OSC
  	; printks "source = %ld\\n", .09, gkSource1, gkSource2, gkSource3, gkSource4
	
	endin


	instr 2

a1 		oscili 	0.5,  60 + (2000 * gkSource1), gisine
aout 	sum 	a1, a2, a3
		outs 	aout, aout

endin

</CsInstruments>
<CsScore>

i 1 0 30000

</CsScore>
</CsoundSynthesizer>