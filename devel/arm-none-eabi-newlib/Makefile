# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	newlib
PORTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/newlib/ \
		SOURCEWARE/${PORTNAME}
PKGNAMEPREFIX=	arm-none-eabi-

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Cross Newlib C library for ${GCC_TARGET}

BUILD_DEPENDS+=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}gcc-bootstrap:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc-bootstrap

GCC_TARGET=	${PKGNAMEPREFIX:C/-$//g}

USES=		gmake makeinfo
HAS_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=${PREFIX}/${GCC_TARGET}
CONFIGURE_ARGS+=--target=${GCC_TARGET}

CC:=		${PKGNAMEPREFIX}gcc-bootstrap
CXX:=		${PKGNAMEPREFIX}g++-bootstrap
CPP:=		${PKGNAMEPREFIX}cpp-bootstrap
CFLAGS:=	${CFLAGS:C/-march=.*//}
SSP_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

.include <bsd.port.post.mk>
