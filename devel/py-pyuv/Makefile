# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	pyuv
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Python interface for libuv

LICENSE=	MIT

LIB_DEPENDS=	libuv.so:${PORTSDIR}/devel/libuv

USES=		python
USE_PYTHON=	autoplist distutils
CFLAGS+=	-I${LOCALBASE}/include
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=		--use-system-libuv

.include <bsd.port.mk>
