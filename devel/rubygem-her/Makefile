# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	her
PORTVERSION=	0.6.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Her is an ORM that maps REST resources and collections to Ruby objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel>=3.0.0:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-multi_json>=1.7:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
