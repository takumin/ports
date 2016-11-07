# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	apt
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Advanced front-end for dpkg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	dpkg:archivers/dpkg

USES=		cmake:outsource tar:xz
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH=man \
		-DWITH_DOC=OFF \
		-DUSE_NLS=OFF

post-install:
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/de*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/es*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/fr*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/it*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/ja*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/nl*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/pl*
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/pt*

.include <bsd.port.mk>
