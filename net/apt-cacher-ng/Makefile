# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	0.8.5
CATEGORIES=	net
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/a/apt-cacher-ng/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Caching package proxy server

LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES+=		cmake compiler:c++11-lib fuse pkgconfig tar:xz
USE_GCC=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	apt-cacher-ng

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apt-cacher-ng ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/in.acng ${STAGEDIR}${PREFIX}/sbin
	${RM} ${WRKSRC}/conf/acng.conf.orig
	${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR})
	${INSTALL_MAN} ${WRKSRC}/doc/man/apt-cacher-ng.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}/var/log/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng

.include <bsd.port.mk>
