
.MODEL FLAT
.CODE
; #include "GetHighAccuracyTime_x86.h"


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; unsigned int GetHighAccuracyTime_x32(unsigned int* high);
; high -> esp + 4
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
GetHighAccuracyTime_x32 PROC PUBLIC
; RDTSC instruction description:
; Reads the current value of the processor’s time-stamp counter (a 64-bit MSR) into the EDX:EAX registers. The EDX
; register is loaded with the high-order 32 bits of the MSR and the EAX register is loaded with the low-order 32 bits.
; (On processors that support the Intel 64 architecture, the high-order 32 bits of each of RAX and RDX are cleared.)
; test al, al   ; Get time in ns, [rdx : rax] -> [high : low];  Read time-stamp counter into EDX:EAX.
; RDTSC  ; No this instruction
mov dword ptr [esp + 4], edx
ret
GetHighAccuracyTime_x32 ENDP



END