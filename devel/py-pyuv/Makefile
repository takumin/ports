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

PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --skip-build

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} build_py)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} build_ext -I${LOCALBASE}/include --use-system-libuv)

.include <bsd.port.mk>
