/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#include "variety.h"
#include <jstring.h>

/**
*
*  Name:        jiskana         全角カタカナ・コード
*
*  Synopsis:    ret = jiskana( c );     (0x8340 <= c <= 0x8396
*                                          && c != 0x837f )
*
*               int ret;        条件に合っていれば０以外の値
*               JMOJI c;        漢字コード
*
*  Description: 与えられた漢字コードが条件に合っているかを調べる。
*               条件に合っている場合は０以外を返し、合わない場合は
*               ０を返す。
*
*  Name:        jiskana         Check 2-byte KANJI code of katakana
*
*  Synopsis:    ret = jiskana( c );     (0x8340 <= c <= 0x8396
*                                          && c != 0x837f )
*
*               int ret;        0 if fault, non-zero if true
*               JMOJI c;        KANJI code
*
*  Description: Check whether the givin character c is 2-byte KANJI code of
*               katakana. It returns non-zero if true, zero if fault.
*               The range of 2-byte KANJI code set is the below.
*               0x8340 <= c <= 0x8396 &&  c != 0x837f
*
**/

_WCRTLINK int jiskana( JMOJI c )        /* change from jiskata to jiskana, compatible to MS-C */
                        /* by M/M Mar/15/87 */
{
    return( c >= 0x8340 && c <= 0x8396 && c != 0x837f );
}
