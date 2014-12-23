# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	mingw-w64
PKGNAMESUFFIX=	-header

COMMENT=	MinGW-w64 for header files

MASTERDIR=	${.CURDIR}/../mingw-w64

PLIST=		${.CURDIR}/pkg-plist

CONFIGURE_ARGS+=	--enable-sdk=all \
			--enable-secure-api \
			--without-crt

MINGW64_HEADER=	yes

.include "${MASTERDIR}/Makefile"
