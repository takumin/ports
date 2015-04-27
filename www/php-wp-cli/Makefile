# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	wp-cli
PORTVERSION=	0.19.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/wp-cli/wp-cli/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.phar

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	command line interface for WordPress

LICENSE=	MIT

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	iconv openssl phar zlib

PLIST_FILES=	bin/wp

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/${DISTFILES} ${WRKSRC}/wp-cli.phar

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wp-cli.phar ${STAGEDIR}${PREFIX}/bin/wp

.include <bsd.port.post.mk>
