# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PKGNAMEPREFIX=	mingw-w64-x86_64-
MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GNU binary tools for Mingw-w64 x86_64

BUTARGET=	x86_64-w64-mingw32
CONFIGURE_ARGS+=--disable-multilib

MASTERDIR=	${.CURDIR}/../binutils
PLIST=		${.CURDIR}/pkg-plist
PLIST_SUB=	BUTARGET=${BUTARGET}

.include "${MASTERDIR}/Makefile"
