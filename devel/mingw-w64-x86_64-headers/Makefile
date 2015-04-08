# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PKGNAMESUFFIX=	-headers
COMMENT=	MinGW-w64 for header files

CROSS_HOST=	x86_64-w64-mingw32
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}

WRKSRC_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MASTERDIR=	${.CURDIR}/../mingw-w64
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
