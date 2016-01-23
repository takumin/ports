# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	redis
PKGNAMEPREFIX=	php55-
PORTVERSION=	2.2.7
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

USE_GITHUB=	yes
GH_ACCOUNT=	phpredis
GH_PROJECT=	phpredis
GH_TAGNAME=	${PORTVERSION}

USE_PHP=	session
DEFAULT_VERSIONS=php=55
IGNORE_WITH_PHP=52 53 54 56 5
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	${PORTNAME}

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

IGBINARY_CONFIGURE_ENABLE=	redis-igbinary
IGBINARY_DEPENDS+=		re2c:${PORTSDIR}/devel/re2c
IGBINARY_USE=			php=igbinary

.include <bsd.port.mk>
