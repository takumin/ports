# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	0.8.3
CATEGORIES=	net
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/a/apt-cacher-ng/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Caching package proxy server

LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES+=		cmake compiler:c++11-lib tar:xz
USE_OPENSSL=	yes
PLIST_FILES=	sbin/apt-cacher-ng \
		sbin/in.acng

OPTIONS_DEFINE=	BOOST FUSE
OPTIONS_DEFAULT=BOOST FUSE
BOOST_LIB_DEPENDS=libboost_thread.so:${PORTSDIR}/devel/boost-libs
FUSE_USES=	fuse

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apt-cacher-ng ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/in.acng ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
