# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	0.8.9
CATEGORIES=	net
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/a/apt-cacher-ng/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Caching package proxy server

LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES+=		cmake:outsource compiler:c++11-lang pathfix pkgconfig tar:xz
CMAKE_ARGS+=	-DBZIP2_NEED_PREFIX=/usr/include
USE_OPENSSL=	yes
USE_RC_SUBR=	apt-cacher-ng
LIB_DEPENDS+=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs

post-install:
	${MKDIR} ${STAGEDIR}/var/log/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng

	# pkg-plist for @sample %%ETCDIR%%/acng.conf.sample
	# pkg-plist for @sample %%ETCDIR%%/security.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/acng.conf ${STAGEDIR}${ETCDIR}/acng.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/security.conf ${STAGEDIR}${ETCDIR}/security.conf.sample

.include <bsd.port.mk>
