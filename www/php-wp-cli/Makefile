# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	wp-cli
PORTVERSION=	0.23.1
CATEGORIES=	www
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.phar

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Command line interface for WordPress

LICENSE=	MIT

USE_GITHUB=	yes
GH_TAGNAME=	v${DISTVERSION}

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
