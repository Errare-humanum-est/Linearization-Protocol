## Linearization protocol
[Scale-Out ccNUMA: Exploiting Skew with Strongly Consistent Caching](https://github.com/Errare-humanum-est/Linearization-Protocol/blob/f2713c8468218ba6cfbeab20e9e5d040634accac/eurosys18.pdf)

The full protocol specification can be found here: [Protocol Specification](https://github.com/Errare-humanum-est/Linearization-Protocol/blob/f2713c8468218ba6cfbeab20e9e5d040634accac/Linearization_Protocol.pdf)

To run the model checking of the Linearization Protocol:

*Install CMurphi*

*Set path to Murphi in Makefile*

```
make
```

```
./VIW -m 128000
```

The original protocol implementation in the publication is not safe if a TS overflow occurs.
Given a sufficiently larger interger a TS overflow should never happen during the runtime of a system,
however, if for any reason the TS can only be an interger with few bits, an overflow safe version of the protocol is provided as well. 
