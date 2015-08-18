# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	middleman
PORTVERSION=	3.4.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Middleman is a static site generator

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-script>=2.2:${PORTSDIR}/devel/rubygem-coffee-script \
		rubygem-compass>=1.0.0:${PORTSDIR}/textproc/rubygem-compass \
		rubygem-compass-import-once>=1.0.5:${PORTSDIR}/textproc/rubygem-compass-import-once \
		rubygem-execjs>=2.0:${PORTSDIR}/devel/rubygem-execjs \
		rubygem-haml>=4.0.5:${PORTSDIR}/www/rubygem-haml \
		rubygem-kramdown>=1.2:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-middleman-core>=${PORTVERSION}:${PORTSDIR}/www/rubygem-middleman-core \
		rubygem-middleman-sprockets>=3.1.2:${PORTSDIR}/devel/rubygem-middleman-sprockets \
		rubygem-sass>=3.4.0:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-uglifier>=2.5:${PORTSDIR}/www/rubygem-uglifier

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
