# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gcc49
PORTVERSION=	4.9.1.s20140604
CATEGORIES=	devel
MASTER_SITES=	GCC
MASTER_SITE_SUBDIR=	snapshots/${DISTVERSION}
PKGNAMEPREFIX=	mingw-w64-x86_64-
PKGNAMESUFFIX?=	-init
DISTNAME=	gcc-${DISTVERSION}
DISTVERSION=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.s([0-9]+)/\1-\2/}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GNU Compiler Collection 4.9 for MinGW-w64

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

MINGW64_TARGET?=x86_64-w64-mingw32

LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc
#BUILD_DEPENDS+=	${LOCALBASE}/bin/${MINGW64_TARGET}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
#RUN_DEPENDS+=	${LOCALBASE}/bin/${MINGW64_TARGET}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

USES=		gmake iconv perl5 tar:bzip2
USE_BINUTILS=	yes
USE_PERL5=	build
SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--target=${MINGW64_TARGET} \
		--enable-languages=c,c++ \
		--disable-nls \
		--disable-bootstrap \
		--with-mpc=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-gmp=${LOCALBASE} \
		--with-system-zlib

ALL_TARGET?=	all-gcc
INSTALL_TARGET?=install-gcc

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
