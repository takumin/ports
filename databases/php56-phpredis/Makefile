# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	phpredis
PKGNAMEPREFIX=	php56-
PORTVERSION=	2.2.5
CATEGORIES=	databases

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	PHP5-Extension for Redis

LICENSE=	PHP301

USE_GITHUB=	yes
GH_ACCOUNT=	nicolasff
GH_COMMIT=	8dac89e

USE_PHP=	session
PHP_DEFAULT=	5.6
IGNORE_WITH_PHP=52 53 54 55 5
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	redis

OPTIONS_DEFINE=	IGBINARY
OPTIONS_DEFAULT=IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIGBINARY}
USE_PHP+=	igbinary
CONFIGURE_ARGS+=--enable-redis-igbinary
.else
CONFIGURE_ARGS+=--disable-redis-igbinary
.endif

.include <bsd.port.mk>
