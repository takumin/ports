# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	isl
PKGNAMESUFFIX=	-gcc
PORTVERSION=	0.12.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}infrastructure/

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Integer Set Library

LICENSE=	MIT

CONFLICTS=	isl-0.14*

USES=		libtool tar:lzma
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gmp-prefix=${LOCALBASE}
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's@pkgconfig_libdir=.*@pkgconfig_libdir=$${prefix}/libdata/pkgconfig@' ${WRKSRC}/configure

.include <bsd.port.mk>
