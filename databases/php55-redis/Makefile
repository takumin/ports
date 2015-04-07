# Created by: Arjan Koole <arjan@blackoak.net>
# $FreeBSD: head/databases/php55-redis/Makefile 356472 2014-06-04 11:49:48Z miwi $

PORTNAME=	redis
PORTVERSION=	2.2.7
CATEGORIES=	databases
PKGNAMEPREFIX=	php55-

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

USE_GITHUB=	yes
GH_ACCOUNT=	phpredis
GH_PROJECT=	phpredis
GH_TAGNAME=	${PORTVERSION}

USE_PHP=	session
DEFAULT_VERSIONS=php=55
IGNORE_WITH_PHP=52 53 54 56 5
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	${PORTNAME}

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIGBINARY}
USE_PHP+=	igbinary
CONFIGURE_ARGS+=--enable-redis-igbinary
.else
CONFIGURE_ARGS+=--disable-redis-igbinary
.endif

.include <bsd.port.mk>
