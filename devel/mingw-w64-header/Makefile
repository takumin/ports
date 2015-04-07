# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	mingw-w64
PKGNAMESUFFIX=	-header

COMMENT=	MinGW-w64 for header files

WRKSRC_SUBDIR=	mingw-w64-headers
GNU_CONFIGURE_PREFIX=	${PREFIX}/x86_64-w64-mingw32

MINGW64_HEADER=	yes

MASTERDIR=	${.CURDIR}/../mingw-w64
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
