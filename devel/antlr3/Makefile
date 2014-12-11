# Created by: Geoffrey Mainland <mainland@apeiron.net>
# $FreeBSD$

PORTNAME=	antlr3
PORTVERSION=	3.5.2
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr3.org/download/
DISTNAME=	antlr-${PORTVERSION}-complete
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition

USE_JAVA=	yes

NO_BUILD=	yes

SUB_FILES=	antlr.sh

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}/antlr3.jar
	${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${STAGEDIR}${PREFIX}/bin/antlr3

.include <bsd.port.mk>
