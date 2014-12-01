# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	wp-cli
PORTVERSION=	0.17.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/wp-cli/wp-cli/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.phar
EXTRACT_ONLY=

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	command line interface for WordPress

LICENSE=	MIT

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}/bin

.include <bsd.port.post.mk>
