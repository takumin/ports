# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

CROSS_TARGET=	x86_64-w64-mingw32

PKGNAMEPREFIX=	mingw64-
PKGNAMESUFFIX=	-core

BUILD_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw64-binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw64-binutils

CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

MASTERDIR=	${.CURDIR}/../mingw-gcc

# echo '@comment Insert PLIST.lib here' > pkg-plist
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
