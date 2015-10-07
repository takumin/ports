# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	0.8.6
CATEGORIES=	net
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/a/apt-cacher-ng/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Caching package proxy server

LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES+=		cmake compiler:c++11-lib pathfix tar:xz
USE_OPENSSL=	yes
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lpthread -lssl -lcrypto
USE_RC_SUBR=	apt-cacher-ng

post-install:
	${RMDIR} ${STAGEDIR}${ETCDIR}/CMakeFiles
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/apt-cacher-ng/CMakeFiles
	${MKDIR} ${STAGEDIR}/var/log/apt-cacher-ng
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng

	# pkg-plist for @sample %%ETCDIR%%/acng.conf.sample
	# pkg-plist for @sample %%ETCDIR%%/security.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/acng.conf ${STAGEDIR}${ETCDIR}/acng.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/security.conf ${STAGEDIR}${ETCDIR}/security.conf.sample

.include <bsd.port.mk>
