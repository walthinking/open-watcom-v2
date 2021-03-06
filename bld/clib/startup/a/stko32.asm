;*****************************************************************************
;*
;*                            Open Watcom Project
;*
;*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
;*
;*  ========================================================================
;*
;*    This file contains Original Code and/or Modifications of Original
;*    Code as defined in and that are subject to the Sybase Open Watcom
;*    Public License version 1.0 (the 'License'). You may not use this file
;*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
;*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
;*    provided with the Original Code and Modifications, and is also
;*    available at www.sybase.com/developer/opensource.
;*
;*    The Original Code and all software distributed under the License are
;*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
;*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
;*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
;*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
;*    NON-INFRINGEMENT. Please see the License for the specific language
;*    governing rights and limitations under the License.
;*
;*  ========================================================================
;*
;* Description:  Stack checking for 32-bit OS/2.
;*
;*****************************************************************************


include mdef.inc
include struct.inc
include exitwmsg.inc

        modstart        stk

datasegment
ifdef __MT__
        extrn   "C",__GetThreadPtr : dword
else
        extrn   "C",_STACKLOW : dword
endif
msg     db      "Stack Overflow!", 0
enddata

include xinit.inc

        xinit   _init_stk,DEF_PRIORITY


        assume  ds:DGROUP

        xdefp   __STK
        xdefp   __CHK
        xdefp   __GRO
        xdefp   "C",__STKOVERFLOW


        defp    _init_stk
        ret                             ; return
        endproc _init_stk


        defpe   __CHK                   ; new style stack check
        xchg    eax,4[esp]              ; get parm in eax
        call    __STK                   ; call stack checker
        mov     eax,4[esp]              ; restore eax
        ret     4
        endproc __CHK


        defpe   __STK
        push    eax                     ; save parm for __GRO routine
        _guess                          ; guess: no overflow
          cmp   eax,esp                 ; - quit if user asking for too much
          _quif ae                      ; - ...
          sub   eax,esp                 ; - calculate new low point
          neg   eax                     ; - calc what new SP would be
ifdef __MT__
          push  esi                     ; - save registers
          push  eax                     ; - save eax
          call  __GetThreadPtr          ; - get thread data address
          mov   esi,eax                 ; - ...
          pop   eax                     ; - restore new ESP value
          cmp   eax,[esi]               ; - quit if too much
          pop   esi                     ; - restore registers
else
          cmp   eax,_STACKLOW           ; - quit if too much
endif
          _quif   be                    ; - ...
          call  __GRO                   ; - return
          ret
        _endguess                       ; endguess

__STKOVERFLOW:
        pop     eax                     ; pop the stack
ifdef __STACK__
        push    1                       ; exit code
        push    offset msg              ; the error message
else
        mov     eax,offset msg          ; the error message
        mov     edx,1                   ; exit code
endif
        jmp     __fatal_runtime_error   ; display msg and exit
        endproc __STK


        defpe   __GRO                   ; touch each 4K page for sparse stack
        push    eax                     ; save regs
        push    ebx                     ; ...
        mov     eax,12[esp]             ; get size to grow by
        mov     ebx,-4                  ; initialiaze index
lup:                                    ; do {
        mov     [esp+ebx],ebx           ; - touch that stack page
        sub     ebx,1000H               ; - decrement by 4k
        sub     eax,1000H               ; - decrement by 4k
        jg      lup                     ; } while stack left to go
        pop     ebx                     ; restore regs
        pop     eax                     ; ...
        ret     4                       ; return to caller
        endproc __GRO                   ;

        endmod
        end
