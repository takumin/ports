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

USES=		gmake makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--target=${PKGNAMEPREFIX:C/-$//g}
MAKE_ARGS+=	CC_FOR_TARGET=${PKGNAMEPREFIX}gcc-bootstrap \
		CXX_FOR_TARGET=${PKGNAMEPREFIX}g++-bootstrap \
		GCC_FOR_TARGET=${PKGNAMEPREFIX}gcc-bootstrap

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
