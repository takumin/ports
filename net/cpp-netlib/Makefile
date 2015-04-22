# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	cpp-netlib
PORTVERSION=	0.11.1
CATEGORIES=	devel

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	C++ Network Library Project

LICENSE=	BSL

USE_GITHUB=	yes
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}-final

LIB_DEPENDS+=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libicui18n.so:${PORTSDIR}/devel/icu

USES=		cmake compiler:c++11-lib
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCPP-NETLIB_BUILD_SHARED_LIBS=ON \
		-DCPP-NETLIB_DISABLE_LIBCXX=ON

.include <bsd.port.mk>
