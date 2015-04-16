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
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=		-I${LOCALBASE}/include --use-system-libuv
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --skip-build

.include <bsd.port.mk>
