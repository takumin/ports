# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	3.2.2
CATEGORIES=	www
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Flexible project management web application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-rails4>=4.2.5.2:www/rubygem-rails4 \
		rubygem-jquery-rails>=3.1.4:www/rubygem-jquery-rails \
		rubygem-coderay>=1.1.0:textproc/rubygem-coderay \
		rubygem-builder>=3.0.4:devel/rubygem-builder \
		rubygem-request_store>=1.0.5:devel/rubygem-request_store \
		rubygem-mime-types>=3.0:misc/rubygem-mime-types \
		rubygem-protected_attributes>=0:devel/rubygem-protected_attributes \
		rubygem-actionpack-action_caching>=0:devel/rubygem-actionpack-action_caching \
		rubygem-actionpack-xml_parser>=0:textproc/rubygem-actionpack-xml_parser \
		rubygem-roadie-rails>=0:mail/rubygem-roadie-rails \
		rubygem-mimemagic>=0:misc/rubygem-mimemagic \
		rubygem-nokogiri>=1.6.7.2:textproc/rubygem-nokogiri \
		rubygem-rails-html-sanitizer>=1.0.3:textproc/rubygem-rails-html-sanitizer \
		rubygem-rbpdf>=1.19.0:print/rubygem-rbpdf

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USES=		cpe

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_NAME=${RUBY_NAME}

post-extract:
	@${RM} ${WRKSRC}/.gitignore ${WRKSRC}/.hgignore

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
