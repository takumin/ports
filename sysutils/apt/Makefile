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
.for d in de es fr it ja nl pl pt
	${RM} -r ${STAGEDIR}${MANPREFIX}/man/${d}*
.endfor

.include <bsd.port.mk>
