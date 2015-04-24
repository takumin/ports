# Created by: Geoffrey Mainland <mainland@apeiron.net>
# $FreeBSD$

PORTNAME=	antlr34
PORTVERSION=	3.4
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr3.org/download/
DISTNAME=	antlr-${PORTVERSION}-complete
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition

LICENSE=	BSD

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
SUB_FILES=	antlr.sh
PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${DISTFILES}

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/${DISTFILES}
	${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
