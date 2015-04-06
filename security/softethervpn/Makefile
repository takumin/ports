# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	softethervpn
PORTVERSION=	4.08.9449
CATEGORIES=	security net

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Cross-platform Multi-protocol VPN Program

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	SoftEtherVPN
GH_PROJECT=	SoftEtherVPN
GH_TAGNAME=	ea38eef

ONLY_FOR_ARCHS=	i386 amd64
USES=		gmake iconv readline ncurses
USE_OPENSSL=	yes
USE_RC_SUBR=	vpnserver vpnbridge vpnclient

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
MAKEFILE=	${WRKSRC}/src/makefiles/freebsd_32bit.mak
.endif
.if ${ARCH} == "amd64"
MAKEFILE=	${WRKSRC}/src/makefiles/freebsd_64bit.mak
.endif

ALL_TARGET=	build
MAKE_ARGS+=	INSTALL_BINDIR=${STAGEDIR}${PREFIX}/bin/
MAKE_ARGS+=	INSTALL_VPNSERVER_DIR=${STAGEDIR}${DATADIR}/vpnserver/
MAKE_ARGS+=	INSTALL_VPNBRIDGE_DIR=${STAGEDIR}${DATADIR}/vpnbridge/
MAKE_ARGS+=	INSTALL_VPNCLIENT_DIR=${STAGEDIR}${DATADIR}/vpnclient/
MAKE_ARGS+=	INSTALL_VPNCMD_DIR=${STAGEDIR}${DATADIR}/vpncmd/

post-install:
.for f in vpnserver vpnbridge vpnclient vpncmd
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/${f}
	@${ECHO_CMD} '${DATADIR}/${f}/${f} "$$@"' >> ${STAGEDIR}${PREFIX}/bin/${f}
	@${ECHO_CMD} 'exit $$?' >> ${STAGEDIR}${PREFIX}/bin/${f}
	@${STRIP_CMD} ${STAGEDIR}${DATADIR}/${f}/${f}
.endfor

.include <bsd.port.post.mk>
