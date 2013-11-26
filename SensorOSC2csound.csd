<CsoundSynthesizer>
<CsOptions>
	-odac -d 
</CsOptions>
<CsInstruments>

sr = 44100
ksmps = 128
nchnls = 2
0dbfs = 1

; OSC port
giport1 	OSCinit 7000

; sine
gisine 		ftgen 	0, 0, 4096, 10, 1
   
alwayson 2

	instr 1

; initialize OSC source
gkSource1   init 	0

; setup OSC connection
					 	; port #   	|| 	OSC name    ||  data type	||	incoming data 	
kOSC1      	OSClisten 	giport1, 		"/osc1", 	"f", 			gkSource1

; smooth OSC data
gkSource1 	portk 		gkSource1, 0.1

; print out OSC data [make sure the data is flowing from MaxMSP/Arduino via OSC]
  	 printks "source = %f\\n", .09, gkSource1
	
	endin


	instr 2

a1 		oscili 	0.5,  60 + (2000 * gkSource1), gisine
aout 	sum 	a1
		outs 	aout, aout

endin

</CsInstruments>
<CsScore>

i 1 0 30000

</CsScore>
</CsoundSynthesizer>