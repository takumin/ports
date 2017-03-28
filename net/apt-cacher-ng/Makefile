# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Caching package proxy server

LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES+=		cmake:outsource compiler:c++11-lang pkgconfig ssl tar:xz
CXXFLAGS+=	-std=c++11
CMAKE_ARGS+=	-Dopenssl_FOUND=on -Dopenssl_LDFLAGS="-lcrypto -lssl"
USE_RC_SUBR=	apt-cacher-ng

post-install:
	${MKDIR} ${STAGEDIR}/var/log/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng

	# pkg-plist for @sample %%ETCDIR%%/acng.conf.sample
	# pkg-plist for @sample %%ETCDIR%%/security.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/acng.conf ${STAGEDIR}${ETCDIR}/acng.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/security.conf ${STAGEDIR}${ETCDIR}/security.conf.sample

	# man
	${MV} ${STAGEDIR}${PREFIX}/share/man/man8/acngfs.8 ${STAGEDIR}${PREFIX}/man/man8/acngfs.8
	${MV} ${STAGEDIR}${PREFIX}/share/man/man8/apt-cacher-ng.8 ${STAGEDIR}${PREFIX}/man/man8/apt-cacher-ng.8
	${RMDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${RMDIR} ${STAGEDIR}${PREFIX}/share/man

.include <bsd.port.mk>
