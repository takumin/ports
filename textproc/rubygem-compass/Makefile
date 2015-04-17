# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	compass
PORTVERSION=	1.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Compass Stylesheet Authoring Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sass>=3.3.13:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-compass-core>=1.0.2:${PORTSDIR}/textproc/rubygem-compass-core \
		rubygem-compass-import-once>=1.0.5:${PORTSDIR}/textproc/rubygem-compass-import-once \
		rubygem-chunky_png>=1.2:${PORTSDIR}/graphics/rubygem-chunky_png \
		rubygem-rb-fsevent>=0.9.3:${PORTSDIR}/devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9:${PORTSDIR}/devel/rubygem-rb-inotify

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/compass

.include <bsd.port.mk>
