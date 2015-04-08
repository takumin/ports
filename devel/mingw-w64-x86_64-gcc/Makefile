# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

CROSS_TARGET=	x86_64-w64-mingw32

PKGNAMEPREFIX=	mingw64-

BUILD_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw64-binutils \
		${LOCALBASE}/${CROSS_TARGET}/lib/libmingw32.a:${PORTSDIR}/devel/mingw64-crt
RUN_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw64-binutils \
		${LOCALBASE}/${CROSS_TARGET}/lib/libmingw32.a:${PORTSDIR}/devel/mingw64-crt

CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}

CC=			${CROSS_TARGET}-gcc
CXX=			${CROSS_TARGET}-c++
CPP=			${CROSS_TARGET}-cpp
AR=			${CROSS_TARGET}-ar
RANLIB=			${CROSS_TARGET}-ranlib

MASTERDIR=	${.CURDIR}/../mingw-gcc

# echo '@comment Insert PLIST.lib here' > pkg-plist
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
