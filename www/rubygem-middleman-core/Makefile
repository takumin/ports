# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	middleman-core
PORTVERSION=	3.3.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Middleman core library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=4.1.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-bundler>=1.1:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-erubis>=0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-hooks>=0.3:${PORTSDIR}/devel/rubygem-hooks \
		rubygem-uglifier>=2.5:${PORTSDIR}/www/rubygem-uglifier

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
