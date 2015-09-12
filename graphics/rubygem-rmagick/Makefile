# $FreeBSD: head/graphics/rubygem-rmagick/Makefile 394310 2015-08-15 12:10:20Z sunpoet $

PORTNAME=	rmagick
PORTVERSION=	2.15.4
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for ImageMagick

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		pkgconfig

LIB_DEPENDS+=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick

.include <bsd.port.mk>
