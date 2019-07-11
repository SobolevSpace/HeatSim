

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for others\ETL\ATL\include\atliface.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IRegistrarBase,0xe21f8a85,0xb05d,0x4243,0x81,0x83,0xc7,0xcb,0x40,0x55,0x88,0xf7);


MIDL_DEFINE_GUID(IID, IID_IRegistrar,0x44EC053B,0x400F,0x11D0,0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3);


MIDL_DEFINE_GUID(IID, IID_IDocHostUIHandlerDispatch,0x425B5AF0,0x65F1,0x11d1,0x96,0x11,0x00,0x00,0xF8,0x1E,0x0D,0x0D);


MIDL_DEFINE_GUID(IID, IID_IAxWinHostWindow,0xB6EA2050,0x048A,0x11d1,0x82,0xB9,0x00,0xC0,0x4F,0xB9,0x94,0x2E);


MIDL_DEFINE_GUID(IID, IID_IAxWinHostWindowLic,0x3935BDA8,0x4ED9,0x495c,0x86,0x50,0xE0,0x1F,0xC1,0xE3,0x8A,0x4B);


MIDL_DEFINE_GUID(IID, IID_IAxWinAmbientDispatch,0xB6EA2051,0x048A,0x11d1,0x82,0xB9,0x00,0xC0,0x4F,0xB9,0x94,0x2E);


MIDL_DEFINE_GUID(IID, IID_IAxWinAmbientDispatchEx,0xB2D0778B,0xAC99,0x4c58,0xA5,0xC8,0xE7,0x72,0x4E,0x53,0x16,0xB5);


MIDL_DEFINE_GUID(IID, IID_IInternalConnection,0x72AD0770,0x6A9F,0x11d1,0xBC,0xEC,0x00,0x60,0x08,0x8F,0x44,0x4E);


MIDL_DEFINE_GUID(IID, IID_IAccessibleProxy,0x7A7D9DCF,0xB7A1,0x4019,0x90,0x31,0x25,0x82,0x68,0x84,0x69,0x80);


MIDL_DEFINE_GUID(IID, IID_IAccessibleServer,0x52C8FB5E,0xD779,0x4e77,0xAE,0x9F,0xF6,0x11,0xFA,0x7E,0x9D,0x7A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



