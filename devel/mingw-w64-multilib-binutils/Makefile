# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	mingw-w64-x86_64-

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GNU binary tools for MinGW-w64

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

CONFLICTS=	libbfd-[0-9]*

BUILD_DEPENDS+=	${LOCALBASE}/lib/libgmp.so:${PORTSDIR}/math/gmp \
		${LOCALBASE}/lib/libmpfr.so:${PORTSDIR}/math/mpfr

MINGW64_TARGET?=x86_64-w64-mingw32

USES=		bison tar:bzip2 gmake
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--target=${MINGW64_TARGET} \
			--with-sysroot=/ \
			--with-system-zlib \
			--disable-nls \
			--disable-werror \
			--with-gmp=${LOCALBASE} \
			--with-mpfr=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

post-install:
	${RM} -f ${STAGEDIR}${PREFIX}/info/*

.include <bsd.port.mk>
