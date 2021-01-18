
.CODE
; #include "GetHighAccuracyTime_x64.h"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; unsigned long long GetHighAccuracyTime_x64();
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
GetHighAccuracyTime_x64 PROC PUBLIC
; RDTSC instruction description:
; Reads the current value of the processor’s time-stamp counter (a 64-bit MSR) into the EDX:EAX registers. The EDX
; register is loaded with the high-order 32 bits of the MSR and the EAX register is loaded with the low-order 32 bits.
; (On processors that support the Intel 64 architecture, the high-order 32 bits of each of RAX and RDX are cleared.)
RDTSC   ; Get time in ns, [rdx : rax] -> [high : low];  Read time-stamp counter into EDX:EAX.
shl rdx, 32
or rax, rdx
ret
GetHighAccuracyTime_x64 ENDP


END