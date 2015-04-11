# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	cloog
PORTVERSION=	0.18.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}infrastructure/

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Code generator in the polyhedral model

LICENSE=	LGPL21

CONFLICTS=	cloog-0.18*

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libisl.so:${PORTSDIR}/devel/isl-gcc

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	pkgconfig_libdir=${PREFIX}/libdata/pkgconfig/
CONFIGURE_ARGS+=--with-gmp-prefix=${LOCALBASE} --with-isl-prefix=${LOCALBASE}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
