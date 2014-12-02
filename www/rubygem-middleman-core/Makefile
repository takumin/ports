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
		rubygem-i18n>=0.6.9:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-listen>=2.7.9:${PORTSDIR}/devel/rubygem-listen \
		rubygem-padrino-helpers>=0.12.3:${PORTSDIR}/www/rubygem-padrino-helpers \
		rubygem-rack>=1.4.5:${PORTSDIR}/www/rubygem-rack \
		rubygem-rack-test>=0.6.2:${PORTSDIR}/www/rubygem-rack-test \
		rubygem-thor>=0.15.2:${PORTSDIR}/devel/rubygem-thor \
		rubygem-tilt1>=1.4.1:${PORTSDIR}/devel/rubygem-tilt1

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
