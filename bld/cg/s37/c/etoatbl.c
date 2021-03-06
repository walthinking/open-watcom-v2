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


/*
 * etoatbl -- EBCDIC to ASCII translation table;  EBCDIC characters with
 *            no 7-bit ASCII equivalent are mapped to 0xFF
 */

char const etoatbl[256] =
  {
              /* 0x-0, 0x-1, 0x-2, 0x-3, 0x-4, 0x-5, 0x-6, 0x-7, */
              /* 0x-8, 0x-9, 0x-A, 0x-B, 0x-C, 0x-D, 0x-E, 0x-F, */
    /* 0x00 */   0x00, 0x01, 0x02, 0x03, 0xFF, 0x09, 0xFF, 0x7F,
    /* 0x08 */   0xFF, 0xFF, 0xFF, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    /* 0x10 */   0x10, 0x11, 0x12, 0x13, 0xFF, 0xFF, 0x08, 0xFF,
    /* 0x18 */   0x18, 0x19, 0xFF, 0xFF, 0x1C, 0x1D, 0x1E, 0x1F,
    /* 0x20 */   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0A, 0x17, 0x1B,
    /* 0x28 */   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x06, 0x07,
    /* 0x30 */   0xFF, 0xFF, 0x16, 0xFF, 0xFF, 0xFF, 0xFF, 0x04,
    /* 0x38 */   0xFF, 0xFF, 0xFF, 0xFF, 0x14, 0x15, 0xFF, 0x1A,
    /* 0x40 */   0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0x48 */   0xFF, 0xFF, 0x5E, 0x2E, 0x3C, 0x28, 0x2B, 0x7C,
    /* 0x50 */   0x26, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0x58 */   0xFF, 0xFF, 0x21, 0x24, 0x2A, 0x29, 0x3B, 0x5E,
    /* 0x60 */   0x2D, 0x2F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0x68 */   0xFF, 0xFF, 0x7C, 0x2C, 0x25, 0x5F, 0x3E, 0x3F,
    /* 0x70 */   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0x78 */   0xFF, 0x60, 0x3A, 0x23, 0x40, 0x27, 0x3D, 0x22,
    /* 0x80 */   0xFF, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    /* 0x88 */   0x68, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0x90 */   0xFF, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,
    /* 0x98 */   0x71, 0x72, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0xA0 */   0xFF, 0x7E, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
    /* 0xA8 */   0x79, 0x7A, 0xFF, 0xFF, 0xFF, 0x5B, 0xFF, 0xFF,
    /* 0xB0 */   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0xB8 */   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5D, 0xFF, 0xFF,
    /* 0xC0 */   0x7B, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
    /* 0xC8 */   0x48, 0x49, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0xD0 */   0x7D, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
    /* 0xD8 */   0x51, 0x52, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0xE0 */   0x5C, 0xFF, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
    /* 0xE8 */   0x59, 0x5A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /* 0xF0 */   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
    /* 0xF8 */   0x38, 0x39, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
              /* 0x-0, 0x-1, 0x-2, 0x-3, 0x-4, 0x-5, 0x-6, 0x-7, */
              /* 0x-8, 0x-9, 0x-A, 0x-B, 0x-C, 0x-D, 0x-E, 0x-F, */
  };

