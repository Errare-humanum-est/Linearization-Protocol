

To run the model checking of the Linearization Protocol:
1) Install CMurphi
2) Set path to Murphi in Makefile
3) $ make
4) $ ./VIW -m 128000

The original protocol implementation in the publication is not safe if a TS overflow occurs.
Given a sufficiently larger interger a TS overflow should never happen during the runtime of a system,
however, if for any reason the TS can only be an interger with few bits, a overflow safe version of the protocol is provided as well. 
