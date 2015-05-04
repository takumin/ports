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

#CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES+=		cmake compiler:c++11-lib pkgconfig tar:xz
USE_GCC=	4.9+
USE_OPENSSL=	yes
LIB_DEPENDS+=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libdaemon.so:${PORTSDIR}/devel/libdaemon
PLIST_FILES=	sbin/apt-cacher-ng \
		sbin/in.acng

#post-patch:
#	@${SED} -i "" -e 's@^\(CHECK_CXX_COMPILER_FLAG.*COMPILER_SUPPORTS_GNU11.*\)$$@#\1@' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apt-cacher-ng ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/in.acng ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
