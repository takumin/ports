# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	bourbon
PORTVERSION=	4.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Bourbon is a library of pure Sass mixins

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sass>=3.4:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-thor>=0:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/bourbon

.include <bsd.port.mk>
