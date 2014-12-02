# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	middleman-sprockets
PORTVERSION=	3.3.10
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Sprockets support for Middleman

LICENSE=	MIT

RUN_DEPENDS=	rubygem-middleman-core>=3.3.7:${PORTSDIR}/www/rubygem-middleman-core \
		rubygem-sprockets>=2.12.1:${PORTSDIR}/devel/rubygem-sprockets \
		rubygem-sprockets-sass>=1.3.0:${PORTSDIR}/devel/rubygem-sprockets-sass \
		rubygem-sprockets-helpers>=1.1.0:${PORTSDIR}/devel/rubygem-sprockets-helpers

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

