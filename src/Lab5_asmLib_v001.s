.include "xc.inc"
 
.global _M_wait_1ms
    
_M_wait_1ms:
    repeat #15994
    nop
    return
