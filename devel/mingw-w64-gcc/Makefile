# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PKGNAMEPREFIX=	mingw-w64-
MAINTAINER=	takumiiinn@gmail.com

BUILD_DEPENDS+=	${LOCALBASE}/bin/x86_64-w64-mingw32-as:${PORTSDIR}/devel/mingw-w64-binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/x86_64-w64-mingw32-as:${PORTSDIR}/devel/mingw-w64-binutils

CONFIGURE_ARGS+=--target=x86_64-w64-mingw32 \
		--program-prefix=x86_64-w64-mingw32-

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

MASTERDIR=	${.CURDIR}/../../lang/gcc49
.include "${MASTERDIR}/Makefile"
